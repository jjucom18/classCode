#include "zjinsert.h"

void zjinsert(int arr[],int n)
{
	int i,j;
	for(i = 1;i < n;i++){
		if(arr[i] < arr[i - 1]){
			int tmp = arr[i];
			for(j = i - 1;j >= 0 && arr[j] > tmp;j--)
				arr[j+1] = arr[j];
				arr[j + 1] = tmp;
		}
	}

}
