#include<stdio.h>
 void swap(int *ptr_var1,int *ptr_var2,int *prt_var3) 
 {

     int t;
      t=*x;
      *x=*y;
      *y=*z;
	  *z=t;
					
 } 
 int main(int argc, char **argv) {

    int var1;
    int var2;
    int var3;
	   printf("请输入var1,var2,var3\n") ;
	   scanf("%d,%d,%d\n",&var1,&var2,&var3) ;
    int *ptr_var1;
    int *ptr_var2;
    int *ptr_var3;
		   ptr_var1=&var1;
		   ptr_var2=&var2;
		   ptr_var3=&var3;
	    printf("%d,%d,%d\n",&var1,&var2,&var3) ;
	    printf("%p,%p,%p\n",var1,var2,var3) ;
	   swap(ptr_var1,ptr_var2,ptr_var3) ;
	    printf("%d,%d,%d\n",var1,var2,var3) ;
		    return 0;
	 }
	