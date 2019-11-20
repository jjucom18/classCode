#include<stdio.h>
#include<stdlib.h>

void simpleSelectSort(int line[], int lineNum, int *compareTime, int *moveTime)
{
	for (int i = 0; i < lineNum - 1; i++)
	{
		int minPosition = i;
		for (int j = i; j < lineNum; j++)
		{
			if (line[j] < line[minPosition])
			{
				minPosition = j;
			}
			*compareTime += 1;
		}
		int temp = line[i];
		line[i] = line[minPosition];
		line[minPosition] = temp;
		*moveTime += 3;

	}


}
