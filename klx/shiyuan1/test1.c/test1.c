#include<stdio.h>
void swap(int *p1,int *p2,int *p3){
	      int temp;
	      	  temp=*p1;
		  	 *p1=*p3;
			  	 *p3=*p2;
				  	 *p2=temp;
}
int  main (int argv,char **argc){
		int var1;int var2;int var3;
			int *ptr_var1; int  *ptr_var2 ; int *ptr_var3;
				  ptr_var1=&var1;
				    ptr_var2=&var2;
				      ptr_var3=&var3; 
				       printf("输入3个数据:\n");                                 			       			                                                                 scanf("%d,%d,%d",&var1,&var2,&var3);
				        printf("%p,%p,%p\n",ptr_var1,ptr_var2,ptr_var3);
					swap(ptr_var1,ptr_var2,ptr_var3); 
					printf("%d,%d,%d\n",*ptr_var1,*ptr_var2,*ptr_var3);
					return 0;

} 
