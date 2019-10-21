#include "bubbleSort.h"

void bubbleSort(int arr[], int arrSize){
	/*int flag;
	for(int i = 1; i < arrSize; i++){
		flag = 0;
		for(int j = i; j < arrSize - 1; j++){
			if(arr[j] > arr[j + 1]){
				arr[0] = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = arr[0];
				flag = 1;
			}
			if(flag == 0){
				break;
			}
		}
	}

	return;
	*/

	int tmp;
	for(int i = 0; i < arrSize; i++){
		for(int j = 0; j < arrSize - i; j++){
			if(arr[j] > arr[ j + 1]){
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	return;
}
