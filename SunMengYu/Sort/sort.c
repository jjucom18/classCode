#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
void BubbleSort(int a[],int n)
{
	 int i,j,flag=1;
	 int temp;
	 for (i=1;i<n&&flag==1;i++){
		 flag=0;
		 for (j=0;j<n-1;j++){
			 if(a[j]>a[j+1]){
				 flag=1;
				 temp=a[j];
				 a[j]=a[j+1];
				 a[j+1]=temp;
			 }
		 }
	 }
}

void InsertSort(int a[],int n)
{
	int i,j;
	int temp;
	for(i=0;i<n-1;i++)
	{
		temp=a[i+1];
		j=i;
		while(j>-1&&temp<a[j]);
		{
			a[j+1]=a[j];
		j--;
	}
		a[j+1]=temp;
	}
}

int Partition(int a[], int low, int high) {
	int x = a[low];
	while (low < high) {
		while (low<high && a[high]>=x) high--;
		if (low < high) {
			a[low] = a[high];
			low++;
		}
		while (low<high && a[low]<=x) low++;
		if (low < high) {
			a[high] = a[low];
			high--;
		}
	}
	a[low] = x;
	return low;
}
int Partition2(int a[], int low, int high) {
	int i=low, j=high+1, x=a[low], t;
	while (i < j) {
		do i++; while (a[i] < x);
		do j++; while (a[j] > x);
		if (i < j) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[low] = a[j];
	a[j] = x;
	return j;
}
void QSort(int a[], int low, int high) {
	if (low < high) {
		int mid = Partition(a, low, high);
		//int mid = Partition2(a, low, high);
		QSort(a, low, mid-1);
		QSort(a, mid+1, high);
	}
}//
void HeapAjust(int a[], int s, int m) {
	int j = 2*s + 1;
	int x = a[s];
	while (j <= m) {
		if ((j+1<=m) && (a[j+1]>a[j])) j++;
		if (x >= a[j]) {
				break;
				 } else {
					 a[s] = a[j];
					 s = j;
					 j = 2*s + 1;
				 }
	}
	a[s] = x;
}
void HeapSort(int a[], int n) {
	for (int i=(n-2)/2; i>=0; i--)
		HeapAjust(a, i, n-1);
	for (int i=n-1; i>0; i--) {
		int t = a[0];
		a[0] = a[i];
		a[i] = t;
		HeapAjust(a, 0, i-1);
	}
}

