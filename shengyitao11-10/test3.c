#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{	
int *ptr_ar,j,k;
int N;
printf("input N:\n");
if(N<=0) N=100;
ptr_ar=(int*)malloc(sizeof(int)*N);
if(!ptr_ar){
printf("alloc ptr_ar error !\n");exit(0):
}else{
printf("alloc ptr_ar success!\n");
}
int *A;
A =(int*)malloc（sizeof(int)*n）；
printf("内存初始值：%d\j",j);
printf("指针地址：%p\j",A);
free(A)
