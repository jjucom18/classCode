#ifndef sort_h
#define sort_h

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define random_1(a,b)((rand()%(b-a))+a)
#define random_2(a,b)((rand()%(b-a+1))+a)
#define MAXSIZE 21


void InsertSort1(int arr[],int n);
void BubbleSort1(int arr[],int n);
void Shel1Sort1(int arr[],int n);
void SelectSort1(int arr[],int n);



#endif

