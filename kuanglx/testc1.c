#include<stdio.h>

void main()

{ 

	   double t,var1,var2,var3;
	   

	   double *ptr_var1=&var1;
	   double *ptr_var2=&var2;
	   double *ptr_var3=&var3;

	      scanf("%lf,%lf,%lf",&var1,&var2,&var3);

	              printf("var1=%f,var2=%f,var3=%f\n",var1,var2,var3);

	                      printf("var1=%p,var2=%p,var3=%p\n",&var1,&var2,&var3);

	      t=*ptr_var1;

	      *ptr_var1=*ptr_var2;

	      *ptr_var2=*ptr_var3;

	      *ptr_var3=t;

	      printf("var1=%f,var2=%f,var3=%f\n",var1,var2,var3);
			
	    
}


