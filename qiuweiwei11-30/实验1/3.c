#include <stdio.h>

#include <stdlib.h>
int main(int argc,char **argv)
{
int *ptr_arr;
int N;
printf("input N:\n");
scanf("%d",&N); //输入个数
if (N<=0) N=100;
ptr_arr = (int *) malloc(sizeof(int) * N); 
if (!ptr_arr){
printf(" 分配失败\n"); exit(0); 
} else {
printf("分配成功\n"); 
}
printf("内存的初始值：%d\n",N);
printf("指针的地址：%p\n",ptr_arr);
free(ptr_arr);
printf("请输入想改变的内存变量：\n");
scanf("%d",&N);
ptr_arr = (int *)malloc(sizeof(int) * N);
printf("内存的初始值：%d\n",N);
printf("指针的地址：%p",ptr_arr);
} 
