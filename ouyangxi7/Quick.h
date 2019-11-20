#ifndef QuickSort_h
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20

int a[N],n,low,high;

int Partition1(int a[],int low,int high);
void QSort(int a[],int low,int high);
void QuickSort(int a[],int n);

#endif
