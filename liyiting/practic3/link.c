#include "link.h"

void outArr(int arr[],int n);{
	for(int i = 0;i < n; i++)
		printf("%d\t",arr[i]);
			printf("\n");
			return;
			}


void insertSort(int arr[], int n);{
	for(int = 2; i<n ;i++){
		if(arr[i] < arr[i-1]){
			arr[0] = arr[i];
			int j ;
			for(j = i-1;arr[0]<arr[j];j--)
				arr[j+1] = arr[j];
			arr[j+1] =arr[0];
		}
}


void bubbleSort(int arr[], int n);{
	int tmp = 0;
	for(int i = 1; i < n; i++){
		for(int j = 0;j < n - i; j++){
			if(arr[j]>arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				}
				}
				}
				outArr( arr , n );
				return;
				}


void selectSort(int arr[], int n);{
      int i,j,k, tmp = 0;
      for(i = 0; i < n-1;i++){
          tmp = arr[i];
	  k = i;
	  for (j=i+1;j<n;j++){
	  if(arr[j]<arr[k])
		k=j;
	     arr[k] = arr[i];
	     arr[i] = tmp;
	  }
      }
	outArr( arr , n );
	return;
}



void shellkSort(int arr[], int n);
{
	int i,j,k,h;
	k = n/2;
	while(k>0){
		for(i = k ; i < n; i++){
			h=arr[i];
			for(j=i;j>=k;j-=k){
				if(h < arr[j-k])
					arr[j] =arr[j-k];
				else break;}
		}
		arr[j] =h;
	}k =k /2;}
	outArr( arr , n );
	return;
	}

