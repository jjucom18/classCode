#include<stdio.h>

int main(int argc, char **argv)
{
	int var1,var2,var3,exc;
	scanf("%d,%d,%d",&var1,&var2,&var3);
	printf("%d,%d,%d\n",var1,var2,var3);
	exc=var1;
	var1=var3;
	var3=var2;
	var2=exc;
	printf("%d,%d,%d\n",var1,var2,var3);
	printf("%x,%x,%x\n",&var1,&var2,&var3);
	return 0;
}
