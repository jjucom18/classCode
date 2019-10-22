#include "selectSort.h"

void selectSort(int arr[], int arrSize){
	int tmp = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	for(i = 0; i < arrSize - 1; i++){
		tmp = arr[i];
		k = i;
		for(j = i + 1; j < arrSize; j++){
			if(arr[j] < tmp){
				tmp = arr[j];
				k = j;
			}
			arr[k] = arr[i];
			arr[i] = tmp;
		}
	}

	outArr(arr, arrSize);

	return;
}
