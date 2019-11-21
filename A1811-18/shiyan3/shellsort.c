
#include <stdio.h>
#include <stdlib.h>
void shellsort(int arr[],int n);
void shellsort(int arr[],int n)
{
	int i,j,elem;
	int k = n/2;
	while(k >= 1){
		for(i = k;i < n;i++){
			elem = arr[i];
			for(j = i;j >= k;j -=k){
				if(elem < arr[j - k]){
					arr[j] = arr[j- k ];
				}
				else{
					break;
				}
			}
			arr[j] = elem;
		}
		k = k/2;
	}

}
