#ifndef Sort_h
#define Sort_h
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxSize 20
#define random_1(a, b) ((rand()%(b - a))+a)
#define random_2(a, b) ((rand()%(b - a + 1))+a)


typedef int DataType;
DataType r[MaxSize];

int *Random_Numble();
void D_inSort(DataType *R,int n);
void Bubble_Sort(DataType *R,int n);
void ShellSort(DataType *r,int n,int *d,int t);
void Select_Sort(DataType *r,int n);

#endif

