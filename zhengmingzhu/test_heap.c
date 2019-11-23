#include "heap.c" 
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#define N 20
int main(int argc,char **argv)
{    int R[N],i;
     srand(time(0));
     for(i=0;i<N;i++)
	R[i] = rand() % 100;
     for(i=0;i<N;i++){
     printf("%d\t",R[i]);}
     printf("\n");
        HeapAjust(R,N);
  printf("After:");
  for(i=0;i<N;i++)
	  printf("%d\t",R[i]);
}
