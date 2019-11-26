#include <stdio.h>
#include "createrandom.c"
#include"out_arr.c"
#include "sort.c"




int main()
{

           int arr[10];
           createrandom(arr);
           out_arr(arr);
           insertSort(arr,10);
           out_arr(arr);
           bubbleSort(arr,10);
           out_arr(arr);
           shellSort(arr,10);
           out_arr(arr);
           selectSort(arr,10);
           out_arr(arr);
          
}
