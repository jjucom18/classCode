#include <stdio.h>
void main(){
	int var1,var2,var3,mcn;
	int *ptr_var1,*ptr_var2,*ptr_var3;
	scanf("%d,%d,%d",&var1,&var2,&var3);
	printf("%d,%d,%d",var1,var2,var3);
	mcn=var1;
	var1=var3;
	var3=var2;
	var2=mcn;
	printf("%d,%d,%d",var1,var2,var3);
     ptr_var1=&var1;
	 ptr_var2=&var2;
	 ptr_var3=&var3;
	printf("var1=%p,var2=%p,var3=%p",&var1,&var2,&var3);
	return 0;
}

