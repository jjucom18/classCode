#include<stdio.h>
#include<stdlib.h>

void shellSort(int arr[], int n)
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
    shellSort(arr, 10);
    printArray(arr, 10);
    return;
}
