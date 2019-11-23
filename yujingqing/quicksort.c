#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
#define random_1(a,b) ((rand()%(b-a)+a)
#define random_2(a,b) ((rand()%(b-a+1))+a)

int partition (int a[],int low,int high) {
	int x=a [low];
	while (low<high) {
		while (low<high && a[high]>=x) high--;
		if (low <high){
	            a[low]=a[high];
		    low++;
		}
		while (low<high && a[low]<=x) low++;
		if(low <high){
			a[high]=a[low];
			high--;
		}
	}

int partition2(int a[],int low,int high){
	int i=low,j=high+1,x=a[low],t;
	while(i<j) {
		do i++;while(a[i]<x);
		do j--;while(a[j]>x);
		if(i<j){
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
}
               a[low] =a[j];
               a[j]=x;
               return j;
	       }


void QSort(int a[],int low,int high){
	if(low<high) {
		int mid= partition(a,low,high);
		QSort(a,low,mid-1);
		QSort(a,mid-1,high);
	}
}	



void QuickSort(int a[],int n){
	QSort(a,0,n-1);
}

	int main(int argc, char **argv) {
	    
	   { int a[N],i;
	      srand(time(0));
	      for(i=0;i<N;i++)
              a[i]=rand()% 100;
             printf("初始数据为：");
             for(i=0;i<N;i++)
             printf( "%d",a[i]);
            printf("\n");
            QuickSort(a,N);
	    //MergeSort2(a,N);
           printf ("排序后数据：");
            for(i=0;i<N;i++)
            printf("%d",a[i]);}


	   {srand((int)time(NULL));
           int arr[10];
	  for(int i=0;i<10;i++){
		 arr[i]=random_1(1,20)}
	 for(int i=0;i<10;i++){
		printf("%d\t",arr[i]);
	 }
 return 0;}


	}	   
