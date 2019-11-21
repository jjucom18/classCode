#include<stdio.h>
#include<malloc.h>
typedef int dataType;
typedef struct {
    dataType data;
    struct node *next;
}node;
typedef struct node {
    dataType data;
    struct node *next;
} LinkList;

LinkList* CreateList (){
    LinkList *head;
    head = (LinkList *)malloc(sizeof(LinkList));
    head->next = NULL;
    return head;
}
 
int Size(LinkList *l){
    node *p = l->next;
    int k=0;
    while (p){
        k++;
        p=p->next;
    }
    return k;
}
void Insert (LinkList *l,int k,dataType x){
    if (k<1) exit (1);
    node *p = l;
    int i = 0;
    while (p && i<k-1){
        p=p->next;
        i++;
}
    if (!p) exit(1);
    node *s= (node *)malloc(sizeof(node));
    s->data=x;
    s->next=p->next;
    p->next=s;
}

void Delete(LinkList *l,int k){
    if (k<1) exit(1);
    node *p=l;
    int i=0;
    while (p->next && i<k-1){
        p=p->next;
        i++;
    }
    if (p->next == NULL) exit (1);
    node *q= p->next ;
    p->next = q->next;
    free(q);
}

int Empty(LinkList *l){
    return l->next ==NULL;
}

dataType GetData(LinkList *l,int k){
    if (k<1) exit(1);
    node *p=l;
    int i=0;
    while (p && i<k){
        p=p->next;
        i++;
    }
    if(!p) exix(1);
    return p->data;
}

node* Find(LinkList *l, dataType x){
    node *p = l->next;
    while (p && p->data!=x)
        p=p->next;
    return p;
}

void Print(LinkList *l){
    node *p = l->next;
    while (p){
        printf("%d",p->data);
        p = p->next;
    }
    printf("\n");
}

void ClearList(LinkList *l){
    node *p, *q;
    p=l->next;
    while (p){
        q=p;
        p=p->next;
        free(q);
    }
    l->next=NULL;
}

int main(){
    LinkList *list=CreateList();
    Insert(list,1,10);
    Insert(list,1,20);
    Delete(list,2);
    Insert(list,1,30);
    Insert(list,1,40);
    printf("%d\n",Size(list));
    Print(list);
    printf("%d",GetData(list,2));
    system("pause");
}
