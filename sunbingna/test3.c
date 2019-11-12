#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *ptr_arr = (int *)malloc(sizeof(int));
	int a;
	scanf("%d",&a);
	ptr_arr=&a;
	printf("%d,%p",a,&a);	
}
