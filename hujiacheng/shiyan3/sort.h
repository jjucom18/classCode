#ifndef sort_h
#define sort_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define random_1(a,b) ((rand()%(b - a)) + a )
#define random_2(a,b) ((rand()%(b - a+1)) + a)		
#define MaxSize 20
typedef int datatype1;
typedef struct{
	int key;
}datatype;
datatype R[MaxSize];

void D_InsertSort(datatype R[],int n);
void Bubble_Sort(datatype R[],int n);
void Quick_Sort(datatype R[],int s,int n);
void Select_Sort(datatype R[],int n);
void ShellSort(datatype R[],int n,int d[],int t);
int    display(datatype R[],int n);
	

#endif
