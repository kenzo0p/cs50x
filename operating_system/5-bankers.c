#include <stdio.h>

int main() {
    char pro[10]={'A','B','C','D','E','F','G','H','I','J'}, seq[10];
    int avlbl[10], resrc[10], max[10][10], alloc[10][10], need[10][10];
    int i,j, proc, res, count=0, temp[10], executed;
    printf("ENTER THE NO. OF PROCESS = ");
    scanf("%d",&proc);
    printf("ENTER THE NO. OF RESOURCE TYPES = ");
    scanf("%d",&res);
    for(i=0;i<proc;i++) temp[i]=0;
    printf("ENTER THE ALLOCATION MATRIX:\n");
    for(i=0;i<proc;i++){
        printf("FOR PROCESS %c: ",pro[i]);
        for(j=0;j<res;j++) scanf("%d",&alloc[i][j]);
    }
    printf("ENTER THE MAXIMUM MATRIX:\n");
    for(i=0;i<proc;i++){
        printf("FOR PROCESS %c: ",pro[i]);
        for(j=0;j<res;j++) scanf("%d",&max[i][j]);
    }
    for(i=0;i<proc;i++){
        for(j=0;j<res;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("ENTER TOTAL INSTANCES OF EACH RESOURCE: ");
    for(i=0;i<res;i++) scanf("%d",&resrc[i]);
    for(i=0;i<res;i++){
        avlbl[i]=resrc[i];
        for(j=0;j<proc;j++) avlbl[i]-=alloc[j][i];
    }
    while(count < proc){
        executed = 0;
        for(i=0;i<proc;i++){
            if(temp[i]==0){
                int flag = 0;
                for(j=0;j<res;j++){
                    if(avlbl[j]<need[i][j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    printf("Process %c executed\n",pro[i]);
                    for(j=0;j<res;j++) avlbl[j]+=alloc[i][j];
                    temp[i]=1;
                    seq[count++] = pro[i];
                    executed = 1;
                }
            }
        }
        if(executed==0){
            printf("System is NOT in safe state\n");
            return 0;
        }
    }
    printf("System is in SAFE state\nSafe sequence: ");
    for(i=0;i<proc;i++) printf("%c ", seq[i]);
    return 0;
}
