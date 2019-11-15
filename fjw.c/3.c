#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int main(int argc, char **argv)
{

	int m=0,n=0,p=m+n,s;
	printf("%d,%p\n",p,&p);//接着输入第一个数据
	scanf("%d",&m);//输入你的地址
	int *ptr_arr=(int*)malloc(p);
	printf("%p\n",ptr_arr);
	p=m+n;
	printf("输入增量后内存增加\n");
	printf("%d\n",p);
    s= *ptr_arr;
	free(ptr_arr);
	return 0;
}
