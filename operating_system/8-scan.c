#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, size, move;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int rq[n];
    printf("Enter request sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &rq[i]);

    printf("Initial head position: ");
    scanf("%d", &head);

    printf("Disk size: ");
    scanf("%d", &size);

    printf("Direction (1 = high, 0 = low): ");
    scanf("%d", &move);

    // sort
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (rq[i] > rq[j])
            {
                int t = rq[i];
                rq[i] = rq[j];
                rq[j] = t;
            }

    int total = 0;
    int index = 0;

    // find first element greater than head
    for (int i = 0; i < n; i++)
    {
        if (rq[i] > head)
        {
            index = i;
            break;
        }
    }

    if (move == 1)
    {
        // move right side
        for (int i = index; i < n; i++)
        {
            total += abs(rq[i] - head);
            head = rq[i];
        }
        // go to end boundary
        total += abs((size - 1) - head);
        head = size - 1;

        // move left side
        for (int i = index - 1; i >= 0; i--)
        {
            total += abs(rq[i] - head);
            head = rq[i];
        }
    }
    else
    {
        // move left side
        for (int i = index - 1; i >= 0; i--)
        {
            total += abs(rq[i] - head);
            head = rq[i];
        }
        // go to 0 boundary
        total += abs(head - 0);
        head = 0;

        // move right side
        for (int i = index; i < n; i++)
        {
            total += abs(rq[i] - head);
            head = rq[i];
        }
    }

    printf("Total head movement = %d\n", total);
    return 0;
}
