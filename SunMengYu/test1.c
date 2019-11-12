#include<stdio.h>
        int var1,var2,var3;
	int swap(int *var1,int *var2,int *var3);
	int main()
	ptr_var1=&var1;
	ptr_var2=&var2;
        ptr_var3=&var3;
	scanf("%d,%d,%d\n",&var1,&var2,&var3)
	int t;
	t=ptr_var1;
	ptr_var1=ptr_var2;
	ptr_var2=ptr_var3;
	ptr_var3=t;
		printf("%d,%d,%d\n",var1,var2,var3);
		swap("%d,%d,%d\n",ptr_var1,ptr_var2,ptr_var3);
	}

