#include<stdio.h>
void swap(int *p1,int *p2,int *p3)
{
	int num;
	num=*p1;
	*p1=*p3;
	*p3=*p2;
	*p2=num;
} 
int main() 
{
	int var1, var2, var3;
	int *ptr_var1,*ptr_var2,*ptr_var3;
    scanf("%d,%d,%d",&var1,&var2,&var3);
	ptr_var1=&var1;
	ptr_var2=&var2;
	ptr_var3=&var3;
	printf("%d %d %d",var1,var2,var3);
	printf("var1=%p var2=%p var3=%p",&var1,&var2,&var3);
	swap(ptr_var1,ptr_var2,ptr_var3);
	printf("%d %d %d",var1,var2,var3); 
    return 0;
}
