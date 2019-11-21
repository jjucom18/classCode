#include "jsxuanzesort.h"

void jdxuanzesort(int arr[],int n)
{
	int i,j,k,tmp;
	for(i = 0;i < n - 1;i++){
		k = i;
		for(j = i + 1;j < n;j++){
			if(arr[j] < arr[k])
				k = j;
		}
		if(i != k){
			tmp = arr[i];
			arr[i] = arr[k];
			arr[k] = tmp;
		}
		}
	}
