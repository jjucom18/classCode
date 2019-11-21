#include "bublesort.h"

void bublesort(int arr[])
{
	for(int i = 0;i < 10 - 1 ;i++){
		for(int j = 0;j < 10 - i- 1 ;j++){
			//if((arr[i] > arr[i + 1]) &&(arr[i] = arr[i + 1]))
			if (arr[j] > arr[j + 1])
			{
				int tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
