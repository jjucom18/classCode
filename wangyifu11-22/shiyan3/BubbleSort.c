void bubbleSort(int line[], int lineNum, int *compareTime, int *moveTime)
{
	for (int i = lineNum - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (line[j + 1] < line[j])
			{
				int temp = line[j];
				line[j] = line[j + 1];
				line[j + 1] = temp;
				*moveTime += 3;
			}
			*compareTime += 1;
		}
	}
}
