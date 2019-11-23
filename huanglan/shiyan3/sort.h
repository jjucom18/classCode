#ifndef sort_h
#define sort_h
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
typedef int datatype; 
datatype R[MAXNUM];

int Random_Numble();
void D_inSort(datatype *r,int n);
void Bubble_Sort(datatype *r,int n);
void Quick_Sort(datatype *r,int n,int *d,int t);
void Select_Sort(datatype *r,int n);


#endif
