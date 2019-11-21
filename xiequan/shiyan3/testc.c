#include"paixu.h"
#include<time.h>

#define random_1(a,b) ((rand()%(b-a))+a)
#define random_2(a,b) ((rand()%(b-a+1))+a)

int main(int argc, char **argv){
   srand((int)time(NULL));
   int *p=(int*)malloc(10 * sizeof(int));
   int *f=(int*)malloc(10 * sizeof(int));
   int n,i,s,t;
   for(int i= 0;i<10;i++){
	   p[i]=random_1(1,20);
       f[i]=random_1(1,20);
   }
   D_insertsort1(p,n);
   displayArray1(p,10);
   Bubble_sort1(p,n);
   displayArray1(p,10);
   Select_sort1(p,n);
   displayArray1(p,20);
   Quick_sort1(p,s,t);
   displayArray1(p,10);
   Shellsort1(p,n,f,t);
   displayArray1(p,10);
}






/* void D_insertsort(int R[],int n)；
void Bubble_sort(int R[],int n);
void Select_sort(int R[],int n);
void Partition(int R[],int low,int high);
void Quick_sort(int R[],int s,int t);
void Shellsort(int R[],int n,int d[],int t);*/



