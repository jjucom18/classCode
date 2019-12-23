#include<stdio.h>
 
void main(){
	int var1;
	int *ptr_var1;
	ptr_var1=&var1;
	printf("请输入var1的值");
	scanf("%d",&var1);
	printf("%d\n",var1);
	printf("%p\n",ptr_var1);
	var1++;
	printf("%d\n",var1);
	printf("%d\n",*ptr_var1);	
	int s;
	printf("请输入常量cvar1的值");
	scanf("%d",&s);
        const int cvar1=s;
	const int *ptr_cvar1;
	ptr_cvar1=&cvar1;
        printf("%d\n",*ptr_cvar1);
        var1++;
        ptr_cvar1=&var1;
        printf("%d\n",*ptr_cvar1);
	int n;
	printf("请输入常量var2的值");
	scanf("%d",&n);
	const int var2=n;
	int *const cptr_var1=&var1;
	int *const cptr_var2;
	printf("%d,%d\n",*cptr_var1,var2);
	printf("cptr_var2不能指向常量var2\n");
	var1++;
	printf("var2是常量不能修改\n");
	printf("%d,%d\n",*cptr_var1,var2);
	const int *cptr_cvar1;
	printf("常量指针的值n不能被修改！\n");
}

