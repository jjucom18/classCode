#include <stdio.h>
#include "createrandom.c"
#include"out_arr.c"





int main(int argc,char **argv){
        
	   int arr[20];
	   createrandom(arr);
	   out_arr(arr);
	   quickSort(arr,20);
	   out_arr(arr);
	   bubbleSort(arr,20);
	   out_arr(arr);
	   selectSort(arr,20);
	   out_arr(arr);
	   insertSort(arr,20);
	   out_arr(arr);






}
