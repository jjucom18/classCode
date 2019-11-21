#include<stdio.h>
#include<stdio.h>

void insertSort(int line[], int lineNum, int *compareTime, int *moveTime)
{
	for (int i = 1; i < lineNum; i++)
	{
		int temp = line[i];
		int j = 0;
		for (j = i - 1; j >= 0 && temp < line[j]; j--)
		{
			line[j + 1] = line[j];
			*compareTime += 1;
			*moveTime += 1;
		}
		j++;
		line[j] = temp;
		*moveTime += 1;
	}

}
