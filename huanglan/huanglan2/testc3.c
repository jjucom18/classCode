#include  <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{int a=1,b=0,p=a+b,c;
int *ptr_arr=(int*)malloc(p);
	printf("初始值");
	printf("%d,%p\n",p,&p);
    printf("please input your data:\n");
	scanf("%d",&b);
    printf("%p\n",ptr_arr);
    p=a+b;
    printf("内存增加后的值\n");
    printf("%d\n",p);
    c=*ptr_arr;
	free(ptr_arr);
	return 0;
} 

