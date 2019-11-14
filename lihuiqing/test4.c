#include<stdio.h>
#include<stdlib.h>
int main(int argc,int *argv)
{int var1;
        printf("please input value of var1: ");
	scanf("var1=%d\n",&var1);
	var1++;
	int *ptr_var1=&var1;
	printf("output value of var1 after self-increase: ");
		printf("var1=%d\n",var1);
(*ptr_var1)++;
printf("output value of var1 after calculation: ");
printf("var1=%d\n",var1);

const int cvar1;
printf("please input value of cvar1: ");
scanf("%d\n",&cvar1);
printf("output value of cvar1: =%d\n",cvar1);
const int *ptr_cvar1=&cvar1;
(*ptr_var1)++;
printf("output value of var1: ");
printf("var1=%d\n",var1);
return 0;
}
