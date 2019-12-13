#include<stdio.h>                                                                            
#include<malloc.h>
int main(int argv,char **argc)
{int var1,p;int const cvar1,var2;p=cvar1;
	int *ptr_var1=&var1;
	int const *ptr_cvar1=&cvar1;
	int const *const cptr_var=&cvar1;
printf("please  input your two  datas:");
scanf("%d,%d",&var1,&p);
(*ptr_var1)++;
printf("利用指针实现变量的自增\n");
printf("%d\n",var1);
ptr_cvar1=&var1;
var1=*ptr_var1+*ptr_cvar1;
printf("利用指向常量的指针实现变量的自增加\n");
printf("%d\n",var1);
printf("%p\n",ptr_cvar1);
ptr_cvar1++;
printf("指针值自增\n");
printf("%p\n",ptr_cvar1);
int *const cptr_var1=&var1;
(*cptr_var1)++;
    printf("使用指向变量的常量指针使变量自增\n");
    printf("%d\n",var1);
	printf("指向变量的常量指针的值不能被修改，但可以通过解引来修改变量的值\n");
	printf("指向变量的常量指针不能保存常量的地址\n");
    printf("指向常量的常量指针即不能改变指针的值，也不能通过解引指针改变变量的值\n");
return 0;
}
