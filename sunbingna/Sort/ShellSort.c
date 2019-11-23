#include"Sort.h"

void ShellSort(DataType *R)
{
	int i,j,k,h,tem;
//	R=Random_Numble();
	for(h = MaxSize/2;h>=1;h =h/2)
	{
		for(i=h;i<MaxSize;i++)
			{
				tem = R[i];
				for(j = i-h;(j>=0)&&(R[j]>tem);j=j-h)
					R[j+h] = R[j];
				R[j+h] = tem;
			}

	}
	for(i=0;i<MaxSize;i++)
	printf("%d\t",R[i]);
	printf("\n");

}
