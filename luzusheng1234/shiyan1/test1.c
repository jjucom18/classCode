#include <stdio.h>

int main(int argc,char **argv){
	int var1,var2,var3,t;
	int *ptr_var1,*ptr_var2,*ptr_var3;
	ptr_var1 = &var1;
	ptr_var2 = &var2;
	ptr_var3 = &var3;
	scanf("%d,%d,%d",&var1,&var2,&var3);
	printf("var1: %d &var1:%p\n",var1,&var1);
	printf("var2: %d &var2:%p\n",var2,&var2);
	printf("var3: %d &var3:%p\n",var3,&var3);
	t = *ptr_var3;
	var3 = *ptr_var2;
	var2 = *ptr_var1;
	*ptr_var1 = t;
	printf("var1: %d &var1:%p\n",var1,&var1);
	printf("var2: %d &var2:%p\n",var2,&var2);
	printf("var3: %d &var3:%p\n",var3,&var3);
	return 0;
}