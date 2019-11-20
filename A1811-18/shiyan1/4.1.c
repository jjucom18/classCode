#include <stdio.h>
#include <stdlib.h>
void var () //变量自加改变值
{
	int a;
	int *ptr_var1;
	ptr_var1 = &a;
	printf("请输入变量的值：\n");
	scanf("%d",&a);
	printf("exchange before:%d\n",*ptr_var1);
	a++;
	printf("exchange after:%d\n",*ptr_var1);
	

}
void ptr () 
{
int a;
int *ptr_arr1;
ptr_arr1 = &a;
printf("请输入变量的值：\n");
scanf("%d",&a);
printf("exchange before :%d",*ptr_arr1);
*ptr_arr1 += *ptr_arr1;
printf("exchange after:%d",*ptr_arr1);

}
void const1var()
{
int const var1;
int const var2;
int *ptr_cvar1;
int *ptr_cvar2;
ptr_cvar1 = &var1;
ptr_cvar2 = &var2;
printf("请输入两个常量的值：\n");
scanf("%d%d",&var1,&var2);
printf("变量自加\n");
printf("exchange before :%d%d",*ptr_cvar1,*ptr_cvar2);
var1 += var1;
var2 += var2;
printf("exchange after:%d%d",*ptr_cvar1,*ptr_cvar2);

}
void constptr()
{
int const var1;
int const var2;
int *ptr_cvar1;
int *ptr_cvar2;
ptr_cvar1 = &var1;
ptr_cvar2 = &var2;
printf("指针自加\n");
printf("exchange before:%d%d",*ptr_cvar1,*ptr_cvar2);
*ptr_cvar1 += *ptr_cvar1;
*ptr_cvar2 += *ptr_cvar2;
printf("exchange after:%d%d",*ptr_cvar1,*ptr_cvar2);
} 
