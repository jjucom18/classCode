#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
	int *ptr_arr = (int *)malloc(sizeof(int));
	scanf("%d",ptr_arr);
	printf("%d,%p",*ptr_arr,ptr_arr);
}
