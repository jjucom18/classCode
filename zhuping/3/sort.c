#include"sort.h"
void insertSort(int R[],int n)//直接插入排序
{int i,j;
	for(i=2,i<=n;i++;) 
	if(R[i]<R[i-1])
	{R[0]=R[i];
	 for(j=i-1;R[0]<R[j];j--)	
       R[j+1]=R[j];
	 R[j+1]=R[0];
	}} 
void Bubble_Sort(int R[],int n)//冒泡排序
{int i,j;
	int swap;
	for(i=1,i<n-1;i++;){
		swap=0;
	    for(j=1;j<=n-1;i++)
		if(R[j]>R[j+1])
		{R[0]=R[j+1];
		 R[j+1]=R[j];
		 R[j]=R[0];
		 swap=1;}
if(swap==0) break;}}  
void Select_Sort(int R[],int n)//希尔排序
{int i,j,k;
	for(i=1;i<n;i++)
	{k=i;
		for(j=i+1;j<=n;j++);
			if(R[j]<R[k])
				k=j;
		if(i!=k)
		{R[0]=R[k];
		 R[k]=R[i];
		 R[i]=R[0];}
}}

