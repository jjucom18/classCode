#include"stdio.h" 
void swp(int *n1,int *n2,int *n3) 
		{int num;
			num = *n1;
			*n1 = *n2;
            *n2 = *n3;
			*n3 = num;
					} 
int main (int argc , char **argv)
{
	int var1,var2,var3;
	int *ptr_var1,*ptr_var2,*ptr_var3;
	ptr_var1 = &var1;
	ptr_var2 = &var2;
	ptr_var2 = &var3;

	printf("请输入三个整数用逗号隔开") ;
	scanf("%d,%d,%d",&var1,&var2,&var3);
	printf("%d,%d,%d\n",var1,var2,var3);
	printf("%p,%p,%p\n",ptr_var1,ptr_var2,ptr_var3);
    swp(ptr_var1,ptr_var2,ptr_var3);
	printf("%d,%d,%d\n",var1,var2,var3);
	return 0;


}
