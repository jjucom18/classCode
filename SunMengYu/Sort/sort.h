#ifndef sort_h
#define sort_h
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20

#define random_1(a,b) ((rand()%(b-a))+a)
#define eandom_2(a,b) ((rand()%(b-a+1))+a)


int Rondom_Numble();
void Bubble_Sort(int a[],int n);
void Insert_Sort(int a[],int n);
void Partition(int a[], int low, int high);
void HeapAjust(int a[], int s, int m);

#endif
