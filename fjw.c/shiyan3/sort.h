#ifndef sort_h
#define sort_h
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define random_1(a,b) ((rand()%(b-a))+a)
#define random_2(a,b) ((rand()%(b-a+1))+a)
#define MaxSize 20
typedef int DataType1;

typedef struct{
	int key;
}datatype a[MaxSize];

void InsertSort(DataType a[],int n);
void BubbleSort(DataType a[],int n);
void QuickSort(DataType a[],int low,int high);
void SelectSort(DataType a[],int n);
int display(DataType a[],int n);
#define

