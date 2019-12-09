#include"SeqList.h"

SeqList *initSeqList()
{
    SeqList *list = (SeqList *)malloc(sizeof(SeqList));
    list->leng = -1;

    return list;
}

bool EmptyList(SeqList *list)
{
    return list->leng == -1;
}//判断是否为空

bool FullList(SeqList *list)
{
    return list->leng ==MaxSize-1;
}//判断是否满 

void inLocalList(SeqList *list,int k,DataType data)  //在表的指定位置k处插入值为data的元素
{
    if(FullList(list)) printf("list is full!\n");
    if(k<1 || k> list->leng+2)
    printf("local is wrong!\n");
 //   for(int i=list->leng;i >= k -1;i--)
  //  {
   //         list->data[i+1] = list->data[i];
  //  }
    list->data[k-1] = data;
    list->leng++;
}

void outList(char *msg,SeqList *list)
{
    printf("%s: \n", msg);
        for(int i = 0; i < list->leng + 1; i++){
                printf("%d\t", list->data[i]);
        }
        printf("\n");

        return;
}

int searchLocalList(SeqList *list,DataType data)
{
    int local = -1;
    for(int i = 0;i< list->leng +1;i++)
    {
        if(data ==list->data[i])
        {local = i+1;}
    }
    return local;
}//找到指定值元素，返回下标

DataType searchElementList(SeqList *list,int k)
{
    return list->data[k-1];
}//找到指定位置元素返回元素值

void deLocalList(SeqList *list,int k)
{
    if(EmptyList(list))
    {
        printf("list is empty!\n");
    }
    if(k<1 || k>list->leng+1)
    {
        printf("local is wrong\n");
    }
    for(int i=k-1;i<list->leng+1;i++)
    {
        list->data[i] = list->data[i+1];
    }
    list->leng--;
}

void deElementList(SeqList *list,DataType data)
{
    int result = searchLocalList(list,data);
    if(result == -1) 
    {printf("Local is wrong!\n");
    return;}
    deLocalList(list,result);
}



