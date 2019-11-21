#include"sort.h"

int main(int argc, char **argv){
	
	int i;
	srand(time(NULL));
	int list[MaxSize];
	for (i = 1; i < MaxSize; ++i)
		list[i] = rand()%100;
	Selectsort(list,MaxSize);
	for (i = 1; i < MaxSize; ++i)
		printf("%d\t",list[i] );
	printf("\n");

	return 0;
}
