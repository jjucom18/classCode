#include<stdio.h>

int main(int argc,char **argv){
	int var1;
	int *ptr_var1;
	ptr_var1 = &var1;
	scanf("%d";&var1);
	var1++;
	printf("%d\n",var1);
	*ptr_var1 = var1;
	printf("%d",*ptr_var1);

	return 0;
}