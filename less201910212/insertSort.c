#include "insertSort.h"

/*void insertSort(int arr[], int arrSize){
	int tmp = 0;
	for(int i = 1; i < arrSize; i++){
		if(arr[i] < arr[i - 1]){
			tmp = arr[i];
			int j = 0;
			for(j = i - 1; tmp < arr[j] || j == 0; j--){
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = tmp;
		}
	}

	return;
}*/
void swap(int var1, int var2){
	int tmp = var1;
	var1 = var2;
	var2 = tmp;

	return;
}

void insertSort(DataType arr[], int arrSize){
	for(int i = 2; i < arrSize; i++){
		if(arr[i] < arr[i - 1]){
			arr[0] = arr[i];
			int j = 0;
			for(j = i - 1; arr[0] < arr[j]; j--){
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = arr[0];
		}
	}

	return;
}
