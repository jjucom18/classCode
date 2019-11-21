#ifndef test3-1_h
#define test3-1_h
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define MAXE 20
#define MAXR 20
#define MAXD 8
typedef struct node
{char data[MAXD];
	struct node *next;
}EngType;

int arr[6];
void E_InsertSort(int arr1[6],int n);
void Selec_Sort(int arr2[6],int n);
void Bubble_Sort(int arr3[6],int n);
void Quick_Sort(int arr4[6],int i,int j);


#endif
