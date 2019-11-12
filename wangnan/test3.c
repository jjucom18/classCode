#include<stdio.h>
int  *ptr_ar;
int N;
printf("input N:\n");
scanf("%d",&N);
if(N<=0)N=100;
ptr_ar=(int*)malloc(sizeof(int)*N);
if(!ptr_ar)
{
	printf("alloc ptr_ar error !\n";
			exit(0);
		
}(else
printf("alloc ptr_ar success!\n");

