#include "sort.h"
typedef int datatype;
void D_InsertSort(datatype R[],int n) //直接插入排序
{
	int  i,j,temp;
for(i=2;i<=n;i++){
	temp = R[i];
	j =i - 1;
	while (j>=0 && R[j]>temp){
		R[j+1]=R[j];
		j--;
	}
R[j+1] =temp;
  }
}
void Bubble_Sort(int R[], int n){
   int i,j,t;
	for(i=0;i<n-1;i++){
		for (j=n-1;j>i;j--){
			if (R[j-1]>R[j]){
				t = R[j-1];
				R[j-1] = R[j];
				R[j] =t;
			}
		}
	}
} 
void Select_Sort(datatype R[],int n)//jian dan xuan ze
{ int i,j,k,m;
for(i=0;i<n-1;i++)
{   m = R[i];
	k = i;
	for(j=i+1;j<=n;j++)
		if(R[j]<m){
			m=R[j];k=j;
		}
	R[k]=R[i];
	R[i]=m;
	} 
  }

int Partition1(int R[],int low,int high ){
	int x =R[low];
	while (low < high){
		while(low<high && R[high]>=x)  high--;
		if (low < high){
			R[low] = R[high];
			low++;
		}
		while (low<high && R[low]<=x)  low++;
		if (low < high){
			R[high] =R[low];
			high--;
		}
	}
	R[low] = x;
	return low;
}

int Partition2(int R[],int low,int high ){
 int i=low, j=high=1,x=R[low],t;
 while (i<j){
	 do i++;while (R[i] < x); 
	 do j--;while (R[j] > x);
     if (i < j){
		  t=R[i];
		  R[i] = R[j];
		  R[j] = t;
	 }
 }
R[low] = R[j];
R[j] = x;
return j;
} 

void QSort(int R[],int low,int high){
	if (low < high){
		int mid = Partition2(R,low,high);
		QSort(R,low,mid-1);
		QSort(R,mid+1,high);
	}
}
void QuickSort(int R[],int n){
	QSort(R,0,n-1);
}
