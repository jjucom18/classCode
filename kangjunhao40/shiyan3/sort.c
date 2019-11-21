#include "sort.h"
void SelectSort(int arr[], int n)//选择排序
{
    int i, j , X, tmp;
    for(i = 0; i < n-1; i++)
    {
        X = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[X] > arr[j])
            {
                X = j;
            }
        }
        if(X != i)
        {
            tmp = arr[i];
            arr[i] = arr[X];
            arr[X] = tmp;
        }
    }
}
void InsertSort(int arr[], int n)//直接插入排序
{
    int i, j, tmp;

    for(i = 1; i < n; i++)
    {
        for(j = i; j > 0; j--)
        {
            if(arr[j] < arr[j-1])
            {
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
            else
            {
                break;
            }
        }
    }

    return;
}
void ShellSort(int arr[], int n)//希尔排序
{
    int i, j, element;
    int k = n/2;

    while(k>=1)
    {
        for(i = k; i < n; i ++)
        {
            element = arr[i];
            for(j = i; j >= k; j-=k)
            {
                if(element < arr[j-k])
                {
                    arr[j] = arr[j-k];
                }
                else
                {
                    break;
                }
            }
            arr[j] = element;
        }
        k = k/2;
    }
}
void BubbleSort(int arr[], int n)//冒泡排序
{
        int i, j,tmp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 1; j < n -i; j++)
        {
            if(arr[j] < arr[j - 1])
            {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

