#ifndef sort_h
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define MAXSIZE 20
 void D_InsertSort(datatype R[],int n)
{
	for(i=2;i<=n;i++)
		for(R[i].key<R[i-1].key)
		{ R[0]=R[i];
			for(j=i-1;R[0].key<R[j].key;j--)
			    R[j+1]=R[j]; 
			R[j+1]=R[0];	
		}
}

void Bubble_Sort(datatype R[],int n)
{int i ,j;
  int swap;
 	for(i=1;j<=n-1;i++)
	{swap=0;
	for(j=1;j<=n;j++)
		if(R[j].key<R[j+1].key)
		{R[0]=R[j+1];
			R[j+1]=R[j];
			R[j]=R[0];
			swap=1;  
		}
	if(swap==0)break;
	}
}

void Quick_Sort(datatype R[],int s,int t)
{
	if(s<t)
	{i=Partition(R,s,t);
		Quick_Sort(R,s,i-1);
		Quick_Sort(R,i+1,t);	
	}
}



void Select_Sort(datatype R[],int n)
{
	for(i=1;i<n;i++)
	{k=1;
		for(j=i+1;j<=n;j++)
			if(R[j].key<R[k].key)
				k=j;
		if(i!=k)
		{R[0]=R[k];
		R[k]=R[i];
		R[i]=R[0];
		}
	}
	}
#endif
