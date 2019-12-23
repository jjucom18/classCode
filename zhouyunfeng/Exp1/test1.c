#include<stdio.h>

int main(int argc,  char **argv)

{ 

	   int var1,var2,var3,Num;

	      int *ptr_var1=&var1;int *ptr_var2=&var2;int *ptr_var3=&var3;

	        
	      printf("请输入三个变量值：\n");

	      scanf("%d,%d,%d",&var1,&var2,&var3);

	      printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);

	      printf("var1=%p,var2=%p,var3=%p\n",&var1,&var2,&var3);

	      Num=*ptr_var1;

	      *ptr_var1=*ptr_var2;

	      *ptr_var2=*ptr_var3;

	      *ptr_var3=Num;

	      printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
		
	      return 0;
}


