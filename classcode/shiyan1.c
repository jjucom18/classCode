#include<stdio.h>
int main()
{
    int var1,var2,var3;
    int *ptr_var1,*ptr_var2,*ptr_var3;
    scanf("%d%d%d",&var1,&var2,&var3);
    ptr_var1 = &var1;
    ptr_var2 = &var2;
    ptr_var3 = &var3;
    swap(ptr_var1,ptr_var2,ptr_var3);
    var2=ptr_var1;
    var3=ptr_var2;
    var1=ptr_var3;
    printf("%d%d%d",var1.var2,var3);
    return 0;
}
