#ifndef paixu_h
#define paixu_h
#include<stdlib.h>
#include<stdio.h>
#define random_1(a,b) ((rand()%(b-a))+a)
#define random_2(a,b) ((rand()%(b-a+1))+a)
int *p=(int*)malloc(sizeof(int));
for(i=0;i<10;i++){
      p[i]=random_1(1,20);f[i]=random_1(1,20);
   }
int  D_insertsort1(int *p, int n);
int Bubble_sort1(int *p,int n);
int   Select_sort1(int *p,int n);
int  Partition1(int *p,int low,int high);
int  Quick_sort1(int *p,int s,int t);
int  Shellsort1(int *p,int n,int *f,int t);
int  displayArray1(int *p,int size);


#endif 
