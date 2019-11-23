#ifndef sort_h
#define sort_h
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
typedef int datatype; 
int *R;
datatype r[20];

int *Random_Numble();
void D_inSort(datatype *R,int n);
void Bubble_Sort(datatype *R,int n);
void Select_Sort(datatype *R,int n);
void QSort(datatype *R);

#endif
