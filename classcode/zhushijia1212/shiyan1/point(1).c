#include <stdio.h>
void exchange(int *p1,int *p2,int *p3)
{
    int t;
    t = *p1;
    *p1 = *p2;
    *p2 = t;
     
    t = *p2;
    *p2 = *p3;
    *p3 = t;
     
    t = *p3;
    *p3 = *p1;
    *p1 = t;
}
int main()
{
    int var1,var2,var3;
    int *ptr_var1,*ptr_var2,*ptr_var3;
    scanf("%d%d%d",&var1,&var2,&var3);
    ptr_var1 = &var1;
    ptr_var2 = &var2;
    ptr_var3 = &var3;
    printf("The original input value of the variable is:\n");
    printf(" var1 = %d\n var2 = %d\n var3 = %d\n",var1,var2,var3);
    printf("\n");
    printf("Variable address before exchange:\n");
    printf(" var1 = %x\n var2 = %x\n var3 = %x\n",&var1,&var2,&var3);
    printf("\n");
    exchange(ptr_var1,ptr_var2,ptr_var3);
    printf(" value of the variable after exchange:\n");
    printf(" var1 = %d\n var2 = %d\n var3 = %d",var1,var2,var3);
    return 0;
}
