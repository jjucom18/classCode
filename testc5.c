#include <stdio.h>

void bubbleSort(int arr[], int arrSize){
	int tmp = 0;
	for(int i = 1; i < arrSize; i++){
		for(int j = i - 1; j < arrSize; j++){
			if(arr[j] > arr[j + 1]){
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	return;
}

void outPut(int arr[], int arrSize){
	for(int i = 0; i < arrSize; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	int arr[] = {2, 5, 7, 1, 8, 4};
	int arrSize = sizeof(arr)/sizeof(int);
	outPut(arr, arrSize);
	bubbleSort(arr, arrSize);
	outPut(arr, arrSize);

	return 0;
}
