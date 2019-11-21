#include"report1.h"

int main(int argc, char **argv){
	
	int var1,var2,var3;
	int *ptr_var1,*ptr_var2,*ptr_var3;
	printf("请输入var1，var2，var3的值\n");
	scanf("%d,%d,%d",&var1,&var2,&var3);
    ptr_var1 = &var1;
    ptr_var2 = &var2;
    ptr_var3 = &var3;
    printf("初始值：\n");
    printf("var1 = %d\n var2 = %d\n var3 = %d\n",var1,var2,var3);
    printf("\n");
    printf("交换之前的地址:\n");
    printf("var1 = %p\n var2 = %p\n var3 = %p\n",&var1,&var2,&var3);
    printf("\n");
    swap(ptr_var1,ptr_var2,ptr_var3);
    printf("交换之后的值：\n");
    printf("var1 = %d\n var2 = %d\n var3 = %d",var1,var2,var3);

    return 0;
}
