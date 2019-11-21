#ifndef Sorting_h
#define Sorting_h
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define random_1(a,b)  ((rand()%(b - a)) + a)
#define random_2(a,b)  ((rand()%(b - a + 1)) + a)
#define MaxNum 25

typedef int Datatype;
typedef struct {
	int data;
}datatype;

datatype R[MaxNum];


void D_InsertSort(datatype R[],int n);
void ShellSort(datatype R[],int n,int D[],int t);
void Bubble_Sort(datatype R[],int n);
void Select_Sort(datatype R[],int n); 

#endif