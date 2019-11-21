#include <stdio.h>
#include <stdlib.h>
#include "DS0.h"
#include "DS1.h"
#include "DS2.h"

void Copy_L(SqList &Lin, SqList &Lo, int Length){
     int i;
     char c;
        for(i=0; i<Length; i++){
        c = Lin.rcd[i+1].key;
        Append(Lo, c);
    }
}

int main()
{
    srand((unsigned)time(NULL));//随机数种子
    int Length=0,i;
    KeyType c;
    SqList l,l2,l3,l4,l5,l6,l7;
    Heap h;
    int ListL=0;
    printf("顺序表长度不小于：\n");
    scanf("%d",&ListL);
    Length = 0;
    while(Length<=ListL){
        Length += rand()%150;//产生数值小于50的随机栈元素个数
    }
    Length = 168;
    int select=0;
    int bubble_c=0,bubble_s=0;
    int insert_c=0,insert_s=0;
    int easy_c=0,easy_s=0;
    int quick_c=0,quick_s=0;
   do{
            InitList(l);    //随机序列顺序表
            InitList(l2);InitList(l3);InitList(l4);InitList(l5);InitList(l6);InitList(l7)
            printf("select 1 排序随机无序字符串\n");
            printf("select 2 排序随机正序字符串\n");
            printf("select 3 排序随机逆序字符串\n");
            scanf("%d",&select);
            switch (select){
                case 1:
                        for(i=0; i<Length; i++){
                            c = 'A'+ rand()%26;
                            Append(l, c);       //产生随机的大写字符串插入线性表
                        }
                         break;
                case 2:
                        for(i=0; i<Length; i++){
                            c = 'A'+ i*1.0/Length*26;
                            Append(l, c);       //产生正序的大写字符串插入线性表
                        }
                        break;
                case 3:
                        for(i=0; i<Length; i++){
                            c = 'Z'- i*1.0/Length*25;
                            Append(l, c);       //产生逆序的大写字符串插入线性表
                        }
                        break;
            }
            Copy_L(l, l2, Length);Copy_L(l, l3, Length);Copy_L(l, l4, Length);Copy_L(l, l5, Length);
            Copy_L(l, l6, Length);Copy_L(l, l7, Length);
            Print(l);
            BubbleSort(l, bubble_c, bubble_s);
            InsertSort(l2, insert_c, insert_s);
            SelectEasy(l3, easy_c, easy_s);
            int d[]={40,30,20,10,5,3,1};
            int t=7;
            ShellSort(l4, d, t, shell_c, shell_s);
            QuickSort(l5, quick_c, quick_s);
            HeapSort(l6, heap_c, heap_s);
            MergeSort(l7, merge_c, merge_s);
            printf("\nSORT          关键字比较次数      关键字移动次数      \n");
            printf("Bubble         %-25d%-20d\n\n",bubble_c, bubble_s);
            printf("Insert         %-25d%-20d\n\n",insert_c, insert_s);
            printf("Easy           %-25d%-20d\n\n",easy_c, easy_s);
            printf("Quick          %-25d%-20d\n\n",quick_c, quick_s);
            Print(l);
            printf("The length of List:%d\n",Length);
            bubble_c=0,bubble_s=0;
            insert_c=0,insert_s=0;
            easy_c=0,easy_s=0;
            quick_c=0,quick_s=0;
            Destroy(l);Destroy(l2);Destroy(l3);Destroy(l4);Destroy(l5);Destroy(l6);Destroy(l7);

     }while(select<=3 && select >=1);
    return 0;

}
