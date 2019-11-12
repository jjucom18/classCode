#include <stdio.h>
int main(int argc,char **agrv){
int var1,var2,var3,temp;
int *ptr_var1=&var1,*ptr_var2=&var2,*ptr_var3=&var3;
scanf("%d,%d,%d",&var1,&var2,&var3);
printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
printf("%p,%p,%p\n",&var1,&var2,&var3);
temp=*ptr_var1;
*ptr_var1=*ptr_var3;
*ptr_var3=*ptr_var2;
*ptr_var2=temp;
printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
}
