#include"sort.h"

void D_InsertSort(datatype R[],int n)
{    int i,j;
	for(i=2;i<=n;i++)
		if(R[i]<R[i-1])
		{
			R[0]=R[i];
			for(j=i-1;R[0]<R[j];j--)
				R[j+1]=R[0];
		}
}
void ShellSort(datatype R[],int n,int d[],int t)
{
	int i,j,k,h;
	for(k=0;k<t;k++)
	{
		h=d[k];
		for(i=h+1;i<=n;i++)
			if(R[i]<R[i-h])
			{
				R[0]=R[i];
				for(j=i-h;j>0&&R[0]<R[j];j=j-h)
					R[j+h]=R[j];
				R[j+h]=R[0];
			}
	}
}
void Bubble_Sort(datatype R[],int n)
{
	int i,j;
	int swap;
	for(i=1;i<=n-1;i++)
	{
		swap=0;
		for(j=1;j<=n-i;j++)
			if(R[j]>R[j+1])
			{
				R[0]=R[j+1];
				R[j+1]=R[j];
				R[j]=R[0];
				swap=1;
			}
		if(swap==0) break;
	}
}
void Select_Sort(datatype R[],int n)
{
int k,i,j;
for(i=1;i<n;i++)
	{
		k=1;
		for(j=i+1;j<=n;j++)
			if(R[j]<R[k])
				k=j;
		if(i!=k)
		{R[0]=R[k];
			R[k]=R[i];
			R[i]=R[0];
		
		}
	}

}
