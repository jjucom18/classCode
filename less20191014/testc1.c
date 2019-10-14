#include <stdio.h>
#include <stdlib.h>

void outArr(int arr[], int arrSize){
	for(int i = 0; i < arrSize; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");

	return;
}

void outArrPtr(int *ptrArr, int arrSize){
	for(int i = 0; i < arrSize; i++){
		//printf("%d\t", ptrArr[i]);
		printf("%d\t", *(ptrArr + i));
	}
	printf("\n");

	return;
}

int main(int argc, char **argv)
{
	int arr[] = {21, 32, 68, 43, 59, 90, 81, 75};
	int arrSize = sizeof(arr)/sizeof(int);

	outArr(arr, arrSize);
	outArrPtr(arr, arrSize);

	return 0;
}
