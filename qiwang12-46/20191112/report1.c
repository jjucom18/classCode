#include <stdio.h>
void swap(int *ptr_var1,int *ptr_var2,int *ptr_var3)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
    temp = *p2;
    *p2 = *p3;
    *p3 = temp;
    temp = *p3;
    *p3 = *p1;
    *p1 = temp;
}
int main(){
	int var1,var2,var3;
	int *ptr_var1,*ptr_var2,*ptr_var3;
	scanf("%d%d%d",&var1,&var2,&var3);
    *ptr_var1 = &var1;
    *ptr_var2 = &var2;
    *ptr_var3 = &var3;
    printf("初始值：\n");
    printf("var1 = %d\n var2 = %d\n var3 = %d\n",var1,var2,var3);
    printf("\n");
    printf("交换之前的地址:\n");
    printf("var1 = %x\n var2 = %x\n var3 = %x\n",&var1,&var2,&var3);
    printf("\n");
    swap(ptr_var1,ptr_var2,ptr_var3);
    printf("交换之后的值：\n");
    printf("var1 = %d\n var2 = %d\n var3 = %d",var1,var2,var3);
    return 0;
}