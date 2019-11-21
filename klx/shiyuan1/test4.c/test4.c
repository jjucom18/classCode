#include<stdio.h>
#include<stdlib.h>
int main(int argc,int *argv)
          {int var1;
	       
		  printf("输入var1: ");
		
		  scanf("var1=%d\n",&var1);
		var1++;
			int *ptr_var1=&var1;
			printf("增加后var1的值 : ");
			 printf("var1=%d\n",var1);
			   (*ptr_var1)++;
				printf("var1=%d\n",var1);

			const int cvar1;
			printf("输入 cvar1: ");
	       	 scanf("var1=%d\n",&cvar1);
			printf("输出 cvar1: =%d\n",cvar1);
	  		const int *ptr_cvar1=&cvar1;
		 (*ptr_var1)++;
	  		printf("输出var1: ");
		printf("var1=%d\n",var1);
			return 0;
}
