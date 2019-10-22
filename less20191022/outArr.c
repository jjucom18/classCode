#include "outArr.h"

void outArr(int arr[], int arrSize){
	for(int i = 0; i < arrSize; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");

	return;
}
