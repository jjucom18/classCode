#include<stdio.h>
#include<malloc.h>
typedef int datdType;
typedef struct node {
        dataType data;
        struct node{
        dataType data;
        struct node *next;
        }LinkList;
        LinkList *CreateList(){
        LinkList *head;
        head = (LinkList*)malloc(sizeof(LinkList));
        head->next = NULL;
        return head;
        }
         LinkedList LinkedListCreatH()
        {
                     Node *L;
                L = (Node *)malloc(sizeof(Node));
                L->next = NULL;

                Elemtype x
                while (scanf("%d", &x) != EOF)
        {
           Node *p;
           p = (Node *)malloc(sizeof(Node));
           p->data = x;
           p->next = L->next;
           L->next = p;
        }
          return L;
        }
status Delete_linklist(linklist &L)
{
linklist p,q;
int k=0,x;
printf("请输入删除节点的值x: ");
scanf("%d",&x);
getchar();
if(L->next ==NULL)
return ERROR;
p=L;
q=L->next ;
while(q!=NULL)
if(q->data ==x)
{ 
k=1;
p=q ;
p->next =q->next ; 
free(q);
q=p->next ;
}
else
{
p=q ;
q=p->next ;
}
if(k==0)
printf("表中没有值为%d的结点！\n",&x);
return OK;
}
