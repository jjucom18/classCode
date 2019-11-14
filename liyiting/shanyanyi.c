#include<stdio.h>
#include<stdlib.h>

int main()
{
	int var1,var2,var3;
        scanf("%d,%d,%d",&var1,&var2,&var3);
        printf("var1=%d,var2=%d,var3=%d",var1,var2,var3);
        printf("\n");
	printf("&var1=%p\n,&var2=%p\n,&var3=%p\n",&var1,&var2,&var3);
        printf("\n");
        
	int *ptr_var1, *ptr_var2, *ptr_var3;
	int p;
	
        p = *ptr_var1;
	*ptr_var1 = *ptr_var3;
	*ptr_var3 = *ptr_var2;
	*ptr_var2 = p;
        
	printf("var1=%d,var2=%d,var3=%d",var1,var2,var3);

	return 0;
}
