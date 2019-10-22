#include "bubbleSort.h"
//#include "selectSort.h"
#include "binarySearch.h"

int main(int argc, char **argv)
{
	int arr[] = {12, 93, 45, 67, 54, 87, 76, 31, 26};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
//	outArr(arr, arrSize);
	bubbleSort(arr, arrSize);
//	selectSort(arr, arrSize);
	printf("search in arr 22");
	int result = 0;

	binarySearch(arr,  0, arrSize - 1, 22, &result);
	if(result){
		printf("%d\n", result);
	}

	return 0;
}
