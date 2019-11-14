#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	int N,T;
	printf("请输入内存大小:\n");
	scanf("%d",&N);
	int *ptr_arr;
	ptr_arr = (int *)malloc(sizeof(int) * N);
	printf("初始化的值和地址:%d,%p\n",N,ptr_arr);
	T=N;
	free(ptr_arr);
	printf("请输入想改变的内存变量：\n");
	scanf("%d",&N);
	ptr_arr = (int *)malloc(sizeof(int) * N);
	printf("改变后内存的值和地址:%d,%p\n",N+T,ptr_arr);		
	return 0;
}
