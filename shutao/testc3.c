#include <stdio.h>

#include <stdlib.h>

int main(int argc,char **argv)

{

	int x,i;
	printf("请输入想分配的内存空间：\n");

	scanf("%d",&x);

	int *ptr_arr;
	ptr_arr = (int *)malloc(sizeof(int) * x);

	printf("内存的初始值：%d\n",x);

	printf("指针的地址：%p\n",ptr_arr);

	free(ptr_arr);

	printf("请输入想改变的内存变量：\n");
	scanf("%d",&x);
	ptr_arr = (int *)malloc(sizeof(int) * x);

	printf("内存的初始值：%d\n",x);

	printf("指针的地址：%p",ptr_arr);
															return 0;
}
