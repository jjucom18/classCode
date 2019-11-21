#include "Bubble.c"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main(){
int a[N],i;
srand(time(0));
for(i=0;i<N;i++)
        a[i]=rand()%100;
for(i=0;i<N;i++)
        printf(" %d",a[i]);
printf("\n");
BubbleSort(a,N);
printf("排序后的数据：");
for(i=0;i<N;i++) printf("%d\t",a[i]);
}

