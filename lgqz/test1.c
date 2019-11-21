
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//插入排序法
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

//冒泡排序法
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

//简单选择排序法
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

//快速排序法
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

void allSort(int line[], int compareTime[], int moveTime[], int N)
{


	//插入排序法
	insertSort((line + sizeof(int) * N * 0) , N, &compareTime[0], &moveTime[0]);
	//冒泡排序法
	bubbleSort((line + sizeof(int)* N * 1), N, &compareTime[1], &moveTime[1]);
	//选择排序法
	simpleSelectSort((line + sizeof(int)* N * 2), N, &compareTime[2], &moveTime[2]);
	//快速排序法
	fastSort((line + sizeof(int)* N * 3), 0, N - 1, &compareTime[3], &moveTime[3]);

	
	printf("插入排序法比较次数：%d，移动次数：%d\n", compareTime[0], moveTime[0]);
	printf("冒泡排序法比较次数：%d，移动次数：%d\n", compareTime[1], moveTime[1]);
	printf("选择排序法比较次数：%d，移动次数：%d\n", compareTime[2], moveTime[2]);
	printf("快速排序法比较次数：%d，移动次数：%d\n\n", compareTime[3], moveTime[3]);

	for (int i = 0; i < 4; i++)
	{
		compareTime[i] = 0;
		moveTime[i] = 0;
	}

}

int main()
{
	#define N 20
	int line[5][N] = { 0 };
	int compareTime[4] = { 0 };
	int moveTime[4] = { 0 };
	srand((int)time(NULL));
	//先产生并显示随机数
	printf("显示所有随机数：\n");
	for (int i = 0; i < N; i++)
	{
		line[0][i] = rand() % 100 + 1;
		printf("%d  ", line[0][i]);
		for (int j = 1; j < 5; j++)
		{
			line[j][i] = line[0][i];
		}
	}
	printf("\n\n");
	printf("随机排序情况下：\n");
	allSort(line, compareTime, moveTime, N);
	printf("已顺序排序情况下：\n");
	allSort(line, compareTime, moveTime, N);
	for (int i = 0; i < N / 2; i++)
	{
		int temp;
		for (int j = 0; j < 5; j++)
		{
			temp = line[j][i];
			line[j][i] = line[j][N - 1 - i];
			line[j][N - 1 - i] = temp;
		}
	}
	printf("已逆序排序情况下：\n");
	allSort(line, compareTime, moveTime, N);




	////插入排序法
	//insertSort(line[1], N, &compareTime[0], &moveTime[0]);
	////冒泡排序法
	//bubbleSort(line[2], N, &compareTime[1], &moveTime[1]);
	////选择排序法
	//simpleSelectSort(line[3], N, &compareTime[2], &moveTime[2]);
	////快速排序法
	//fastSort(line[4], 0, N - 1, &compareTime[3], &moveTime[3]);

	//printf("已顺序排序情况下：\n");
	//printf("插入排序法比较次数：%d，移动次数：%d\n", compareTime[0], moveTime[0]);
	//printf("冒泡排序法比较次数：%d，移动次数：%d\n", compareTime[1], moveTime[1]);
	//printf("选择排序法比较次数：%d，移动次数：%d\n", compareTime[2], moveTime[2]);
	//printf("快速排序法比较次数：%d，移动次数：%d\n", compareTime[3], moveTime[3]);



	getchar();

	return 0;
}
