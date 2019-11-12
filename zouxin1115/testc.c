#include<stdio.h> 
int main(int argc, char **argv){
	void swap(int *var1,int *var2,int *var3){
		int t;
		t = *var1;
		*var1 = *var2;
		*var2 = t;
	        t = *var2;
                *var2 = *var3;
                *var3 = t;
                t = *var3;
                *var3 = *var1;
                *var1 = t;
}
int var1,var2,var3;
int *ptr_var1,*ptr_var2,*ptr_var3;
scanf("%d,%d,%d",&var1,&var2,&var3);
ptr_var1 = &var1;
ptr_var2 = &var2;
ptr_var3 = &var3;
printf("Original value:\n");
printf(" var1 = %d\n, var2 = %d\n, var3 = %d\n",var1,var2,var3);
printf("\n");
printf("Address before swap:\n");
printf(" var1 = %p\n, var2 = %p\n, var3 = %p\n",&var1,&var2,&var3);
printf("\n");
swap(ptr_var1,ptr_var2,ptr_var3);
printf("value after swap:\n");
printf(" var1 = %d\n, var2 = %d\n, var3 = %d\n",var1,var2,var3);
return 0;
}
