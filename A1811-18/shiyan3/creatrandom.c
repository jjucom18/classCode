#include "creatrandom.h"

int createrandom(int arr[10])
{
	srand((int)time(NULL));
	//int arr[20];
	for(int i = 0;i < 10;i++){
		arr[i] = random_1(1,20);
	}
	for(int i = 0;i < 10;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return 0;
}
