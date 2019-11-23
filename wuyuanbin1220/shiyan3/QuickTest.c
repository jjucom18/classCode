#include"sort.h"

int main(int argc, char **argv){
	
	int i;
	srand(time(NULL));
	datatype list[MAXSIZE];
	for (i = 1; i < MAXSIZE; ++i)
		list[i].data = rand()%100;
	QuickSort(list,1,MAXSIZE);
	for (i = 1; i < MAXSIZE; ++i)
		printf("%d\t",list[i].data );
	printf("\n");

	return 0;
}