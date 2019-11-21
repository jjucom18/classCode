#include"sort.h"
void InsertSort1(int arr[],int n ){
	int i,j;
	for(i=2;i<n;i++){

		if(arr[i]<arr[i-1]){
			arr[0]=arr[i];
			for(j=i-1;arr[0]<arr[j];j--)
				arr[j+1]=arr[j]; 
			arr[j+1]=arr[0];
			} 
	}
		
}//直接插入排序

void BubbleSort1(int arr[],int n){
int i,j;int swap;
for(i=1;i<n-1;i++)
{swap=0;
for(j=1;j<=n-i;j++)
if(arr[j]>arr[j+1])
{arr[0]=arr[j+1];
arr[j+1]=arr[j];
arr[j]=arr[0];
swap=1;
}
if(swap==0)break;}
}//冒泡排序

void ShellSort1(int arr[],int n,int d[],int t){
   int i,j,k,h;
   for(k=0;k<t;k++)
   {
	h=d[k] ;
	for(i=h+1;i<=n;i++)
	if(arr[i]<arr[i-h])	
	{
	arr[0]=arr[i];
	for(j=i-h;j>0&&arr[0]<arr[j];j=j-h)
		arr[j+h]=arr[j];
	    arr[j+h]=arr[0];
	}
   }
}//希尔排序

	

void SelectSort1(int arr[],int n){
	int i,j,k;
	for(i=1;i<n;i++){
		k=i;
		for(j=i+1;j<=n;j++)
		if(arr[j]<arr[k])
		k=j;
		if(i!=k){
	arr[0]=arr[k];
	arr[k]=arr[i];
	arr[i]=arr[0];
		}
		
	}
}//简单选择排序
