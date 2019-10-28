#include <stdio.h>

int main(int argc, char **argv)
{
	int arr[] = {3, 8, 9, 12, 14, 78, 35};
	int arrSize = sizeof(arr)/sizeof(arr[0]);

	for(int i = 0; i < arrSize; i++){
		printf("%d\t", arr[i]);
		printf("%p\t", &arr[i]);
		printf("\n");
	}
	printf("\n");

	return 0;
}
