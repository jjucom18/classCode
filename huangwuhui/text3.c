#include<stdio.h>
#include<stdlib.h>


void main() 
{
	int *ptr_arr = (int *) malloc(sizeof(int) ) ;
	int a;
	int i;
	printf("请输入一个数字\n") ;
	scanf("%d",&a) ;
	for(i=0;i<a;i++) 
{
 ptr_arr[i]  = i+a;
 printf("%d\t%p\n",ptr_arr[i] ,&ptr_arr[i] ) ;} } 
