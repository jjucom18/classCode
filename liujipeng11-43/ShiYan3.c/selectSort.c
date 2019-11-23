#include<stdio.h>
#include<stdlib.h>

void selectSort(int arr[], int n)
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

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    int arr[10] = {2,5,6,4,3,7,9,8,1,0};
    printArray(arr, 10);
    selectSort(arr, 10);
    printArray(arr, 10);
    return;
}
