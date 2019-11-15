#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	int var1;
	int *ptr_var1 = &var1;
	printf("please input a value of var1:\n");
	scanf("%d",&var1);
	printf("The ptr_var1 is:%d\n",*ptr_var1);

	var1++;
	printf("after increase,the value of var1 is:%d\n",var1);

	(*ptr_var1)++;
	printf("*ptr_var1:%d\n",*ptr_var1);
	printf("var1:%d\n",var1);

	const int cvar1;
	int *ptr_cvar1 = &cvar1;

	printf("please input a value of cvar1:\n");
	scanf("%d",&cvar1);
	printf("The ptr_cvar1 is:%d\n",*ptr_cvar1);

	//cvar1++;
	//const int *ptr_cvar1 = &cvar1;
	(*ptr_cvar1)++;
	printf("cvar1: %d and &cvar1: %p\n",cvar1,&cvar1);
	printf("*ptr_cvar1: %d and ptr_cvar1: %p\n",*ptr_cvar1,ptr_cvar1);

	int var2;
	int *const cptr_var1 = &var1;
	int *const cptr_var2 = &var2;
	printf("please input a value of var2:\n");
	scanf("%d",&var2);
	printf("The cptr_var1 is:%d\n",*cptr_var1);
	printf("The cptr_var2 is:%d\n",*cptr_var2);

	var1++;
	printf("var1:%d\n",var1);
	var2++;
	printf("var2:%d\n",var2);

	(*cptr_var1)++;
	printf("*cptr_var1:%d\n",*cptr_var1);
	(*cptr_var2)++;
	printf("*cptr_var2:%d\n",*cptr_var2);

	const int *const cptr_cvar1 = cvar1;

	return 0;
}
