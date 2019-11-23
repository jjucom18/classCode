#include "test6.h"

void SelectSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int k=i;
		for(int j=i+1;j<n;j++)
			if(a[j]<a[k])
				k=j;
		if(k!=i)
		{
			int t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
	}
}
