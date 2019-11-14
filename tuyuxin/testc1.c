#include<stdio.h>
void main()
{
        int varl,var2,var3;
        scanf("%d,%d,%d",&var1,&var2,&var3);
        int *ptr_var1 = &var3;
        int *ptr_var2 = &var1;
        int *prt_var3 = &var2;
        printf("%d,%d,%d\n",var1,var2,var3);
        printf("%p,%p,%p\n",&var1,&var2,&var3);
        printf("%d,%d,%d\n",*ptr_var1,*ptr_var2,*ptr_var3);
}

