#ifndef Sort_h
#define Sort_h
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
#define random_1(a,b) ((rand()%(b-a))+a)
#define random_2(a,b) ((rand()%(b-a+1))+a)

int Random_Numble();
void Selet_Sort(int a[],int n);
void InsertSort(int a[],int n);
void Bubblel(int a[],int n);
void QuickSort(int a[],int n);

#endif
