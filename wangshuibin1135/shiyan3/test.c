#include "outarr.c"
#include "sort.c"
#include "createrandom.c"

int main(int argc,char **argv){

           int arr[10];
           createrandom(arr);
           outarr(arr);
           shellSort(arr,10);
           outarr(arr);
           bubbleSort(arr,10);
           outarr(arr);
           selectSort(arr,10);
           outarr(arr);
           insertSort(arr,10);
           outarr(arr);






}
