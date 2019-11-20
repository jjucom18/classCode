#include "BubbleSort.c"
#include "FastSort.c"
#include "SimpleSort.c"
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
          FastSort(arr,10);
          out_arr(arr);
          SimpleSort(arr,10);
          out_arr(arr);
          insertSort(arr,10);
          out_arr(arr);
          
          return 0;
          
 }
