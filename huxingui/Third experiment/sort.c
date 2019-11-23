#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <string.h>

extern int Comparisons_num;       //    比较次数
extern int Mobile_num;            //    移动次数

//　　建立伪随机数组
void Create_data(int *a, int n, int min, int max)
{
    int flag;                    //　　避免取重复取值
    srand(time(NULL));

    if (n > max - min + 1)
        return 0;
    for (int i = 0, j = 0; i<n; i++)
    {
        do
        {
            a[i] = (max - min + 1) * rand() / (RAND_MAX + 1) + 1;
            flag = 0;
            for (j = 0; j < i; j++)
            {
                if (a[i] == a[j])
                    flag = 1;
            }
        } while (flag);
    }
}

//　　复制数组
void Copy_array(int *tar, int *arr, int len)
{
    int i;

    for (i = 0; i < len; i++)
        tar[i] = arr[i];
}

//　　交换元素
void Swap_element(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
    
    Mobile_num += 3;    //　　一次关键字交换计为3次移动
}
//    冒泡排序
void Bubble_sort(int *arr, int len)
{
    int i, j;
    int flag = 1;            //    标记循环过程是否进行过交换，如果为1则进行了交换    

    for (i = 0; i < len && flag; i++)
    {
        flag = 0;
        for (j = 1; j < len - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                Swap_element(arr + j, arr + j - 1);
                flag = 1;
            }
            Comparisons_num++;
        }
    }    
}
//　　分隔（快速排序）
int Division(int *a, int left, int right)
{
    int base = a[left];
    while (left < right)
    {
        while (left < right && base < a[right])
        {
            right--;
            Comparisons_num++;
        }

        a[left] = a[right];
        Mobile_num++;

        while (left < right && a[left] < base)
        {
            left++;
            Comparisons_num++;
        }

        a[right] = a[left];
        Mobile_num++;
    }

    a[left] = base;
    return left;
}

//　　快速排序    
//　　left 和 count初始值为0  right 初始值为数组长度 - 1
void Quick_sort(int *arr, int left, int right, int count)    
{
    int i;
    int count_temp = count + 1;

    if (left < right)
    {
        i = Division(arr, left, right);
        Quick_sort(arr, left, i - 1, count_temp);
        Quick_sort(arr, i + 1, right, count_temp);
    }
}
//    归并 (归并排序)
void Merge(int arr[], int target[], int start, int mid, int end)
{
    int i, j, k;

    for (i = mid + 1, j = start; start <= mid && i <= end; j++)
    {
        if (arr[start] < arr[i])
            target[j] = arr[start++];
        else
            target[j] = arr[i++];
        Mobile_num++;
        Comparisons_num++;
    }

    if (start <= mid)
    {
        for (k = 0; k <= mid - start; k++)
        {
            target[j + k] = arr[start + k];
            Mobile_num++;
        }
    }

    if (i <= end)
    {
        for (k = 0; k <= end - i; k++)
        {
            target[j + k] = arr[i + k];
            Mobile_num++;
        }
    }
}

//    归并排序
//    start 和 count初始值为0    end 初始值为数组长度 - 1
void Merge_sort(int arr[], int target[], int start, int end, int count)    
{
    int mid;
    int count_temp = count + 1;
    int * temp_arr = (int *)calloc(end + 1, sizeof(int));

    if (start == end)
    {
        target[start] = arr[start];
        Mobile_num++;
    }
    else
    {
        mid = (start + end) / 2;
        Merge_sort(arr, temp_arr, start, mid, count_temp);
        Merge_sort(arr, temp_arr, mid + 1, end, count_temp);
        Merge(temp_arr, target, start, mid, end, count_temp);
    }

    if (count == 0)
    {
        free(temp_arr);
    }
}
//    构成堆 (堆排序)
void Heap_adjust(int arr[], int parent, int len)
{
    int child;
    int temp;

    for (temp = arr[parent]; 2 * parent + 1 < len; parent = child)
    {
        child = 2 * parent + 1;

        if (child < len - 1 && arr[child + 1] > arr[child])
        {
            child++;
            Comparisons_num++;
        }

        Comparisons_num++;
        if (temp < arr[child])
        {
            Swap_element (arr + child, arr + parent);
        }
        else
            break;
    }
}
//    堆排序
void Heap_sort(int arr[], int len)
{
    int i;

    for (i = (len - 1) / 2; i >= 0; i--)
        Heap_adjust(arr, i, len);
    
    for (i = len - 1; i > 0; i--)
    {
        Swap_element(arr, arr + i);            //    每次将最大的数排在最后
        Heap_adjust(arr, 0, i);                //    重新构成堆，将最大的数放在第一位
    }
}
//    直接插入排序
void Insert_sort(int *arr, int len)
{
    int i, j;
    int tmp;            //    待排序的元素

    for (i = 0; i < len; i++)
    {
        tmp = arr[i];
        for (j = i - 1; j >= 0 && tmp < arr[j]; j--)
        {
            Swap_element(arr + j, arr + j + 1);　　　　// tmp < arr[j]，因此arr[j]向后移动
            Comparisons_num++;
        }
        arr[j + 1] = tmp;
    }  
}
//    选择排序
void Select_sort(int *arr, int len)
{
    int i, j;
    int tmp;　　//　　记录待排序元素的下标

    for (i = 0; i < len - 1; i++)
    {
        tmp = i;
        for (j = i + 1; j < len; j++)
        {
            if (arr[tmp] > arr[j])
                tmp = j;
            Comparisons_num++;
        }
        if (tmp != i)
            Swap_element(arr + tmp, arr + i);
    }
}
//    希尔排序
void Shell_sort(int *arr, int len)
{
    int i, j;
    int d = len / 2;
    int lookouts;                //    监视哨

    while (d >= 1)
    {
        for (i = d; i < len; i++)
        {
            lookouts = arr[i];
            for (j = i - d; j >= 0 && lookouts < arr[j]; j = j - d)
            {
                Swap_element(arr + j + d, arr + j);
                Comparisons_num++;
            }
            if (arr[j + d] != lookouts)
            {
                Swap_element(arr + j + d, &lookouts);
                Comparisons_num++;
            }
        }
        d /= 2;
    }
}
//    显示打印
//    正序输出
void Print_sort_positive(int *arr, int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if (i % 10 == 0 && i != 0)
            putchar('\n');
        printf("%3d ", arr[i]);
    }
    putchar('\n');
}

//    逆序输出
void Print_sort_negative(int *arr, int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if (i % 10 == 0 && i != 0)
            putchar('\n');
        printf("%3d ", arr[len - i - 1]);
    }
    putchar('\n');
}

//    显示移动次数和比较次数
void Print_mob_com()
{
    printf("移动次数：%d\n", Mobile_num);
    printf("比较次数：%d\n\n", Comparisons_num);
    //    初始化
    Mobile_num = Comparisons_num = 0;
}
