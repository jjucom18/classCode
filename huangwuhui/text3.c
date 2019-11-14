#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
int *ptr_arr;
int N;
printf("input N:\n");
scanf("%d",&N);
if(N<=0) N=100;
ptr_arr=(int*)malloc(sizeof(int)*N);
if(!ptr_arr){
	printf("alloc ptr_arr error !\n");
	exit(0);
	
}else{
	printf("alloc ptr_arr success !\n")；
}

	
	
	
}
