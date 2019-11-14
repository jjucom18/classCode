#include<stdio.h>
main(){
int var1 ,var2 ,var3;
int *ptr_var1;
int *ptr_var2;
int *ptr_var3;

ptr_var1 = &var1;
ptr_var2 = &var2;
ptr_var3 = &var3;

scanf("%d%d%d",&var1 , &var2 ,&var3);

printf("%3d",var1);
printf("%3d",var2);
printf("%3d\n",var3);

ptr_var1 = &var2;
ptr_var2 = &var3;
ptr_var3 = &var1;

printf ("%d ,%p\n" , *ptr_var1 ,&var1);
printf ("%d ,%p\n" , *ptr_var2 ,&var2);
printf ("%d ,%p\n" , *ptr_var3 ,&var3);

}
