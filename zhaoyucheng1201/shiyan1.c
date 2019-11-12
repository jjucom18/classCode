#include<stdio.h>
void exchange(int *pt1,int *pt2,int *pt3)
{
    int arr;
    arr = *pt1;
    *pt1 = *pt2;
    *pt2 = arr;
     
    arr = *pt2;
    *pt2 = *pt3;
    *pt3 = arr;
     
    arr = *pt3;
    *pt3 = *pt1;
    *pt1 = arr;
}
int main(int argc, char **argv)
{
 	int var1,var2,var3;
    int *ptr_var1,*ptr_var2,*ptr_var3;
    printf("请输入三个变量的值并以逗号分隔：\n");
    scanf("%d，%d，%d",&var1,&var2,&var3);
    ptr_var1 = &var1;
    ptr_var2 = &var2;
    ptr_var3 = &var3;
    printf("变量的原始输入值为：\n");
    printf(" var1 = %d\n var2 = %d\n var3 = %d\n",var1,var2,var3);
    printf("\n");
    printf("交换前的可变地址：\n");
    printf(" var1 = %x\n var2 = %x\n var3 = %x\n",&var1,&var2,&var3);
    printf("\n");
    exchange(ptr_var1,ptr_var2,ptr_var3);
    printf("交换后变量的值：\n");
    printf(" var1 = %d\n var2 = %d\n var3 = %d",var1,var2,var3);
    printf("\n");
    return 0;
}