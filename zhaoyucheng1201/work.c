#include"work.h"

void output(int *arr,int n)
{
	printf("%d\n",n);
	int i=0;
	for( i=0;i<n;i++)
	{
	printf("%d",*(arr+i));//arr[i]=*(arr+i)
	}
}
void del(int *arr,int *n,int x,int y)
{
	int i,j;
	for(i=j=0;i<*n;i++)
    if(arr[i]>y||arr[i]<x)
	arr[j++]=arr[i];//选择合适的筛选条件， 
	*n=j;
}