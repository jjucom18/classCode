#include<stdio.h>
int main(int argc,char **argc)
{

    int var1;
	int var2;
	int var3;

	int *ptr_var1;
	int *ptr_var2;
	int *ptr_var3;
	prt_var1=&var1;
	prt_var2=&var2;  
	prt_var3=&var3; 
	printf("%p,%p,%p\n",ptr_var1,ptr_var2,ptr_var3) ;
	ptr_var1=&var3;ptr_var3=&var2;ptr_var2=&var1;
	scanf("%d,%d,%d",&var1,&var2,&var3);
	printf("%d,%d,%d\n",var1,var2,var3);
	printf("%d,%d,%d\n",*ptr_var1,*ptr_var2,*ptr_var3);
	return 0;
} 
