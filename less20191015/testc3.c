#include <stdio.h>

void fun2(){
	int f2_var1 = 30;
	int f2_var2 = 45;

	printf("f2_Var1: %d and %p\n", f2_var1, &f2_var1);
	printf("f2_Var2: %d and %p\n", f2_var2, &f2_var2);

	return;
}

void fun1(int mVar){
	printf("mVar: %d and %p\n", mVar, &mVar);

	fun2();
	printf("call fun2() finished!\n");

	return;
} 

typedef void (*ptrFun2)();
typedef void (*ptrFun1)(int);

int main(int argc, char **argv)
{
	int varM =99;
	fun2();
	ptrFun2 pFun2 = fun2;
	pFun2();
	printf("fun2(): %p\n", pFun2);

	ptrFun1 pFun1 = fun1;
	pFun1(varM);
	printf("call fun1(): ");
	fun1(varM);
	printf("fun1(): %p\n", pFun1);

	return 0;
}
