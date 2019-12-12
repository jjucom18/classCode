#include<stdio.h>
#include<stdlib.h>
int *f1(int n){
	int *ptr_arr=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		ptr_arr[i]=i+1;}
	printf("初始值和地址：\n");
	for(int j=0;j<n;j++){
		printf("ptr_arr[%d]=%d  ",j,ptr_arr[j]);
		printf("ptr_arr[%d]=%p\n",j,&ptr_arr[j]);}
	return ptr_arr;}
int main(){
	int a;
	int *ptr_arr;
	printf("请输入内存大小：");
	scanf("%d",&a);
	ptr_arr=f1(a);
    return 0;}

