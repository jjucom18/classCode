#include <stdio.h>

typedef struct __str{
	char ch1;
	char ch2;
	int in1;
	int in2;
} Str;

int main(int argc, char **argv)
{
	Str str1;
	str1.ch1 = 'a';
	str1.ch2 = 'c';
	str1.in1 = 65;
	str1.in2 = 66;

	printf("&str1: %p\n", &str1);
	printf("str1.ch1: %c and %p\n", str1.ch1, &str1.ch1);
	printf("str1.ch2: %c and %p\n", str1.ch2, &str1.ch2);
	printf("str1.in1: %c and %p\n", str1.in1, &str1.in1);
	printf("str1.in2: %c and %p\n", str1.in2, &str1.in2);
	
	printf("Str size: %d\n", sizeof(Str));

	return 0;
}
