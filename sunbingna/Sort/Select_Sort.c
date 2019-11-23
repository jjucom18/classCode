#include"Sort.h"

void Select_Sort(DataType *R)
{
	int i,j,tem;
	for(i=0;i<MaxSize;i++)
	{
		int k=i;
		for(j=i+1;j<=MaxSize;j++)
			if(R[j]<R[k])
				k=j;
		if(i!=k)
		{
			tem = R[k];
			R[k] = R[i];
			R[i] = tem;
		}
	}
	for(i=0;i<MaxSize;i++)
	printf("%d\t",R[i]);
	printf("\n");
}

