#include<stdio.h>
#include<stdlib.h>


void bubbleSort(int arr[], int n)
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
    bubbleSort(arr, 10);
    printArray(arr, 10);
    return;
}
