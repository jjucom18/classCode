#include"paixu.h"
#include<time.h>

int main(int argc, char **argv){
   srand((int)time(NULL));
   int n,i,s,t;int *p=(int*)malloc(sizeof(int));
   int *f=(int*)malloc(sizeof(int));
   for(i=0;i<10;i++){
      p[i]=random_1(1,20);f[i]=random_1(1,20);
   }
   displayArray1(p,10);
   /*D_insertsort1(f,n);
   displayArray1(f,10);
   Bubble_sort1(p,n);
   displayArray1(p,10);
   Select_sort1(p,n);
   displayArray1(p,20);
   Quick_sort1(p,s,t);
   displayArray1(p,10);
   Shellsort1(p,n,f,t);
   displayArray1(p,10);*/
}


/*int D_insertsort1(int *p,int n);
void Bubble_sort1(int *p,int n);
int   Select_sort1(int *p,int n);
int  Partition1(int *P,int low,int high);
void Quick_sort1(int *p,int s,int t);
void Shellsort1(int *p,int n,int *f,int t);
void displayArray1(int *p,int size);*/








