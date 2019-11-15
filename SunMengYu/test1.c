#include<stdio.h>
        int main()
{
	int var1;int var2;int var3;
	int *ptr_var1;int *ptr_var2;int *ptr_var3;
	scanf("%d,%d,%d/n",&var1,&var2,&var3);
	printf("%d,%d,%d\n",var1,var2,var3);
      	ptr_var1=&var1;
	ptr_var2=&var2;
        ptr_var3=&var3;
	
	ptr_var1 =&var2;
	ptr_var2 =&var3;
	ptr_var3 =&var1;
		printf("%d,%d,%d\n",*ptr_var1,*ptr_var2,*ptr_var3);
		printf("%p,%p,%p\n",ptr_var1,ptr_var2,ptr_var3);
	}

