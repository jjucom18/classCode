#include <stdio.h>
#include <stdlib.h>
void ptr()
{
	int var1,var2,var3;
	printf("请输入三个变量值：\n");
	scanf("%d%d%d",&var1,&var2,&var3);
	int *ptr_var1;
	int *ptr_var2;
	int *ptr_var3;
	ptr_var1 = &var1;
	ptr_var2 = &var2;
	ptr_var3 = &var3;
	printf("exchange before:%d%d%d\n",*ptr_var1,*ptr_var2,*ptr_var3);
	printf("exchange before local:%p%p%p\n",ptr_var1,ptr_var2,ptr_var3);
	int tmp;
	tmp = *ptr_var3;
	*ptr_var3 = *ptr_var2;
	*ptr_var2 = *ptr_var1;
	*ptr_var1 = tmp;
	printf("exchange after :%d%d%d\n",*ptr_var1,*ptr_var2,*ptr_var3);
	printf("exchange after local:%p%p%p\n",ptr_var1,ptr_var2,ptr_var3);


}

int main(int argc,char **argv)
{
	ptr();


	return 0;
}
