#ifndef Sort_h
#define Sort_h

typedef struct
{
	KeyType key;
} DataType;
void InsertSort(DataType a[], int n) //直接插入排序
void BubbleSort(DataType a[], int n) //冒泡排序
void SelectSort(DataType a[], int n) //简单选择排序
void QuickSort(DataType a[], int low,int high) //快速排序
void ShellSort(DataType a[], int n,int d[],int numOfD) //希尔排序

#endif
