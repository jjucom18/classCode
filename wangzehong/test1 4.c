#include<stdio.h>

void main(){

	int var1;int*ptrvar1=&var1;

	scanf("%d",&var1);

	var1++;

	printf("%d\n",var1);

	scanf("%d",ptrvar1);

	printf("%d",*(ptrvar1++));
}
