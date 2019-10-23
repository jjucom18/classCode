#include <stdio.h>

void bubbleSort(int arr[], int arrSize){
	int tmp = 0;
	int swap = 1;
	while(swap){
		swap = 0;
		for(int i = 0; i < (arrSize -1); i++){
			if(arr[i] > arr[i + 1]){
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swap = 1;
			}
		}
	}

	return;
}

void outArr(int arr[], int arrSize){
	for(int i = 0; i < arrSize; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");

	return;
}

void insertSort(int arr[], int arrSize){
	for(int i = 1; i < arrSize; i++){
		if(arr[i] < arr[i - 1]){
			int j = 0;
			int tmp = arr[i];
			for(j = i - 1; j >= 0 && tmp < arr[j]; j--){
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = tmp;
		}
	}

	return;
}

void binaryInsertSort(int arr[], int arrSize){
	int tmp = 0;
	int i = 0;
	int j = 0;
	int low = 0;
	int high = 0;
	for(i = 0; i < arrSize; i++){
		tmp = arr[i];
		low = 0;
		high = i - 1;
		while(low <= high){
			int mid = (low + high)/2;
			if(tmp < arr[mid]){
				high = high - 1;
			}else{
				low = low + 1;
			}
		}
		for(j = i - 1; j >= low; j--){
			arr[j + 1] = arr[j];
		}
		arr[low] = tmp;
	}
	return;
}

void selectSort(int arr[], int arrSize){
	for(int i = 0; i < arrSize; i++){
		int index = i;
		for(int j = i + 1; j < arrSize; j++){
			if(arr[j] < arr[index]){
				index = j;
			}
		}
		if(index != i){
			int tmp = arr[index];
			arr[index] = arr[i];
			arr[i] = tmp;
		}
	}

	return;
}

int partition(int arr[], int low, int high){
	int i = low;
	int j = high;
	int tmp = arr[low];
	while(i < j){
		while(i < j && arr[j] >= tmp){
			j--;
		}
		if(i < j){
			arr[i] = arr[j];
			i++;
			while(i < j && arr[i] <= tmp){
				i++;
			}
			if(i < j){
				arr[j] = arr[i];
				j--;
			}
		}
	}
	arr[i] = tmp;

	return i;
}

void quickSort(int arr[], int left, int right){
	if(left < right){
		int tmp = partition(arr, left, right);
		quickSort(arr, left, tmp - 1);
		quickSort(arr, tmp + 1, right);
	}

	return;
}

int main(int argc, char **argv)
{
	int arr[] = {42, 93, 64, 15, 26, 57, 48, 79, 80};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	outArr(arr, arrSize);

	//bubbleSort(arr, arrSize);
//	insertSort(arr, arrSize);
//	binaryInsertSort(arr, arrSize);
//	selectSort(arr, arrSize);
	quickSort(arr, 0, arrSize - 1);
	outArr(arr, arrSize);

	return 0;
}
