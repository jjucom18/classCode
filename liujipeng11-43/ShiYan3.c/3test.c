#include "BubbleSort.c"
#include "selectSort.c"
#include "shellSort.c"
#include "insertSort.c"
#include "creatrandom.c"
#include "out_arr.c"
int main(int argc, char **argv)
{  
          int arr[10];
          createrandom(arr);
          out_arr(arr);
          BubbleSort(arr,10);
          out_arr(arr);
          selectSort(arr,10);
          out_arr(arr);
          shellSort(arr,10);
          out_arr(arr);
          insertSort(arr,10);
          out_arr(arr);
          
          return 0;
          
 }
