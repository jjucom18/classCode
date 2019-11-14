#include<stdio.h>
#include<stdlib.h>
int main(int argv,char **argc)
{
	int var1,var2,var3,temp;
	int *ptr_var1=&var1,*ptr_var2=&var2,*ptr_var3=&var3;
	printf("请输入三个数字:");
	scanf("%d%d%d",&var1,&var2,&var3);
	printf("原始输入值:%d%d%d\n",var1,var2,var3);
	printf("变量地址:%p,%p,%p\n",&var1,&var2,&var3);
	temp=*ptr_var1;
	*ptr_var1=*ptr_var3;
	*ptr_var3=*ptr_var2;
	*ptr_var2=temp;
	printf("交换后的值:%d%d%d\n",var1,var2,var3);
}

