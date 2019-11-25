#include<stdlib.h>
#include<stdio.h>
#include"sort.h"

void D_Insertsort(datatype R[],int n){
	for(i=2;i<=n;i++)
		if(R[]<R[i-1])
		{
			R[0]=R[i];
			for(j=i-1;R[0]<R[j];j--)
				R[j+1]=R[j];
			R[j+1]=R[0];
		}
	return R[];
} 

void Shellsort(datatype R[],int n,int d[],int t){
	int i,j,k,h;
	for(k=0;k<t;k++){
		h=d[k];
		for(i=h+1;i<=n;i++)
			if(R[i]<r[i-h])
			{
				R[0]=R[i];
				for(j=i-h;j>0&&R[0]<R[j];j=j-h)
					R[j+h]=R[j];
				R[j+h]=R[0];
			}
	}
}

void Bubble_sort(datatype R[],int n){
	int i,j;
	int swap;
	for(i=1;i<n-1;i++){
		swap=0;
		for(j=1;j<=n-i;j++)
			if(R[j]>R[j+1]){
				R[0]=R[j+1];
				R[j+1]=R[j];
				R[j]=R[0];
				swap=1;
			}
if(swap==0)break;
	}
}

void Quick_sort(datatype R[],int s,int t){
	if(s<t){
		i=Partition(R,s,t)
			Quick_sort(R,s,i-1);
		Quick_sort(R,i+1,t);
	}

}

int Partition(datatype R[],int low,int high){
	R[0]=R[low];
	while(low<high){
		while(low<high&&R[high]>=R[0])
			high--;
		if(low<high)
			R[low]=R[high];low++;
		}while(low<high&&R[low]<R[0])
	low++;
		if(low<high){
			R[high]=R[low];high--;
}
 R[low]=R[0];} 
 return low;
}
