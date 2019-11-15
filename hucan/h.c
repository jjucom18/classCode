#include<stdio.h>
#include<stdio.h>
typedef int ElemType;
typedef struct Node
{
ElemType data;
struct Node*next;
}
Node,*LinkedList;
LinkedList LinkedListlnit()
{
 Node *L;
 L=(Node *)malloc(size of (Node));
 if(L=NULL)
printf(“申请空间失败”）；
L->next=NULL;
}
LinkedList LinkedListCreateH()
{
Node *L;
L=(Node *)malloc(sizeof(Node));
L->next=NULL;
ElemType x;
while(scanf("%d",&x)!=EOF)
{
 Node *p;
 p=(Node *)malloc(sizeof(Node));
 p->data=x;
 p->next=L->next;
 L->next=p;
 }
 return L;
LinkedList LinkedListCreateT()
{
Node *L;
L=(Node *)malloc(sizeof(Node));
L->next=NULL;
Node *r;
r=L;
ElemType x;
while(scanf("%d",&x)!=EOF
{
Node *p;
p=Node *)malloc(sizeof(Node));
p->data=x;
r->next=p;
r=p;
}
return L;
}
LinkedList LinkedListDelete(LinkedList L,ElemType x)
{
 Node *p,*pre;
 p=L->next;
 while(p-<data!=NULL)
{
pre->next;
}
pre->next=p->next;
free(p)
return L;
}
struct node
{
int data;
node *next;
}*head;
*node Search(int key)
{
 node *p=head;
 while (p->data!=key && p!=NULL) p=p->next;
 return p;
}
void print(node *head)
{
node *p;
int index =0;
if(head->next == NULL
{
cout <<"Link is empty"<<return;
}
p=head->next;
while(p!= NULL)
{
cout<<"the"<<++index<<p=p->next;
}
}
