#include"reporte3.h"

void InsertSort(int arr[],int n){
	int i,j;
	int compare = 0;
	int move = 0;
	for (i = 2; i < n; ++i){
		compare++;
		if (arr[i] < arr[i-1]){
			arr[0] = arr[i];
			compare++;
			for (j = i-1; arr[0] < arr[j]; --j){
				
				move++;
				arr[j+1] = arr[j];
			}
			arr[j+1] = arr[0];
		}
	}
	printf("关键字比较次数为%d\n",compare);
	printf("关键字移动次数为%d\n",move );
	return;
}

void bubbleSort(int arr[],int n){
	int tmp;
	int i,j;
	int compare = 0;
	int move = 0;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n-i; ++j){
			compare++;
			if (arr[j]> arr[j+1]){
				
				move++;
				tmp = arr[j];
				arr[j]= arr[j+1];
				arr[j+1] = tmp;
			}
		}
		printf("关键字比较次数为%d\n",compare);
		printf("关键字移动次数为%d\n",move );
		return;
}
void SelectSort(int arr[],int n){
	int i,j;
	int tmp;
	int compare = 0;
	int move = 0;
	for (i = 1; i < n; ++i){
		tmp = i;
		for (j = i+1; j < n; ++j){
			compare++;
			if (arr[j] < arr[tmp]){
				tmp = j;
			}
			compare++;
			if (i != tmp){
				move++;
				arr[0] = arr[tmp];
				arr[tmp] =arr[i];
				arr[i] =arr[0];
			}
		}
	}
	printf("关键字比较次数为%d\n",compare);
	printf("关键字移动次数为%d\n",move );
	return;

}

int Partition(int arr[],int low, int high){

	arr[0] = arr[low];
	while(low < high){
		while(low < high && arr[high] >= arr[0])
			high--;
		if(low < high){
		arr[low] = arr[high];
			low++;
		}
		while(low < high && arr[low] < arr[0])
			low++;
		if(low < high){
		arr[high] = arr[low];
			high--;
		}
		arr[low] = arr[0];
		
	}
	return low;
}
void QuickSort(int arr[],int s,int t){
	int i;
	if (s<t)
	{
		i = Partition(arr,s,t);
		QuickSort(arr,s,i-1);
		QuickSort(arr,i+1,t);
	}
	return;
}