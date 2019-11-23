#include"shiyan.h"

void ChangeData(){

	int var1,var2,var3,tmp;
	int *ptr_var1,*ptr_var2,*ptr_var3;
	ptr_var1 = &var1;
	ptr_var2 = &var2;
	ptr_var3 = &var3;
	printf("请输入 var1,var2,var3\n");
	scanf("%d,%d,%d",&var1,&var2,&var3);
	printf("%d,%d,%d\n",var1,var2,var3);
	printf("地址是 %p,%p,%p\n",&var1,&var2,&var3);
	tmp = *ptr_var2;
	var2 = *ptr_var1;
	var1 = *ptr_var3;
	var3 = tmp;
	printf("交换后的值为%d,%d,%d\n",var1,var2,var3);

	return;
}
