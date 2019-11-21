#ifndef reporte3_h
#define reporte3_h

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 20


void InsertSort(int arr[],int n);
void bubbleSort(int arr[],int n);
void SelectSort(int arr[],int n);
int Partition(int arr[],int low, int high);
void QuickSort(int arr[],int s,int t);

#endif