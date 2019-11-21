#ifndef SORT_H_
#define SORT_H_

#define ARRAY_LEN 1000        //    数组长度
#define MIN 1                 //    数组的最小值
#define MAX 1000              //    数组的最大值

int Comparisons_num;          //    比较次数
int Mobile_num;               //    移动次数

void Create_data(int *a, int n, int min, int max);                            //    建立伪随机
void Copy_array(int *tar, int *arr, int len);                                 //    复制数组
void Swap_element(int *a, int *b);                                            //    交换元素

void Insert_sort(int *arr, int len);                                          //    #1 直接插入排序 
void Shell_sort(int *arr, int len);                                           //    #2 希尔排序
void Bubble_sort(int *arr, int len);                                          //    #3 冒泡排序
int Division(int *a, int left, int right);                                    //    分隔过程（快速排序）
void Quick_sort(int *arr, int left, int right, int count);                    //    #4 快速排序（left和count初始值为0，right初始值为数组长度 - 1）    
void Select_sort(int *arr, int len);                                          //    #5 选择排序
void Heap_adjust(int arr[], int i, int len);                                  //    构成堆过程 (堆排序)
void Heap_sort(int arr[], int len);                                           //    #6 堆排序
void Merge(int arr[], int target[], int start, int mid, int end);             //    归并过程(归并排序)
void Merge_sort(int arr[], int target[], int start, int end, int count);      //    #7 归并排序（start和count初始值为0，end初始值为数组长度 - 1）

void Print_sort_positive(int *arr, int len);                                  //    正序输出
void Print_sort_negative(int *arr, int len);                                  //    逆序输出
void Print_mob_com();                                                         //    显示移动次数和比较次数

#endif          
