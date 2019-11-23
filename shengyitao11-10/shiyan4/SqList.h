//表--停车
#include<malloc.h>
#include<stdio.h>    
#include"People.h" 
#define MaxSize 7
typedef peo ElemType;
typedef struct 
{    
    ElemType data[MaxSize];
       int length;
}SqList;    //顺序表类型
 
void CreateList(SqList*&L,ElemType a[],int n)//建立 
{
    int i;
    L=(SqList*)malloc(sizeof(SqList));
    for(i=0;i<n;i++)
        L->data[i]=a[i];
    L->length=n;
}
void InitList(SqList*&L)//初始化 
{
    L=(SqList*)malloc(sizeof(SqList));
    L->length=0;
}
void DestroyList(SqList *&L)//销毁 
{
    free(L);
}
bool ListEmpty(SqList *L)//检查空 
{
    return(L->length==0);
}
int ListLength(SqList *L)//长度 
{
    return(L->length);
}
void DispList(SqList *L)//输出 
{
    int i;
    if(ListEmpty(L)){
        cout<<"             没生意啊好心酸TvT~"<<endl;
        return;
    }
    for(i=0;i<L->length;i++)  Out1(L->data[i]);//stu类型 
    printf("\n");
} 
bool GetElem(SqList *L,int i,ElemType &e)//求值 
{
    if (i<1 || i>L->length)  return false;
    e=L->data[i-1];
    return true;
}
int LocateElem(SqList *L,ElemType e)//查找 
{
    int i=0;
    while (i<L->length && L->data[i].num!=e.num)   i++;
    if(i>=L->length)  return 0;
    else  return i+1;
}
bool ListInsert(SqList *&L,int i,ElemType e)//插入 
{  
    int j;
    if(i<1||i>L->length+1)  return false;
    i--;
    for(j=L->length;j>i;j--)  L->data[j]=L->data[j-1];
    L->data[i]=e;
    L->length++;
    return true;
}
bool ListDelete(SqList *&L,int i,ElemType &e)//删除 
{  
    int j;
    if(i<1||i>L->length)  return false;
    i--;
    e=L->data[i];
    for(j=i;j<L->length-1;j++)  L->data[j]=L->data[j+1];
    L->length--;
    return true;
}
