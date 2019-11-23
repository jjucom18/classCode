#include "sort.h"
#include <stdio.h>

int main(void)
{
    int arr[ARRAY_LEN];
    int temp_arr[ARRAY_LEN];
    int target_arr[ARRAY_LEN];

    Create_data(arr, ARRAY_LEN, MIN, MAX);
    Copy_array(target_arr, arr, ARRAY_LEN);

    
    printf("排序前: \n");
    Print_sort_positive(target_arr, ARRAY_LEN);
    Bubble_sort(target_arr, ARRAY_LEN);

    printf("\n完全正序: \n");
    Print_sort_positive(target_arr, ARRAY_LEN);

    printf("\n完全逆序: \n");
    Print_sort_negative(target_arr, ARRAY_LEN);

    //　　开始进行七种排序比较
    Copy_array(target_arr, arr, ARRAY_LEN);
    Bubble_sort(target_arr, ARRAY_LEN);
    printf ("冒泡排序:\n");
    Print_mob_com();

    Copy_array(target_arr, arr, ARRAY_LEN);
    Quick_sort(target_arr, 0, ARRAY_LEN - 1, 0);
    printf ("快速排序:\n");
    Print_mob_com();

    Copy_array(target_arr, arr, ARRAY_LEN);
    Copy_array(temp_arr, arr, ARRAY_LEN);
    Merge_sort(temp_arr, target_arr, 0, ARRAY_LEN - 1, 0);
    printf ("归并排序:\n");
    Print_mob_com();
    
    Copy_array(target_arr, arr, ARRAY_LEN);
    Heap_sort(target_arr, ARRAY_LEN);
    printf ("堆排序:\n");
    Print_mob_com();
    
    Copy_array(target_arr, arr, ARRAY_LEN);
    Insert_sort(target_arr, ARRAY_LEN);
    printf ("直接插入排序:\n");
    Print_mob_com();

    Copy_array(target_arr, arr, ARRAY_LEN);
    Select_sort(target_arr, ARRAY_LEN);
    rintf ("选择排序:\n");
    Print_mob_com();

    Copy_array(target_arr, arr, ARRAY_LEN);
    Shell_sort(target_arr, ARRAY_LEN);
    printf ("希尔排序:\n");
    Print_mob_com();
    
    return 0;
}
