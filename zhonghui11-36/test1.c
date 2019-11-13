#include<stdio.h>
int main(int argr,char **argv) {
int var1,var2,var3;
int *ptrvar1,*ptrvar2,*ptrvar3;
ptrvar1=&var1;
ptrvar2=&var2;
ptrvar3=&var3;
printf("请输入三个数");
scanf("%d,%d,%d",&var1,&var2,&var3);
printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
printf("%p,%p,%p\n", ptrvar1, ptrvar2, ptrvar3);
int *temp;
temp=ptrvar3;
ptrvar3=ptrvar2;
ptrvar2=ptrvar1;
ptrvar1=temp;
printf("var1=%d,var2=%d,var3=%d\n",*ptrvar1,*ptrvar2,*ptrvar3); 
} 
