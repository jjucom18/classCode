#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int main(int argv,char **argc)
{int m=0,n=0,p=m+n,s;	
printf("初始定义的值:");	
printf("%d,%p\n",p,&p);
printf("please input your first data:\n");
scanf("%d",&m);
printf("please input your add data:\n");
scanf("%d",&n);
int *ptr_arr=(int*)malloc(p);
printf("打印初始的指针地址\n");//可不用打印。
printf("%p\n",ptr_arr);
p=m+n;
printf("输入增量后内存增加\n");
printf("%d\n",p);
printf("打印输入增量后的指针地址\n");//可不用打印。
printf("%p\n",ptr_arr);
s= *ptr_arr;
free(ptr_arr);
return 0;

}

