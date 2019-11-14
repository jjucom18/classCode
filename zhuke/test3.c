#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
	int Size;
	printf("piease input a space size:\n");
	int *ptr_arr=(int *)malloc(sizeof(int)*Size);
	scanf("%d",&Size);
	ptr_arr = &Size;
	printf("The original size is %d\n",Size);
	printf("The original address is %p\n",&Size);
	return 0;
}
