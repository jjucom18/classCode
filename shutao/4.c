#include<stdio.h>

#include<stdlib.h>



const int c_var1 = 4;

int var1;



void main()

{

	int *ptr_var1 = (int *)malloc(sizeof(int));



	ptr_var1 = &var1;



	scanf("%d",&var1);



	int *ptr_c_var1 = (int *)malloc(sizeof(int));





	ptr_c_var1 = &c_var1;



	var1 +=*ptr_c_var1;

	

	ptr_c_var1=&var1;





                           }
