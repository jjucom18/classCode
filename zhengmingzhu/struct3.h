#ifndef Sort_h
#define Sort_h
#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#define N 20

int n;
int R[N];
void InsertionSort(int  R[],int n);
void Bubble_Sort(int  R[],int n);	
void Select_Sort(int R[],int n);
void HeapAjust(int R[],int s,int n);	
#endif
