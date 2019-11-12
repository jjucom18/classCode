#include<stdio.h>

int main(int argr, char **argv) 
{
	int var1,var2,var3;
	int *ptr_var1, *ptr_var2,  *ptr_var3;
	ptr_var1=&var1;
	ptr_var2=&var2;
	ptr_var3=&var3;
	int scanf("%d,%d,%d",&var1,&var2,&var3) ;
	printf("原始输入值：var1=%d,var2=%d,var3=%d/n",var1,var2,var3) ;
	printf("地址:var1=%p,var2=%p,var3=%p/n",&var1,&var2,&var3) ;
	int *tem;
	tem=ptr_var3;
	ptr_var3=ptr_var2;
	ptr_var2=ptr_var1;
	ptr_var1=tem;
	print("新值:var1=%d,var2=%d,var3=%d",*ptr_var1,*ptr_var2,*ptr_var3) ;
}
