#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void sort(int a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j] > a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
}
int main(){
    int n,choice;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("\n1.Normal Execution\n2.Orphan Process\n3.Zombie Process\nEnter choice: ");
    scanf("%d",&choice);
    pid_t pid=fork();
    if(choice==1){
        if(pid==0){
            printf("Child doing sorting...\n");
            sort(arr,n);
            printf("Sorted: ");
            for(int i=0;i<n;i++) printf("%d ",arr[i]);
            printf("\n");
        } else {
            wait(NULL);
            printf("Parent finished after child.\n");
        }
    }
    else if(choice==2){ // orphan
        if(pid==0){
            sleep(5);
            printf("Orphan Child PID:%d New Parent:%d\n",getpid(),getppid());
        } else {
            printf("Parent exiting immediately...\n");
            exit(0);
        }
    }
    else if(choice==3){ // zombie
        if(pid==0){
            printf("Child finished, becoming zombie...\n");
            exit(0);
        } else {
            printf("Parent sleeping, child becomes zombie.\n");
            sleep(10);
            printf("Parent exiting now.\n");
        }
    }
    return 0;
}
