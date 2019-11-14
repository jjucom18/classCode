#include <stdio.h>    
int main()
{int var1,var2,var3,*ptr_var1,*ptr_var2,*ptr_var3;
   scanf("%d,%d,%d",&var1,&var2,&var3);
 ptr_var1=&var1;
   ptr_var2=&var2;
   ptr_var3=&var3;
   int t;
   t=*ptr_var1;
   *ptr_var1=*ptr_var3;
   *ptr_var3=*ptr_var2;
   *ptr_var2=t;
                          
printf("var1=%d,var2=%d,var3=%d",*ptr_var1,*ptr_var2,*ptr_var3);
}
