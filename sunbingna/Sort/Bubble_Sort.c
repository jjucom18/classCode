#include"Sort.h"

void Bubble_Sort(DataType *R)
{
	int i,j,tem;
	int swap;
	//R = Random_Numble();
	for(i=0;i<MaxSize;i++)
	{
		swap = 0;
		for(j=0;j<MaxSize-1-i;j++)
			if(R[j]>R[j+1])
			{
				tem = R[j+1];
				R[j+1] = R[j];
				R[j] = tem;
			swap = 1;	
			}
			if(swap == 0) break;
	}
	for(i=0;i<MaxSize;i++)
		printf("%d\t",R[i]);
	printf("\n");
}
