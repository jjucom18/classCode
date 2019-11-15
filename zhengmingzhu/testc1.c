#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
 
	int var1,var2,var3;
	int temp;
	int *ptr_var1=&var1;
	int *ptr_var2=&var2;
	int *ptr_var3=&var3;
        scanf("%d,%d,%d",&var1,&var2,&var3);
	printf("var1: %d &var1 : %p\n ",var1 ,&var1);
	printf("var2: %d &var2 : %p\n ",var2 ,&var2);
	printf("var3: %d &var3 : %p\n ",var3 ,&var3);

	temp = *ptr_var1; *ptr_var1 = *ptr_var2; *ptr_var2 = *ptr_var3;
	*ptr_var3=temp;
        printf("var1: %d &var1 : %p\n",var1, &var1);
        printf("var2: %d &var2 : %p\n",var2, &var2);
        printf("var3: %d &var3 : %p\n",var3, &var3);


	return 0;
}
       

















//#include<stdlib.h>
//
//int main(int argc,char **argv)
//{
//	int *ptr_arr
//	int *ptr_arr=(int*)malloc(sizeof(int));
//
//
//	return 0;
//}
