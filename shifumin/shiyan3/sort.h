#ifndef sort_h
#define sort_h
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define random_1(a,b) ((rand()%(b-a))+a)
#define random_2(a,b) ((rand()%(b-a+1))+a)

#define MAXSIZE 20

void D_InsertSort(int R[],int n);
void Bubble_Sort(int R[],int n);
void Select_Sort(int R[],int n);
void Quick_Sort(int R[],int s,int t);

#endif


