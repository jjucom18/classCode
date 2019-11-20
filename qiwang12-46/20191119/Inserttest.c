#include"reporte3.h"

#define random_1(a,b) ((rand()%(b - a)) + a)
#define random_2(a,b) ((rand()%(b - a + 1)) + a)
int main(int argc, char **argv)
{
	int i;
	srand((int)time(NULL));
	int arr[N];
	for(i = 1;i < N; i++){
		arr[i] = random_1(1,20);
	}
	InsertSort(arr,N);
	for (i = 1; i < N; ++i)
	{
		printf("%d\t",arr[i] );
	}
	printf("\n");

	return 0;
}