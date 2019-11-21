#include "zjinsert.c"
#include "creatrandom.c"
#include "out_arr.c"
int main(int argc,char **argv)
{
	int arr[10];
	createrandom(arr);
	zjinsert(arr,10);
	out_arr(arr);


	return 0;
}
