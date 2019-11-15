#include"shiyan4.h"


int main(int argc, char **argv)
{
	int var1;
	int cvar1,var2;
	printf("指向变量的指针\n");
	printf("请输入var1的值\n");
	scanf("%d",&var1);
	Ptr1(var1);
	printf("指向常量的指针\n");
	printf("请输入var1的值\n");
	scanf("%d",&var1);
	printf("请输入cvar1的值\n");
	scanf("%d",&cvar1);
	Ptr2(var1,cvar1);
	printf("指向变量的常指针\n");
	printf("请输入var1的值\n");
	scanf("%d",&var1);
	printf("请输入var2的值\n");
	scanf("%d",&var2);
	Ptr3(var1,var2);
	
	return 0;
}