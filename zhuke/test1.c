#include<stdio.h>

int main(int argc,char **argv)
{
	int var1,var2,var3,temp;
	int *ptr_var1,*ptr_var2,*ptr_var3;

	scanf("%d,%d,%d",&var1,&var2,&var3);
	ptr_var1 = &var1;
	ptr_var2 = &var2;
	ptr_var3 = &var3;

	printf("the original var1 is %d and address is %p\n",var1,&var1);
	printf("the original var2 is %d and address is %p\n",var2,&var2);
	printf("the original var3 is %d and address is %p\n",var3,&var3);

	temp = *ptr_var1;
	*ptr_var1 = *ptr_var2;
	*ptr_var2 = temp;

	temp = *ptr_var2;
	*ptr_var2 = *ptr_var3;
	*ptr_var3 = temp;

	temp = *ptr_var3;
	*ptr_var3 = *ptr_var1;
	*ptr_var1 = temp;
	
	printf("after swap:var1 = %d,var2 = %d,var3 = %d\n",var1,var2,var3);
	
	return 0;}
        
