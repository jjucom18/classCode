#include <stdio.h>
void swap(int *ptr_var1,int *ptr_var2,int *ptr_var3)
{
	int temp; 
    /*
	temp = *ptr_var1;
	*ptr_var1 = *ptr_var2;
	*ptr_var2 = temp;
    temp = *ptr_var2;
    *ptr_var2 = *ptr_var3;
    *ptr_var3 = temp;
    temp = *ptr_var3;
    *ptr_var3 = *ptr_var1;
    *ptr_var1 = temp; 
    */
    temp = *ptr_var2;
    *ptr_var2 = *ptr_var1;
    *ptr_var1 = *ptr_var3;
    *ptr_var3 = temp;

    return;
}
