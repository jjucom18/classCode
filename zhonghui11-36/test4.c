#include<stdio.h>
int main(){
int var1;
int *ptrvar1;
ptrvar1=&var1;
scanf("%d",&var1);
var1++;

printf("%d\n",var1);

printf("%d\n",*(ptrvar1++));
}
