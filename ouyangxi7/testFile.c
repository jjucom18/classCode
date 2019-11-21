#include "File.c"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main(int argc,char **argv){
int a[N],i;
srand(time(0));
for(i=0;i<N;i++)    a[i]=rand()%100;
for(i=0;i<N;i++)  printf(" %d",a[i]);
printf("\n");
InsertSort(a,N);
BubbleSort(a,N);
SelectSort(a,N);
QuickSort(a,N);
Menu(a,N);
}
