#include"test5.h"

void ShellSort(int a[],int n)
{
	int dk;
	int tmp;
	int i;
	int j;
	for(dk=n/2;dk>0;dk/=2)
	    for(i=dk;i<n;i++)
	    {
		tmp=a[i];
	     	for(j=i;j>=dk;j-=dk)
			if(tmp<a[j-dk])
				a[j]=a[j-dk];
			else break;
		a[j]=tmp;
	    }
}

