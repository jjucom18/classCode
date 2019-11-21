#include <stdio.h>
#include "testc.c"

int main(int argc,char **argv){
        
	   int arr[10];
	   createrandom(arr);
	   shellSort(arr,10);
	   out_arr(arr);
	   bubbleSort(arr,10);
	   out_arr(arr);
	   selectSort(arr,10);
	   out_arr(arr);
	   insertSort(arr,10);
	   out_arr(arr);

}
