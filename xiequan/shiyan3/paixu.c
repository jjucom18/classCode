#include"paixu.h"



int D_insertsort1(int R[],int n){int i,j;
	for(i=2;i<=n;i++)
if(R[i]<R[i-1]){
	R[0]=R[i];
	for(j=i-1;R[0]<R[j];j++)
		R[j+1]=R[j];
	R[j+1]=R[0];
}
}



void Bubble_sort1(int R[],int n){
	int i,j;
	int swap;
	for(i=1;i<n-i;i++){
		swap=0;for(j=1;j<=n;j++)
			if(R[j]>R[j+1]){
				R[0]=R[j+1];
				R[j+1]=R[j];
				R[j]=R[0];
				swap=1;
			}
		if(swap==0)break;
	}
}



int Select_sort1(int R[],int n){int i,j,k;
for(i=1;i<n;i++){
	k=i;for(j=i+1;j<=n;j++)
		if(R[j]<R[k])
			k=j;
	if(i!=k){
		R[0]=R[k];
		R[k]=R[i];
		R[i]=R[0];
	}
}
}
		


int  Partition1(int R[],int low,int high)
{
	R[0]=R[low];
	while(low<high){
		while(low<high&&R[high]>=R[0])
			low++;
		if(low<high){
			R[high]=R[low];high--;
		}
	}
	R[low]=R[0];
	return low;
}



void Shellsort1(int R[],int n,int d[],int t){
	int i,j,k,h;
	for(k=0;k<t;k++)
	{
		h=d[k];
		for(i=h+1;i<=n;i++)
			if(R[i]<R[i-h]){
				R[0]=R[i];
				for(j=i-h;j>0&&R[0]<R[j];j=j-h)
					R[j+h]=R[j];
				    R[j+h]=R[0];
			}
	}
}








void Quick_sort1(int R[],int s,int t){
	if(s<t){int i;
		i=Partition1(R,s,t);
			Quick_sort1(R,s,i-1);
			Quick_sort1(R,i+1,t);
	}
}



void displayArray1(int *p,int size){
	for(int i=0;i<size;i++){
		printf("%d\t",p[i]);
	}return;
}
