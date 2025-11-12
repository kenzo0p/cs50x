#include <stdio.h>

int main()
{
    int n, r, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resources: ");
    scanf("%d",&r);

    int alloc[n][r], max[n][r], avail[r];

    printf("Enter Allocation Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Available Resources:\n");
    for(i=0;i<r;i++)
        scanf("%d",&avail[i]);

    int f[n], ans[n], ind = 0;

    for(i=0;i<n;i++)
        f[i] = 0;

    int need[n][r];
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(k=0;k<n;k++)
    {
        int executed = 0;
        for(i=0;i<n;i++)
        {
            if(f[i] == 0)
            {
                int flag = 0;
                for(j=0;j<r;j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0)
                {
                    ans[ind++] = i;
                    for(j=0;j<r;j++)
                        avail[j] += alloc[i][j];
                    f[i] = 1;
                    executed = 1;
                }
            }
        }

        if(executed == 0) // nothing executed this cycle → UNSAFE
        {
            printf("\nSystem NOT in safe state (Deadlock Possible)\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state.\nSAFE Sequence: ");
    for(i=0; i<n; i++)
    {
        printf("P%d", ans[i]);
        if(i != n-1)
            printf(" -> ");
    }
    printf("\n");

    return 0;
} 


/*
    Enter number of processes: 3
Enter number of resources: 3

Enter Allocation Matrix:
0 1 0
2 0 0
3 0 2

Enter Max Matrix:
7 5 3
3 2 2
9 0 5

Enter Available Resources:
3 3 2

total -> 8,4 ,4

*/