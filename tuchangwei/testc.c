#include <stdio.h>

void swap()
{
	int var1,var2,var3;
	scanf("%d,%d,%d\n",&var1,&var2,&var3);
	printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
	printf("&var1=%p,&var2=%p,&var3=%p\n",&var1,&var2,&var3);

	int *ptrvar1=&var1;
	int *ptrvar2=&var2;
	int *ptrvar3=&var3;
	int temp;
	temp=var1;
	var1=var3;
	var3=var2;
	var2=temp;
	printf("after swap\n");
	printf("var1=%d,var2=%d,var3=%d\n",*ptrvar3,*ptrvar1,*ptrvar2);
}
int main()
{
	swap();
}

 
