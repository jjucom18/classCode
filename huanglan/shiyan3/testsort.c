#include"sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define randim_1(a,b)((rand()%(b - a))+ a)
#define random_2(a,b)((rand()%(b - a + 1)) + a)
#define M 20
int main(int arge,char **argv)
{
	srand((int)time(NULL));
	int R[10],i,n;
	for(int i = 0; i< 10;i++){
		R[i]= random_1(1,20);
	}
	for(int i= 0;i<10;i++){
		printf("%d\t",R[i]);
	}
	return 0;
	int m = 0;
	R[m] = D_inSort(R[i],n);
	Bubble_Sort(R,n);
	Select_Sort(R,n);
	QuickSort(R,n);

}
