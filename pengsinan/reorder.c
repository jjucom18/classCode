#include "reorder.h"
#include<stdio.h>

void Shellsort(int datatype R[] ,int n ,int d[] ,int t){
	int i ,j ,k ,h ;
	for(k = 0 ;k < t ;k ++){
		h = d[k];
		for(i = h+1 ; i <= n ; i ++)
			if(R[i] < R[i-h]){
				R[0] = R[i];
				for(j = i - h ;j > 0 && R[0] < R[j] ; j = j-h)
					R[j-h] = R[j];
					R[j+h] = R[0];
			}
	}
}

void Bubblesort(int arr [] ,int arrsize){
	int i , j;
	int swap;
	for(j = 1; j <= arrsize-i; j++){
		if(arr[j] > arr[j+1]){
			arr[0] = arr [j+1];
			arr[j+1] = arr[j];
			arr[j] = arr[0];
			swap = 1;
		}
	if(swap == 0)break;
	} 
}
void Quick_sort(int datatype Q[] ,int s ,int y){
	if(s<t){
		i = Partition(Q ,s , t);
		Quick_sort(Q ,s ,t);
	}
}

void Select_sort(datatype S[] ,int n){
	for(i = 1 ; i < n ;i ++)
	{
		k = i;
		for(j = i + 1 ;j <= n ;j ++)
			if(S[j] < S[k])
				k = j;
		if(i != k){
			S[0] = S[k];
			S[k] = S[i];
			S[i] = S[0];
		}
	}
}

/*return;*/
