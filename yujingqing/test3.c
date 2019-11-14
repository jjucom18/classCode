#include<stdio.h>
#include<stdlib.h>
int main (int argv,char **argc)
{
	int a;int b;
     int *ptr_arr=(int*)malloc(sizeof(a)) ;
	  ptr_arr=&a;
	scanf("%d,%d",&a,&b);
	printf("a=%d\n",a);
	a=a+b;
	printf("%p\n",ptr_arr); 
        printf("%d",a);

   return 0;
 }
