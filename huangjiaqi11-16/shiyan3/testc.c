#include "createnumber.c"
#include"out_arr.c"
#include "allsort.c"




int main(int argc,char **argv){
        
	   int arr[10];
	   createrandom(arr);
	   printf("输出随机数\n");
	   out_arr(arr);
	   printf("希尔排序\n");
	   shellSort(arr,10);
	   out_arr(arr);
	   printf("冒泡排序\n");
	   bubbleSort(arr,10);
	   out_arr(arr);
	   printf("选择排序\n");
	   selectSort(arr,10);
	   out_arr(arr);
	   printf("直接插入排序\n");
	   insertSort(arr,10);
	   out_arr(arr);






}
