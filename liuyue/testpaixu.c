#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20;
void Select_Sort(int a[],int n){
	int i,j,k,m;
	for( i=0;i<n-1;i++){
		m=a[i];
		k=i;
		for( j=i+1;j<n;j++)
			if(a[j]<m)
			{
				m=a[j],k=j;
			}
			a[k]=a[i];
			a[i]=m;
		}		
}

void InsertSort(int a[],int n){
   int i,j,temp;
    for( i=1;i<n;i++){
	temp=a[i];
	j=j-1;
	while(j>=0&&temp<a[j])
	{
		a[j+1]=a[j];
		j--;
	}
	a[j+1]=temp;
} 	
} 
void Bubblel(int a[],int n)
{
	int i,j,t;
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++);
		{
			if(a[j+1]<a[j])
			{
				t=a[i];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
int Partition(int a[],int low,int high){
	int x=a[low];
	while(low<high){
		while(low<high && a[high]>=x) high--;
		if(low<high) {
			a[low]=a[high];
			low++;
		}
		while (low<high && a[low]<=x) low++;
			if (low<high) {
				a[high]=a[low];
				high--;
			}
	}
	a[low]=x;
	return low;
}
int Partition2(int a[],int low,int high){
	int i=low,j=high+1,x=a[low],t;
	while(i<j){
		do i++; while(a[i]<x);
		do j--; while(a[j]>x);
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[low]=a[j];
	a[j]=x;
	return j;
}
void QSort(int a[],int low, int high) {
	if(low<high) {
		int mid=Partition(a,low,high);
		//int mid=Partition2(a,low,high);
		QSort(a,low,mid-1);
		QSort(a,mid+1,high);
	}
}
void QuickSort(int a[],int n) {
	QSort(a,0,n-1);
}

