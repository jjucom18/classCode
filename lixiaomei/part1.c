#include<stdio.h>
#include<stdlib.h>

    int main(int argc,char **argv){

	
	int var1,var2,var3;
	scanf("%d,%d,%d",&var1,&var2,&var3);

 int  *ptr_var1=&var3;
int	*ptr_var2=&var1;
int	*ptr_var3=&var2;
    
	printf("var1=%d,var2=%d,var3=%d",var1,var2,var3);
    printf("变量var1的地址为：%p\n 变量var2的地址为：%p\n  变量var3的地址为：%p\n",&var1,&var2,&var3);
	printf("ptr_var1=%d,ptr_var2=%d,ptr_var3=%d",*ptr_var1,*ptr_var2,*ptr_var3);

}
