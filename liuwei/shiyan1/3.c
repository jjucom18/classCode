#include<stdio.h>
#include<stdlib.h>

int *g(int n)
{
	int *ptr_arr=(int *)malloc(sizeof(int)*n);
	for (int i=0;i<n;i++)
	{
		ptr_arr[i]=i+1;
	}
	printf("初始化的值和地址为：、\n");
	for(int i=0;i<n;i++)
	{
		printf("ptr_arr[%d]=%d\t",i,ptr_arr[i]);
		printf("&ptr_arr[%d]=%p\n",i,&ptr_arr[i]);
	}
	return ptr_arr;
}



int main(int argc,char **argv)
{
	int n;
	int ptr_arr;
	scanf("%d",&n);
	ptr_arr=g(n);
	return 0;
}
