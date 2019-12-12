#include<stdio.h>
#include<stdlib.h>
void main(){
	int var1;
	int *ptr_var1;	
       	ptr_var1=&var1;
	printf("请输入var1的值:");
	scanf("%d",&var1);
	printf("原值为:%d\n",var1);
	printf("地址为:%p\n",ptr_var1);
	var1++;
	printf("通过变量自增后的值:%d\n",var1);
	printf("通过指针运算变换后的值:%d\n",*ptr_var1);
	int s;
	printf("请输入常量cvar1的值:");
	scanf("%d",&s);
	const int cvar1=s;
	const int *ptr_cvar1;
	ptr_cvar1=&cvar1;
	printf("指针的值:%d\n",*ptr_cvar1);
	var1++;
	ptr_cvar1=&var1;
	printf("自增后的值:%d\n",*ptr_cvar1);
        int n;
		printf("请输入常量var2的值:");
	scanf("%d",&n);
	const int var2=n;
	int *const cptr_var1=&var1;
	int *const cptr_var2;
	printf("指针的值:%d,常量的值:%d\n",*cptr_var1,var2);
	var1++;
	printf("常量var2无法被修改\n");
	printf("自增后的值:%d,%d\n",*cptr_var1,var2);
	const int *cptr_cvar1;
	printf("常量指针的值无法被修改\n");
} 
