#include<stdio.h>
#include<stdlib.h>
int main(int argc,int *argv)
{int _size;
	printf("pleas input a _size: ");
	int *ptr_arr=(int *)malloc(sizeof(int)*_size);
	scanf("%d",&_size);
	ptr_arr=&_size;
	printf("_size=%d\n",_size);
	printf("&_size=%p\n",&_size);
return 0;
}
