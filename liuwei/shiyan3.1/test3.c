#include"test3.h"

void bubblesort(int arr[],int arrsize)
{
	int tmp=0;
	int swap=1;
	while(swap){
           swap=0;
           for(int i=0;i<(arrsize-1);i++)
	{
		if(arr[i]>arr[i+1]){
			tmp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=tmp;
			swap=1;
		}
	}

}
         return;
}	 
         


