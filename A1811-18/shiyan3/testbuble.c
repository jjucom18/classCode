#include "bublesort.c"
#include "creatrandom.c"
#include "out_arr.c"
int main(int agrc,char **argv)
{
	int arr[10];
	createrandom(arr);
	bublesort(arr);
	out_arr(arr);

	return 0;
}
