#include<stdio.h>
#include<stdlib.h>
int *f1(int n,int *arr)
{
	int *ptr_arr=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		ptr_arr[i]=arr[i];
	}
	printf("初始值和地址：\n");
	for(int j=0;j<n;j++)
	{
		printf("ptr_arr[%d]=%d  ",j,ptr_arr[j]);
		printf("ptr_arr[%d]=%p\n",j,&ptr_arr[j]);
	}
	return ptr_arr;
}
int *f2(int m)
{
	int *ptr_arr=(int *)malloc(sizeof(int)*m);
	printf("请输入初始值：\n");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&ptr_arr[i]);
	}
	return ptr_arr;
}
int main()
{
	int a;
	int *ptr_arr1,*ptr_arr2;
	printf("请输入内存大小：");
	scanf("%d",&a);
	ptr_arr2=f2(a);
	ptr_arr1=f1(a,ptr_arr2);



	return 0;
}

