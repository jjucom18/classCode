#include<stdio.h>
int swap(int *p,int *p1,int *p2){
      int temp;
	  temp=*p;
	  *p=*p2;
	  *p2=*p1;
	  *p1=temp;
}
int  main (int argv,char **argc){
	int var1;
	int var2;
	int var3;

int *ptr_var1;
int *ptr_var2;
int *ptr_var3;
  ptr_var1=&var1;
  ptr_var2=&var2;
  ptr_var3=&var3;
 printf("%p,%p,%p\n",ptr_var1,ptr_var2,ptr_var3); 
printf("please intput three datas:\n");
scanf("%d,%d,%d",&var1,&var2,&var3);
printf("利用swap函数使变量值转换\n");
swap(ptr_var1,ptr_var2,ptr_var3); 
printf("%d,%d,%d\n",var1,var2,var3);
return 0;
} 



