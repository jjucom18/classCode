#include "shellsort.c"
#include "out_arr.c"
#include "creatrandom.c"


int main (int argc,char **argv)
{
	int arr[10];
	createrandom(arr);
	shellsort(arr,10);
	out_arr(arr);


	return 0;
}
