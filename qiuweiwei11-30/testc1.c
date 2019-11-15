#include"stdio.h"             

void swap(int*p1,int*p2,int*p3)
{int temp;
	 temp=*p1;
	   *p1=*p2;
	      *p2=temp;
	          *p2=*p3;
		      *p3=temp;}

		      int main()
{
	int var1,var2,var3;
	int *ptr_var1,*ptr_var2,*ptr_var3;
	scanf("%d%d%d",&var1,&var2,&var3);
	ptr_var1=&var1;
	ptr_var2=&var2;
	ptr_var3=&var3;
	 printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
	  printf("var1=%p,var2=%p,var3=%p\n",&var1,&var2,&var3);
	    swap(ptr_var1,ptr_var2,ptr_var3);                                                                                           
      printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
	     return 0;
}
