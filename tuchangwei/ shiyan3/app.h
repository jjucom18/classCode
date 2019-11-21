#ifndef app_h
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20


typedef int datetype;

typedef struct 					
{
        datetype date[MAXSIZE];
                datetype last;
}SeqList;

SeqList *Init_SeqList()
{ 
        printf("初始化顺序表\n");
        SeqList *L;
        L = (SeqList *)malloc(sizeof(SeqList));
	L->last  = -1;
        srand (time(NULL));
        for  (datetype i=0;i<=MAXSIZE;i++)
         {
                L->date[i] = (rand()%1000);
                printf("%d\t",L->date[i]);
                L->last = i;
         }
        printf("\n");
        return L;
}

void Bubble_Sort(SeqList *L)
{
        printf("冒泡排序法\n");
        datetype i,j;
        datetype swap;
        for(i = 1;i<=MAXSIZE;i++)
        {swap = 0;
        for(j =1;j<=MAXSIZE-1;j++)
                if(L->date[j] > L->date[j+1])
                {
                        L->date[0] = L->date[j+1];
                        L->date[j+1] = L->date[j];
                        L->date[j] = L->date[0];
                        swap = 1;
                }
        if(swap == 0) break;
        }
        printf("输出排序后的值\n");
        for(datetype i = 0;i <= MAXSIZE -1; i++)
        printf("%d\t",L->date[i]);
        printf("\n");
}

void D_InserSort(SeqList *L)                    
{
        printf("插入排序\n");
        for(datetype i = 1;i<=MAXSIZE;i++)
                if(L->date[i] < L->date[i-1])
                {
                datetype temp;
                temp = L->date[i];
                datetype j = i-1;
        for( j ;temp < L->date[j] ; j--)
                        L->date[j+1] = L->date[j];
                L->date[j+1] = temp;
                }
        printf("输出排序后的值\n");
        for(datetype i = 0;i <= MAXSIZE -1; i++)
        printf("%d\t",L->date[i]);
        printf("\n");
}

void Select_Sort(SeqList *L)
{
        printf("选择排序法\n");
        datetype i ;
        for (i = 0; i<MAXSIZE;i++)
        {
                datetype k,j;
                k = i;
                for(j = i+1;j<=MAXSIZE;j++)
                        if(L->date[j] < L->date[k])
                                k = j;
                        if(i!=k)
                        {
                                datetype temp;
                                temp = L->date[k];
                                L->date[k] = L->date[i];
                                L->date[i] = temp;
                        }
        }
        printf("输出排序后的值\n");
        for(datetype i = 0;i <= MAXSIZE -1; i++)
        printf("%d\t",L->date[i]);
        printf("\n");
}
void ShellSort(SeqList *L)
{
        printf("希尔排序\n");
        datetype i,j,k,h;
        datetype t = 5;
        datetype d[]={5,4,3,2,1};
        for(k = 0; k < t ;k++)
        {
        h= d[k];
        for(i = h;i<MAXSIZE;i++)
                if(L->date[i]<L->date[i-h])
                {
                        datetype temp;
                        temp = L->date[i];
                        for(j=i-h;j>0 && temp<L->date[j];j = j-h)
                        L->date[j+h] = L->date[j];
                        L->date[j+h] = temp;
                }
        }
        printf("输出排序后的值\n");
        for(datetype i = 0;i <= MAXSIZE -1; i++)
        printf("%d\t",L->date[i]);
        printf("\n");

}
void Menu(SeqList *L)
{
        int choice;
        printf("请按数字输入，选择对应的排序方式:\n");
        printf("1、插入排序\n");
        printf("2、冒泡排序\n");
        printf("3、选择排序\n");
        printf("4、希尔排序\n");

        do
        {       do
                {       scanf("%d",&choice);
                        switch(choice)
                       {
              case 1: D_InserSort ( L );
                              break;                                                         case 2: Bubble_Sort ( L );
               			 break;                                                      case 3: Select_Sort ( L );
                                   break;                                                    case 4: ShellSort   ( L );
                                 break;                                                          default :0;
                        printf("error:");
                                break;
                        }
                }while(choice==1||choice==2||choice==3||choice==4);

                printf("没有此排序，请重新输入\n");
        }while(1);
}

#endif
