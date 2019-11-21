#include<stdio.h>
#include<stdio.h>

void insertSort(int arr[], int n)
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

void printArray(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void main()
{
    int arr[10] = {2,5,6,4,3,7,9,8,1,0};
    printArray(arr, 10);
    insertSort(arr, 10);
    printArray(arr, 10);
    return;
}
