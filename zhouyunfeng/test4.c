#include<stdio.h>

#include<malloc.h>

int main(int argv,char **argc)

{int var1,p;int const cvar1;p=cvar1;

	int *ptr_var1=&var1;

	int const *ptr_cvar1=&cvar1;

	printf("please  input your data var1:,cvar1:");
	
	scanf("%d,%d",&var1,&p);

	var1=var1+(*ptr_cvar1); 

	printf("%d",var1);

	return 0;

}
