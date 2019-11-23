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
//DataType *R;

int *Random_Numble();
void D_inSort(DataType *R);
void Bubble_Sort(DataType *R);
void ShellSort(DataType *R);
void Select_Sort(DataType *R);

#endif

