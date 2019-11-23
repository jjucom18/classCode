#include "SelectSort.c"
int main(int argc,char **argv){
int R[N],i;
srand(time(0));
for(i=0;i<N;i++)
        R[i]=rand()%100;
for(i=0;i<N;i++)
        printf("%d\t",R[i]);
printf("\n");
SelectSort(R,N);
printf("排序后的数据:");
for(i=0;i<N;i++)  printf("%d\t",R[i]);
     }

