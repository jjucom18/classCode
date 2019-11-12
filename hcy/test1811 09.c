#include<stdio.h>                                                                                                     2 void swap(int* var1,int* var2, int* var3);
   int var1,var2,var3;
   {
  
      int temp;
       temp=*var2;
       *var2=*var1;
       *var1=temp;
 
      temp=*var3;
     *var3=*var2;
      *var2=temp;

     temp=*var3;
      *var3=*var1;
      *var1=temp;
  }
  int main(   ){
  int var1,var2,var3;
  int*ptr_var1,*ptr_var2,*ptr_var3;
  scanf("%d%d%d",&var1,&var2,&var3);
  ptr_var1=&var1;
  ptr_var2=&var2;
  ptr_var3=&var3;
  printf("Original value:\n");
  printf("var1=%d\nvar2=%d\nvar3=%d\n",var1,var2,var3);
  printf("\n");
  printf("Address before swap:\n");
  printf("var1=%x\nvar2=%x\nvar3=%x\n",&var1,&var2,&var3);
  printf("\n");
  swap(ptr_var1,ptr_var2,ptr_var3);
  printf("Value after swap:\n")
        return 0;
  }         
