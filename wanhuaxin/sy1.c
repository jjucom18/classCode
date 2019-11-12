#include<stdio.h>
void swap()                                                                                                             {                                                                                                                         int var1,var2,var3;                                                                                                     int *ptr_var1,*ptr_var2,*ptr_var3;                                                                                      scanf("%d,%d,%d",&var1,&var2,&var3);                                                                                    printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);                                                                     printf("&var1=%p,&var2=%p,&var3=%p\n",&var1,&var2,&var3);                                                               int temp;                                                                                                               temp=ptr_var1;                                                                                                          ptr_var1=ptr_var3;
  ptr_var2=ptr_var3;
  ptr_var3=temp;
printf("after swap\n");
printf("var1=%d,var2=%d,var3=%d\n",*ptr_var1,*ptr_var2,*ptr_var3);
}
