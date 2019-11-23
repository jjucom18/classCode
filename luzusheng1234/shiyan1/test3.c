#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv){
	int n;
	printf("输入内存n的大小\n")；
	scanf("%d",&n);
	int *ptr_arr = (int *)malloc(sizeof(int)*n);
	scanf("%d",ptr_arr);
	printf("%d,%p",*ptr_arr,ptr_arr);

	return 0;
}
