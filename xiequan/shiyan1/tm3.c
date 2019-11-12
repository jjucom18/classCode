#include<stdio.h>
#include<malloc.h>
int main(int argv,char **argc)
{int m=30,n=0,p=m+n,s;
	printf("%d,%p\n",p,&p);
printf("please input your data:");
scanf("%d",&n);
p=m+n;
printf("%d\n",p);
int *ptr_arr=(int*)malloc(p);
s= *ptr_arr;
return 0;

}

