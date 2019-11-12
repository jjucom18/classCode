 #include<stdio.h>
  
   int main(int argc,char **argv)
   {
       int var1,var2,var3;
       printf("input var1:");
       scanf("%d",&var1);
       printf("input var2:");
       scanf("%d",&var2);
      printf("input var3");
      scanf("%d",&var3);
      int *ptr_var1=&var3;
      int *ptr_var2=&var1;
      int *ptr_var3=&var2;
      printf("%d,%d,%d\n",var1,var2,var3);
      printf("%p,%p,%p\n",&ptr_var1,&ptr_var2,&ptr_var3);
      printf("%d,%d,%d",*ptr_var1,*ptr_var2,*ptr_var3);
 
 
      return 0;
  }
