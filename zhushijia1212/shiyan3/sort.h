#ifndef sort_h
#define sort_h

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MaxSize 23

void InsertSort(int list[],int n);
void bubbleSort(int list[],int n);
void Selectsort(int list[],int n);
int partition(int list[],int low,int high);
void QuickSort(int list[],int s,int t);





#endif
