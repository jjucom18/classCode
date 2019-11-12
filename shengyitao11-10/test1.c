#include<stdio.h>
void main()
{	
int var1,var2,var3,temp;
int *ptr1=&var1,*ptr2=&var2,*ptr3=&var3;
scanf("%d,%d,%d",&var1,&var2,&var3);
printf("var1=%d,var2=%d,var3=%d",&var1,&var2,&var3);
temp=*ptr1;
*ptr2=*ptr1;
*ptr3=*ptr2;
temp=*ptr3;
printf("var1=%d,var2=%d,var3=%d",var1,var2,var3)；
}                                                                                                                                                                                                                                                                          }            
