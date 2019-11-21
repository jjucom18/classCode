#include "Sorting.h"

int main(int argc, char **argv){
	int i,n,t = 3;
	int D[MaxNum];
	srand((int)time(NULL));
	datatype R[MaxNum];
	for (i = 5; i >0 ; i-2)
	{	
		D[i] = i;
	}
	for (i = 1; i < MaxNum; ++i){
		R[i].data = random_1(1,100);
	}
	ShellSort(R,n,D,t);
	for (i = 1; i < MaxNum; ++i)
	{
		printf("%d\t",R[i].data);
	}
		
	
	return 0;
}