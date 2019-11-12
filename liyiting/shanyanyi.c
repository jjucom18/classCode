#include<stdio.h>
#include<stdlib.h>

int main()
{
	int var1,var2,var3;
 	scanf("%d,%d,%d",&var1,&var2,&var3)；
        printf("var1=%d\n,var2=%d\n,var3=%d\n",var1,var2,var3);
	       printf("\n");
        
	       
	int *prt_var1,*prt_ar2,*prt_var3;
    
	printf("var1=%x\n,var2=%x\n,var3=%x\n",&var1,&var2,&var3);
		printf("\n"); 
       
	int *p = NULL,*s = NULL;*q = NULL;
	*p = *var1;
	*s = *var2;
	*m = *var3;
	*var1 = *var3;
        *var2 = *var1;
        *var3 = *var2;
	printf("var1=%d\n,var2=%d\n,var3=%d\n",var1,var2,var3);
	       prinntf("\n");
	




	return 0;
}
