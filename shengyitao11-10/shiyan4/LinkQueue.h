#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
typedef int ElemType1;
typedef struct qnode{
    ElemType1 data;
    struct qnode *next;
}DataNode;
typedef struct{
    DataNode *front;
    DataNode *rear;
}LinkQuNode;
 
void InitQueue(LinkQuNode *&q){//初始化 
    q=(LinkQuNode *)malloc(sizeof(LinkQuNode));
    q->front=q->rear=NULL; 
}
void DestroyQueue(LinkQuNode *&q){//销毁
    DataNode *pre=q->front,*p;
    if(pre!=NULL){
        p=pre->next;
        while(p!=NULL){
            free(pre);
            pre=p;
            p=p->next;
        }
        free(pre);
    }
    free(q);
}
bool QueueEmpty(LinkQuNode *q){//判断空否 
    return(q->rear==NULL);
}
void EnQueue(LinkQuNode *&q,ElemType1 e){//进队 
    DataNode *p;
    p=(DataNode *)malloc(sizeof(DataNode));
    p->data=e;
    p->next=NULL;
    if(q->rear==NULL)  q->front=q->rear=p;
    else{
        q->rear->next=p;
        q->rear=p;
    }
}
bool DeQueue(LinkQuNode *&q,ElemType1 &e){//出队 
    DataNode *t;
    if(q->rear==NULL)  return false;
    t=q->front;
    if(q->front==q->rear)  q->front=q->rear=NULL;
    else  q->front=q->front->next;
    e=t->data;
    free(t);
    return true;
}
int QueueLength(LinkQuNode *q){//队列的长度
    int length=0;
    if(QueueEmpty(q))  return length;
    else if(!QueueEmpty(q)){
        DataNode *p;
        p=q->front;
        while(p){
            length++;
            p=p->next;
        }
        return length;
    } 
}
void DispQueue(LinkQuNode *q)//输出等待 
{
    DataNode *t=q->front;
    while(t!=NULL)
    {
        printf("车牌号：%d\n",t->data);
        t=t->next;
    }
}
