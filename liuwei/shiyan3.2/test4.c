#include"test4.h"

void InsertSort(int arr[],int size){
	for(int i=1;i<size;i++){
		if(arr[i]<arr[i-1]){
			int last=i-1;
			int tmp=arr[i];
			while(last>=0&&tmp<arr[last]){
				arr[last+1]=arr[last];
				last--;
			}
			arr[last+1]=tmp;
		}
	}
}
