#include<stdio.h>
#include<stdlib.h>

void fastSort(int line[], int left, int right, int *compareTime, int *moveTime)
{
	if (right <= left)
	{
		*compareTime += 1;
		return;
	}
	int i = left;
	int j = right;
	int key = line[left];

	for (; i < j;)
	{
		for (; i < j && key <= line[j];)
		{
			j--;
			*compareTime += 1;
		}
		line[i] = line[j];
		*moveTime += 1;
		for (;i < j && line[i] <= key;)
		{
			i++;
			*compareTime += 1;
		}
		line[j] = line[i];
		*moveTime += 1;
		
	}
	line[i] = key;
	fastSort(line, left, i - 1, compareTime, moveTime);
	fastSort(line, i + 1, right, compareTime, moveTime);
}
