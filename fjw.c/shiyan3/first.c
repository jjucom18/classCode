#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define random_1(a, b) ((rand()%(b - a)) + a)
#define random_2(a, b) ((rand()%(b - a + 1)) + a)

int main(int argc, char **argv)
{
	srand((int)time(NULL));
	int arr[10];
	for(int i = 0; i < 10; i++){
		arr[i] = random_1(1,20);
	}

	for(int i = 0; i < 10; i++){
		printf("%d\t", arr[i]);
	}
	return 0;
}
