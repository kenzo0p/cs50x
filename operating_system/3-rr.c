#include <stdio.h>
int main() {
    int n, qt;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], rt[n], ft[n], wt[n], tat[n];
    printf("Enter arrival time and burst time:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter time quantum: ");
    scanf("%d", &qt);
    int time = 0, done = 0;
    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (rt[i] <= qt) {
                    time += rt[i];
                    rt[i] = 0;
                    ft[i] = time;
                    done++;
                } else {
                    rt[i] -= qt;
                    time += qt;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("\nAT\tBT\tFT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", at[i], bt[i], ft[i], wt[i], tat[i]);
    }
    float total_wt=0, total_tat=0;
    for(int i=0;i<n;i++){
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("\nAverage WT = %.2f\n", total_wt/n);
    printf("Average TAT = %.2f\n", total_tat/n);

    return 0;
}
