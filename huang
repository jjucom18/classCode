#include <stdio.h>
void swap(int *p1,int *p2,int *p3)
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
int main()
{
    int var1,var2,var3;
    int *ptr_var1,*ptr_var2,*ptr_var3;
    scanf("%d%d%d",&var1,&var2,&var3);
    ptr_var1 = &var1;
    ptr_var2 = &var2;
    ptr_var3 = &var3;
    printf("Original value:\n");
    printf(" var1 = %d\n var2 = %d\n var3 = %d\n",var1,var2,var3);
    printf("\n");
    printf("Address before swap:\n");
    printf(" var1 = %x\n var2 = %x\n var3 = %x\n",&var1,&var2,&var3);
    printf("\n");
    swap(ptr_var1,ptr_var2,ptr_var3);
    printf("Value after swap:\n");
    printf(" var1 = %d\n var2 = %d\n var3 = %d",var1,var2,var3);
    return 0;
}
