#include<stdio.h>
int main()
{
	int var1,var2,var3;
	printf("请输入三个数：");
	scanf("%d,%d,%d",&var1,&var2,&var3);
	printf("交换前:%d,%d,%d\n",var1,var2,var3);
	int *ptr_var1,*ptr_var2,*ptr_var3;
	ptr_var1=&var1;
		ptr_var2=&var2;
		ptr_var3=&var3;
		printf("%p,%p,%p\n",&var1,&var2,&var3);
		int temp=*ptr_var1;
		var1=*ptr_var3;
			var3=*ptr_var2;
			var2=temp;
			printf("交换后：");
			printf("%d,%d,%d",var1,var2,var3);
			return 0;

}
