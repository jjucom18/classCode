#include<stdio.h>
#include<stdlib.h>
#define Error 0
#define OK 1
    typedef int ElemType;
    typedef struct node{
    ElemType element;
    struct node *link;
}node;
    typedef struct{
    struct node *head;
    int n;
}headerList;//头结点的插入
    typedef int Status;
    Status Init(headerList *h){
    h->head=(node*)malloc(sizeof(node));
    if(!h->head)
    return Error;
    h->head->link=NULL;
    h->n=0;
    return OK;
}
    Status Insert(headerList *h,int i,ElemType *x){
    node *p,*q;
    int j;
    if(i<-1||i>h->n-1)
    return Error;
     p=h->head;
    for(j=0;j<=i;j++) p=p->link;
            q=malloc(sizeof(node));
    q->element=x;
    q->link=p->link;
    p->link=q;
    h->n++;
    return OK;
}
    Status Output(headerList *h,int i,ElemType *x){
    int i=0;
    node *p;
    if(!h->head)
    return Error;
    p=h->head;
    for(i=0;i<h->n;i++){
    p=p->link;
    printf("%d",p->element);
    }
    return OK;
}
    Status Delete(headerList *h,int i){
    int j;
    node *p,*q;
    if(!h->n)
	 return Error;
    if(i<0||i>h->n-1)
	 return Error;
    q=h->head;
    for(j=0;j<i;j++)q=q->link;
    p=q->link;
    q->link=p->link;
    free(p);
    h->n--;
    return OK;   
}
    Status Find(headerList h,int i,ElemType *x){
    node *p;
    int j;
    if(i<0||i>h->n-1)
	return Error;
    p=h.head->link;
    for(j=0;j<i;j++) p=p->link;
    *x=p->element;
    return OK;   
}
    void Destroy(headerList *h){
    node *p;
    while(h->head){
    p=h->head->link;
    free(h->head);
    h->head=p;
    }    
}
    void main(){
    int i;
    int x;
    headerList list;
    Init(&list);
    for(i=0;i<9;i++)
	    Insert(&list,i-1,i);
    printf("插入数据是:");
    Output(&list);
    Delete(&list,0);
    printf("\n插入数据是:");;
    Find(list,0,&x);
    printf("\n查找结果是:");
    printf("%d",1);
    Destroy(&list);
}    

