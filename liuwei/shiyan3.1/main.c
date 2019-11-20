#include"test3.h"

void outArr(int arr[],int arrsize){
	for(int i=0;i<arrsize;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return; }	

int main(int argc,char **argv){
	int arr[]={12,24,36,15,43,56,39,87,78};
	int arrsize=sizeof(arr)/sizeof(int);
        outArr(arr,arrsize);
	bubblesort(arr,arrsize);
	outArr(arr,arrsize);


	return 0;}
	

