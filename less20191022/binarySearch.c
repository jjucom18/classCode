#include "binarySearch.h"

void binarySearch(int arr[], int low, int high, int obj, int *result){
	while(low <= high){
		int middle = (low + high)/2;
		if(obj == arr[middle]){
			*result = middle;
		}else{
			if(obj > arr[middle]){
				low = middle + 1;
			}else{
				high = middle - 1;
			}
		}
	}
	*result = -1;

	return;
}
