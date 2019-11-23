#include"Sort.h"

void D_inSort(DataType *R)
{
	int i,j;
	int tem;
	//R=Random_Numble();
	//R[0]=1;R[1]=4;R[2]=3;R[3]=9;R[4]=8;
	for (i=1;i<=MaxSize;i++)
	{
		tem = R[i];
		j=i-1;

		while(j>=0 && tem<r[j])
		{
			R[j+1] = R[j];
			j--;
		}
		R[j+1] = tem;
	}
	for(int i=0;i<MaxSize;i++)
	printf("%d\t",R[i]);
	printf("\n");
}
