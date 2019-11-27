#include<stdio.h>

#include<stdlib.h> 


void fun();



int main(){

	

	fun();

	

	return 0;

} 



void fun(){

	int size, initialValue, increment, *ptr_arr = NULL, *p = NULL;

	printf("请输入内存大小、初始值、增量：");

	scanf("%d %d %d",&size, &initialValue, &increment);

	

	// 申请内存 

	ptr_arr = (int*)malloc(size*sizeof(int));

	if(ptr_arr == NULL){

		printf("内存申请失败！");

		return; 

	}

	

	p = ptr_arr;

	// 内存数值初始化 

	for(int i = 0; i < size; i++,p++){

		*p = initialValue + i * increment;

	}

	

	p = ptr_arr;

	// 输出数值及地址 

	for(int i = 0; i < size; i++,p++){

		if(p == NULL) {

			printf("失败");

			break;

		}

		printf("初始值：%d 内存地址：%X\n", *p, p);

	}

	

	// 释放内存 

	free(ptr_arr);

	free(p); 

	return; 

} 
