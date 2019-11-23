#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "sort.h"

#define N 20

#define random_1(a,b) ((rand()%(b-a))+a)
#define random_2(a,b) ((rand()%(b-a+1))+a)

void main(int argc,char **argv){
	srand((int)time(NULL));
	int R[N],i,t;
	int d[N],s;
	for(int i=0;i<N;i++){
		R[i]=random_1(1,20);}

	int n = 0;
	R[N] = D_Insertsort(R[i],n);

Shellsort(R,N,d,t);

Bubble_sort(R,N);

Quick_sort(R,s,t);
}
