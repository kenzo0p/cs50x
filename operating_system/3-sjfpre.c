#include <stdio.h>
#include <limits.h>
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ft[n], wt[n], tat[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }
    int t=0, done=0;
    while(done<n){
        int min=INT_MAX, idx=-1;
        for(int i=0;i<n;i++){
            if(at[i]<=t && rt[i]>0 && rt[i]<min){
                min=rt[i];
                idx=i;
            }
        }
        if(idx==-1){ t++; continue; }
        rt[idx]--;
        t++;
        if(rt[idx]==0){
            ft[idx]=t;
            tat[idx]=ft[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
            done++;
        }
    }
    float total_wt=0, total_tat=0;
    for(int i=0;i<n;i++){
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("\nAT\tBT\tFT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",at[i],bt[i],ft[i],wt[i],tat[i]);
    }
    printf("\nAverage WT = %.2f\n", total_wt/n);
    printf("Average TAT = %.2f\n", total_tat/n);
    return 0;
}
