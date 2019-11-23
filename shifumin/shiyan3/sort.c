#include"sort.h"

void D_InsertSort(int R[],int n)
{   int i,j;
	for(i=2;i<=n;i++)
		if(R[i]<R[i-1])
		{R[0]=R[i];
		for(j=i-1;R[0]<R[j];j--)
			R[j+1]=R[j];
		R[j+1]=R[0];
		}
	return;
} //直接插入排序

void Bubble_Sort(int R[],int n)
{
	int i,j;
	int swap;
	for(i=1;i<=n-1;i++)
	{swap=0;
	for(j=1;j<=n-i;j++)
		if(R[j]>R[j+1])
		{R[0]=R[j+1];
		R[j+1]=R[j];
		R[j]=R[0];
		swap=1;
		}
    if(swap==0)break;
	}
	return;
}//冒泡排序

void Select_Sort(int R[],int n)
{   int k,j,i;
	for(i=1;i<n;i++)
	{k=i;
     for(j=i+1;j<=n;j++)
		 if(R[j]<R[k])
			 k=j;
	 if(i!=k)
	 {R[0]=R[k];
      R[k]=R[i];
	  R[i]=R[0];

	 }
	}
	return;
}//简单选择排序

void ShellSort(int R[],int n)
{
	int d=n/2;//设置希尔排序增量
	int i,j,temp;
	while(d>=1)
	{
		for(i=d;i<n;i++)
		{
			temp=R[i];
			j=i-d;
			while(j>=0&&R[j]>temp)
			{
				R[j+d]=R[j];
				j=j-d;
			}
			R[j+d]=temp;
		}
	}
	return;
}//希尔排序
