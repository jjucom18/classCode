#include<stdio.h>
#include "sort_h"
#include<stdlib.h>

void selectSort(int arr[], int n) //选择排序
{
    int i, j , minValue, tmp;
    for(i = 0; i < n-1; i++)
    {
        minValue = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[minValue] > arr[j])
            {
                minValue = j;
            }
        }
        if(minValue != i)
        {
            tmp = arr[i];
            arr[i] = arr[minValue];
            arr[minValue] = tmp;
        }
    }
}


void bubbleSort(int arr[], int n)  //冒泡排序
{
    int i, j, tmp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 1; j < n; j++)
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


void insertSort(int arr[], int n)  //插入排序
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


void shellSort(int arr[], int n)  //希尔排序
{
    int i, j, elem;
    int k = n/2;

    while(k>=1)
    {
        for(i = k; i < n; i ++)
        {
            elem = arr[i];
            for(j = i; j >= k; j-=k)
            {
                if(elem < arr[j-k])
                {
                    arr[j] = arr[j-k];
                }
                else
                {
                    break;
                }
            }
            arr[j] = elem;
        }
        k = k/2;
    }
}
