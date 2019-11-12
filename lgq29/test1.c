#include <stdio.h>
#include <stdlib,h>
int main()
{
    int var1,var2,var3,temp;
    int ptr_var1,ptr_var2,ptr_var3;
    ptr_var1=&var1;
    ptr_var2=&var2;
    ptr_var3=&var3;
    scanf("%d,%d,%d",&var1,&var2,&var3);
    printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
    printf("ptr_var1=%d,ptr_var2=%d,ptr_var3=%d\n",ptr_var1,ptr_var2,ptr_var3);
    temp=ptr_var2;
    ptr_var2=ptr_var1;
    ptr_var1=ptr_var3;
    ptr_var3=temp;
    printf("var1=%d,var2=%d,var3=%d",var1,var2,var3);
    return 0;
}
