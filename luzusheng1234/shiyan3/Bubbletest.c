#include "Sorting.h"

int main(int argc, char **argv){
	int i;
	srand((int)time(NULL));
	datatype R[MaxNum];
	for (i = 1; i < MaxNum; ++i){
		R[i].data = random_1(1,100);
	}
	Bubble_Sort(R,MaxNum);
	for (i = 1; i < MaxNum; ++i)
	{
		printf("%d\t",R[i].data);
	}
		
	
	return 0;
}