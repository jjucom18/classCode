#include "bubbleSort.h"

void bubbleSort(int arr[], int arrSize){
	int tmp = 0;
	for(int i = 1; i < arrSize; i++){
		for(int j = 0; j < arrSize - i; j++){
			if(arr[j] > arr[j + 1]){
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	outArr(arr, arrSize);

	return;
}

