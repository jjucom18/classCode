#include"Sort.h"

int *Random_Numble()
{
	srand((int)time(NULL));
	DataType r[MaxSize];
	for (int i=0; i < MaxSize; i++)
	{
		r[i] = random_1(1,20);
	}
	for(int i=0; i < MaxSize; i++)
	{printf("%d\t",r[i]);}
	printf("\n");
	return r;
}
