#include"shiyan4.h"
void Ptr1(int var1)
{   int *ptr_var1;
	ptr_var1=&var1;
	printf("输入的var1=%d\n",var1);var1++;
	printf("变量自增后的var1=%d\n",var1);(*ptr_var1)++;
	printf("指针运算后的var1=%d\n",var1);
	return;
}
void Ptr2(int var1,const int cvar1){
	const int *ptr_cvar1;
	ptr_cvar1=&var1;
	printf("输入的var1=%d,cvar1=%d\n",var1,cvar1);
	printf("ptr_cvar1=%p\n",ptr_cvar1);
	ptr_cvar1=&cvar1;
	printf("修改后的ptr_cvar1=%p\n",ptr_cvar1);
	return;
}
void Ptr3(int var1,const int var2){
	int *const ptr_var1=&var1;
	int *const ptr_var2=&var2;
	printf("输入的var1=%d，var2=%d\n",var1,var2);
	return;
}
void Ptr4(const int cvar1){
	const int *const cptr_cvar1=&cvar1;
	return;
}
#include"shiyan4.h"
int main(int argc,char **agrv)
{
	int var1;int cvar1,var2;
	printf("指向变量的指针\n");
	printf("请输入var1的值\n");
	scanf("%d",&var1);
	ptr1(var1);
	printf("指向常量的指针\n");
	printf("请输入var1的值\n");
	scanf("%d",&var1);
	printf("请输入cvar1的值\n");
	scanf("%d",&cvar1);
}
