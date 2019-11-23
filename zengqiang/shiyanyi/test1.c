#include<stdio.h>
void main(int argc,char**argv){
int var1,var2,var3,a;
scanf("%d%d%d",&var1,&var2,&var3);
printf("var1=%d,var2=%d,var3=%d\n",var1,var2,var3);
int *ptrVar1=&var1;
int *ptrVar2=&var2;
int *ptrVar3=&var3;
  a      = ptrVar1;
 ptrVar2 = ptrVar3;
 ptrVar3 = a;
printf("%ls,%ls,%ls",ptrVar1,ptrVar2,ptrVar3);
}
	
