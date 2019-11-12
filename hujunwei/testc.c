#include<stdio.h>
int main(int argc,  char **argv)
{ 
   int var1,var2,var3,Temp;
   int *ptr_var1=&var1,*ptr_var2=&var2,*ptr_var3=&var3;
  
scanf("%d,%d,%d",&var1,&var2,&var3);
printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
printf("var1=%p,var2=%p,var3=%p\n",&var1,&var2,&var3);
Temp=*ptr_var1;
*ptr_var1=*ptr_var2;
*ptr_var2=*ptr_var3;
*ptr_var3=Temp;
printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
}


