#include <stdio.h>
#include <stdlib.h>

void ptr()
{
	int a,b,c;
	int *ptr_var1;
	ptr_var1 = &a;
	ptr_var1 = (int *)malloc(sizeof(int));
	int *ptr_var2;
	ptr_var2 = &b;
	ptr_var2 = (int *)malloc(sizeof(int));
	int *ptr_var3;
	ptr_var3 = &c;
	ptr_var3 = (int *)malloc(sizeof(int));
	printf("请输入三个指针的值：\n");
	scanf("%d%d%d",ptr_var1,ptr_var2,ptr_var3);
	printf("exchange before value ptr_var1 :%d\n",*ptr_var1);
	printf("exchange before local ptr_var1:%p\n",ptr_var1);
	printf("exchange before value ptr_var2 :%d\n",*ptr_var2);
	printf("exchange before local ptr_var2:%p\n",ptr_var2);
	printf("exchange before value ptr_var3 :%d\n",*ptr_var3);
	printf("exchange before local ptr_var3:%p\n",ptr_var3);
	int tmp;
	tmp = *ptr_var3;
	*ptr_var3 = *ptr_var2;
	*ptr_var2 = *ptr_var1;
	*ptr_var1 = tmp;

	printf("exchange after value ptr_var1 :%d\n",*ptr_var1);
	printf("exchange after local ptr_var1:%p\n",ptr_var1);
	printf("exchange after value ptr_var2 :%d\n",*ptr_var2);
	printf("exchange after local ptr_var2:%p\n",ptr_var2);
	printf("exchange after value ptr_var3 :%d\n",*ptr_var3);
	printf("exchange after local ptr_var3:%p\n",ptr_var3);

	
}
