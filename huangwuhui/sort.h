#ifndef sort_h
#define sort_h
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20;
#define random_1(a,b) ((rand()%(b-a))+a)
#define random_2(a,b) ((rand()%(b-a+1))+a)
typedef int datatype;

    int Numble();
    void D_InsertSort(datatype R[],int n)
	void ShellSort(datatype R[],int n,int d[],int t)
	void Bubble_Sort(datatype R[],int n)
	void Select_Sort(datatype R[],int n)


#endif	
