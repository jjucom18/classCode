#include<stdio.h>//shiyansi(1)
void main()
  void Ptr1(int var1)
{
	int *ptr_var1;
	ptr_var1 =&var1;
    scanf("%d\n",&var1);
	var1++;
	scanf("%d\n",&var1);
	(*ptr_var1)++;
	scanf("%d\n",&var1);
	return;
}

  void  Ptr2(int var1,const int cvar1)
{
	const int *ptr_cvar1;
	ptr_cvar1 = &var1;
	scanf("%d,%d\n",&var1,&cvar1);
scanf("ptr_cvar1=%p\n",&ptr_cvar1);
	ptr_cvar1= &cvar1;
scanf("%p\n",&ptr_cvar1);
return;
}
    void Ptr3(int var1,const int var2)

{

     int  *const ptr_var1 =&var1;
     int  *const ptr_var2 =&var2;
	 scanf("%d,%d\n",&var1,&var2);
	 ( *ptr_var1)++;
	 ( *ptr_var2)++;
	 scanf("%d,%d\n",&var1,&var2);
	 return ;
	
} 
  void Ptr4(const int cvar1)

{

	const int *const cptr_cvar1 = &cvar1;
	return ;
}

