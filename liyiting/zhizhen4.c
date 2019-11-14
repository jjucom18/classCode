#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **ardv)

{
        int var1;
	int *ptr_var1 = &var1;
	printf("用户输入：\n");
	printf("var1:");
	scanf("%d",&var1);
	printf("ptr_var1:%d\n",*ptr_var1);

        var1++;
	printf("var1:%d\n",var1);
        
	(*ptr_var1)++;
	printf("*ptr_var1:%d\n",*ptr_var1);
      	printf("var1:%d\n",var1);

      	const int cvar1;
	int *ptr_cvar1 = &cvar1;
	printf("用户输入：\n");
	printf("cvar1:");
	scanf("%d",&cvar1);
	printf("ptr_cvar1:%d\n",*ptr_cvar1);

       // cvar1++;(error:increment of read-only variable)//
	(*ptr_cvar1)++;

	printf("cvar1:%d\n",cvar1);
	printf("*ptr_cvar1:%d\n",*ptr_cvar1);


      	int var2;
	int *const cptr_var1 = &var1;
	int *const cptr_var2 = &var2;
        printf("用户输入：\n");
	printf("var2:");
	scanf("%d",&var2);
	printf("cptr_var1:%d\n",*cptr_var1);
	printf("cptr_var2:%d\n",*cptr_var2);

        var1++;
	var2++;
	printf("var1:%d\n",var1);
	printf("var2:%d\n",var2);
        
	(*cptr_var1)++;
	(*cptr_var2)++;
	printf("*cptr_var1:%d\n",*cptr_var1);
	printf("*cptr_var2:%d\n",*cptr_var2);

	const int *const cptr_cvar1 = cvar1;
	//cvar1++;(error:increment of read-only variable)//
	//*cptr_cvar1++;(error:increment of read-only variable)//

	return 0;


}
