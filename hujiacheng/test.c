#include"stdio.h" 
void swap(int *p1,int *p2,int *p3){
		int p;
		p=*p1;
		*p1=*p2;
		*p2=*p3;
		*p3=p;} 
int main ()
{
	int var1,var2,var3;
	int *ptr_var1,*ptr_var2,*ptr_var3;
	printf("请输入三个整数用逗号隔开");
	scanf("%d,%d,%d",&var1,&var2,&var3);
	ptr_var1 = &var1;
	ptr_var2 = &var2;
	ptr_var3 = &var3;
	printf("%d,%d,%d\n",var1,var2,var3);
	printf("%p,%p,%p\n",ptr_var1,ptr_var2,ptr_var3);
    	swap(ptr_var1,ptr_var2,ptr_var3);
	printf("%d,%d,%d\n",var1,var2,var3);



}
