#include<stdio.h>
#include<stdlib.h>


void vapointer(int var) 
{
  int *ptr_var1;
  ptr_var1 = &var;
  *ptr_var1 = *ptr_var1+1;
  var = var+1;
  printf("指针自增和变量加1后的值:\n") ;
  printf("%d\n",*ptr_var1) ;
} 

void pointertoconst(int var,int const varc) 
{
  int const *ptr_varc1 = &var;
  var += 1;
  printf("\n指向常量的指针指向一个变量并自增后的值:\n") ;
  printf("%d\n",*ptr_varc1) ;
  ptr_varc1 = &varc;
  printf("指向常量的指针指向常量后的值:\n") ;
  printf("%d\n",*ptr_varc1) ;
} 


void cpointertova(int var,int const varc) 
{
   int *const cptr_var1 = &var;
   //int *const cptr_var2 = &varc;
   *cptr_var1 = var+1;
    printf("\n常量指针指向的变量加1:\n") ;
    printf("%d\n",*cptr_var1) ;
    printf("常量指针不能修改，指向的常量不能修改\n") ;
		} 
		
void cpointertoc(int const varc) 
{
    const int * const cptr_cvar1 = &varc;
    printf("\n指向常量的常量指针，指针和常量都不可修改\n") ;
		} 
		
void main() 
{
  int var1,var2;
  printf("请输入一个变量值和一个常量值:\n") ;
  scanf("%d%d",&var1,&var2) ;
  int const varc1 = var2;
 vapointer(var1) ;
  pointertoconst(var1,varc1) ;
  cpointertova(var1,varc1) ;
  cpointertoc(varc1);}  
