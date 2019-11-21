#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
       int a;
	printf("输入要申请分配的内存空间：\n");
	scanf("%d",&a);
	int *ptr_arr;
	ptr_arr = (int *)malloc(sizeof(int) * a);
	printf("初始化值：%d\n",a);
	printf("地址：%p\n",ptr_arr);
	free(ptr_arr);
	printf("请输入要改变的内存变量：\n");
	scanf("%d",&a);
	ptr_arr = (int *)malloc(sizeof(int) * a);
	printf("内存的初始值：%d\n",a);
	printf("指针的地址：%p\n",ptr_arr);
	return 0;
}
