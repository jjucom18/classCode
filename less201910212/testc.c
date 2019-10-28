#include "insertSort.h"
//#include "bubbleSort.h"

void displayArr(DataType arr[], int arrSize){
	for(int i = 1; i < arrSize; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");

	return;
}

int main(int argc, char **argv)
{
	DataType arr[] = {0, 999, 92, 12, 45, 36, 87, 75, 66, 52, 29};
	int arrSize = sizeof(arr)/sizeof(int);

	displayArr(arr, arrSize);
	insertSort(arr, arrSize);
	//bubbleSort(arr, arrSize);
	displayArr(arr, arrSize);

	return 0;
}
