#ifndef sort_h
#define sort_h

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 21
typedef struct _datatype{
	int data;
}datatype;

void InsertSort(datatype list[],int n);
void bubbleSort(datatype list[],int n);
void SelectSort(datatype list[],int n);

int Partition(datatype list[],int low, int high);
void QuickSort(datatype list[],int s,int t);


#endif