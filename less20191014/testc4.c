#include <stdio.h>

void fun1(){
	int fun1_var1 = 3;
	int fun1_var2 = 6;

	return 0;
}

void fun2(int var1){
	int fun2_var1 = var1;
	int fun2_var2 = 5;

	fun1();

	return;
}

int main(int argc, char **argv)
{
	int tmp = 99;
	fun2(tmp);
	fun1();

	return 0;
}
