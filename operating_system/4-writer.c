#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>   // for sleep()
sem_t x, y;
pthread_t readerthreads[100], writerthreads[100];
int readercount = 0;
void *reader(void *param)
{
    sem_wait(&x);
    readercount++;
    if (readercount == 1)
        sem_wait(&y); // first reader blocks writers
    sem_post(&x);
    printf("\nReader entered. Current readers = %d", readercount);
    sleep(1); // simulate reading
    sem_wait(&x);
    readercount--;
    if (readercount == 0)
        sem_post(&y); // last reader releases writers
    sem_post(&x);
    printf("\nReader leaving. Current readers = %d", readercount);
    return NULL;
}
void *writer(void *param)
{
    printf("\nWriter is trying to enter");
    sem_wait(&y);
    printf("\nWriter has entered");
    sleep(1); // simulate writing
    printf("\nWriter is leaving");
    sem_post(&y);

    return NULL;
}
int main()
{
    int nReaders, nWriters, i;
    printf("Enter the number of readers: ");
    scanf("%d", &nReaders);
    printf("Enter the number of writers: ");
    scanf("%d", &nWriters);

    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);

    for (i = 0; i < nReaders; i++)
        pthread_create(&readerthreads[i], NULL, reader, NULL);

    for (i = 0; i < nWriters; i++)
        pthread_create(&writerthreads[i], NULL, writer, NULL);

    for (i = 0; i < nReaders; i++)
        pthread_join(readerthreads[i], NULL);

    for (i = 0; i < nWriters; i++)
        pthread_join(writerthreads[i], NULL);

    sem_destroy(&x);
    sem_destroy(&y);

    return 0;
}