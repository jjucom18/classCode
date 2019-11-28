#include<stdio.h>
#include<stdlib.h>
#include<Sort.h>

void InsertSort(int a[], int n)
{int i, j;
	DataType temp;
	for (i=;i<n-1;i++){
		temp = a[i+1];
		j = i;
		while (j>=-1 && temp.key<a[j].key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}

void BubbleSort(DataType a[], int n)
{
	int i,j,flag=1;
	DataType temp;
	for (i=1;i<n && flag==1;i++){
		flag=0;
		for (j=0;j<n-1;j++){
			if (a[j.key]>a[j+1].key){
				flag = 1;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void SelectSort(DataType a[], int n )
{
	int i,j,small;
	DataType temp;
	for (i=0;i<n-1;i++){
		small = i;
		for (j=i+1;j<n;j++)
			if (a[j].key<a[small].key)
				small = j;
		if (small!=i){
			temp = a[i];
			a[i] = a[small];
			a[small] = temp;
		}
	}
}

void QuickSort(DataType a[],int low,int high)
{
	int i=low,j=high;
	DataType temp = a[low];
	while (i<j){
		while (i<j&&temp.key<=a[j].key)
			j--;
		if (i<j){
			a[i] = a[j];
			i++;
		}
		while (i<j&&a[i].key<temp.key)
			i++;
		if (i<j){
			a[j] = a[i];
			j--;
		}
	}
	a[i] = temp;
	if (low<i)QuickSort(a,low,i-1);
	if (i<high)QuickSort(a,j+1,high);
}

void ShellSort(DataType a[], int n,int d[],int numOfD)
{
	int i,j,k,m,span;
	DataType temp;
	for (m=0;m<numOfD;m++){
		span = d[m];
		for (k=0;k<span;k++){
			for (i=k;i<n-span;i=i+span){
				temp = a[i+span];
				j = i;
				while(j>-1&&temp.key<=a[j].key){
					a[j+span] = a[j];
					j = j-span;
				}
				a[j+span] = temp;
			}
		}
	}
}
