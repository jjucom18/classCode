#include<stdio.h>
int *pt_ar;
int N；
printf("input N:\n") ;
scanf("%d,&N");//输入个数
if(N<=0)N=100;
ptr_ar=(int*)malloc(sizeof(int)*N) ;//动态分配
if（!ptr_ar） {
	printf("alloc ptr_ar error!\n");exit(0);//如果分配失败
}else{
	printf("alloc ptr_ar success!\n");//如果分配成功
}
