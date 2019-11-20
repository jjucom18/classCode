#include"test4.h"

int main(int argc,char **argv)
{
	int arr[]={12,76,56,45,43,23,14,25};
	int size=sizeof(arr)/sizeof(int);
	printf("Sort before:\n");
	for(int i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");

	printf("Sort after:\n");
	InsertSort(arr,size);
	for(int i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");

	return 0;
}
