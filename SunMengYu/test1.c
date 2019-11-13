#include<stdio.h>
        int var1,var2,var3;
	int *ptr_var1;int *ptr_var2;int *ptr_var3;
	int main()
        {
	ptr_var1=&var1;
	ptr_var2=&var2;
        ptr_var3=&var3;
	scanf("%d,%d,%d\n",&var1,&var2,&var3);
	int t;
	t=ptr_var1;
	ptr_var1=ptr_var2;
	ptr_var2=ptr_var3;
	ptr_var3=t;
		printf("%d,%d,%d\n",var1,var2,var3);
		printf("%p,%p,%p\n",ptr_var1,ptr_var2,ptr_var3);
	}

