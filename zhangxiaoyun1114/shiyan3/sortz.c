#include<sortz.h>

void BubbleSort(int a[],int n)//冒泡排序
{ 
	int i,j,y;
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j=1];
				a[j+1]=t;
			}
		}
	}
}
void InsertSort(int a[],int n)//插入排序
{
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=a[i];
		j=i-1;
		while(j>0&&a[j>temp]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
void SelectSort(int a[],int n)//简单选择排序
{
	int i,j,k,m;
	for(i=0;i<n-1;i++){
		m=a[i];
		k=i;
		for(j=i+1;j<n;j++)
			if(a[j]<m){
				m=a[j];
				k=j;
			}
		a[k]=a[i];
		a[i]=m;
	}
}
void ShellSort(int a[],int n)//希尔排序
{
	int i,j,elem;
	int k=n/2;
	while(k>=1){
		for(i=k;i<n;i++){
			elem=a[i];
			for(j=i;j>=k;j-=k){
				if(elem<a[j-k]){
					a[j]=a[j-k];
				}
				else {break;}
			}
			a[j]=elem;
		}
		k=k/2;
	}
}
