#ifndef sort_h
#define sort_h

#include<stdio.h>
#include<stdlib.h>

#define MAXNUM 20
typedef int datatype;

datatype R[MAXNUM];

int Random_Numble();
void D_Insertsort(datatype R[],int n);
void Shellsort(datatype R[],int n,int d[],int t);
void Bubble_sort(datatype R[],int n);
void Quick_sort(datatype R[],int s,int t);
int Partition(datatype R[],int low,int high);  

#endif
