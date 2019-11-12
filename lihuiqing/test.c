#include<stdio.h>
#include<stdlib.h>
int main()
{int var1,var2,var3;
	printf("please input: var1,var2,var3\n");
	scanf("%d,%d,%d",&var1,&var2,&var3);
printf("before:var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
printf("%p,%p,%p\n",&var1,&var2,&var3);
int *ptr_var1=&var1,*ptr_var2=&var2,*ptr_var3=&var3;
int i;
i=*ptr_var1;
*ptr_var1=*ptr_var2;
*ptr_var2=*ptr_var3;
*ptr_var3=i;
printf("after:var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
return 0;
}
