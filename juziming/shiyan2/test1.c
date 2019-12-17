nclude <stdio.h>
#include <stdlib.h>

typedef int ElemType;
 
typedef struct Node
{
ElemType data; //单链表中的数据域 
struct Node *next; //单链表的指针域 
} Node,*LinkedList;
LinkedList LinkedListInit() 
{

Node *L;
L = (Node *) malloc(sizeof(Node) ) ; //申请结点空间 
if(L == NULL)  //判断是否有足够的内存空间 
printf('申请内存空间失败') ;
L->next = NULL; br> //将next设置为NULL,初始长度为0的单链表 
	return L;
} 

LinkedList LinkedListCreatH() 
{
	Node *L;
L = (Node *) malloc(sizeof(Node) ) ; //申请头结点空间
L->next = NULL; //初始化一个空链表
ElemType x; //x为链表数据域中的数据
while(scanf('%d',&x)  != EOF) 
{

Node *p;
p = (Node *) malloc(sizeof(Node) ) ; //申请新的结点 
p->data = x; //结点数据域赋值 
p->next = L->next; //将结点插入到表头L-->|2|-->|1|-->NULL 
L->next = p; 
} 
return L; 
}  


LinkedList LinkedListCreatT() 
{
Node *L;
L = (Node *) malloc(sizeof(Node) ) ; //申请头结点空间
L->next = NULL; //初始化一个空链表
br> Node *r;
r = L; //r始终指向终端结点，开始时指向头结点 
ElemType x; //x为链表数据域中的数据
while(scanf('%d',&x)  != EOF) 
{

Node *p;
p = (Node *) malloc(sizeof(Node) ) ; //申请新的结点 
p->data = x; //结点数据域赋值 
r->next = p; //将结点插入到表头L-->|1|-->|2|-->NULL 
r = p; 
} 
r->next = NULL; 

return L; 
} 


LinkedList LinkedListInsert(LinkedList L,int i,ElemType x) 
{
Node *pre; //pre为前驱结点 
pre = L;
int tempi = 0;
for (tempi = 1; tempi < i; tempi++) 
pre = pre->next; //查找第i个位置的前驱结点 
Node *p; //插入的结点为p
p = (Node *) malloc(sizeof(Node) ) ;
p->data = x; 
p->next = pre->next;
pre->next = p;

return L; 
}
LinkedList LinkedListDelete(LinkedList L,ElemType x) 
{

Node *p,*pre; //pre为前驱结点，p为查找的结点。 
p = L->next;
while(p->data != x)  //查找值为x的元素 
{
 
 pre = p; 
 p = p->next;
 } 
 pre->next = p->next; //删除操作，将其前驱next指向其后继。 
 free(p) ;
 return L;
}  

 int main() 
 {

 LinkedList list,start;
 printf('请输入单链表的数据：') ; 
 list = LinkedListCreatH() ;
 for(start = list->next; start != NULL; start = start->next) 
 printf('%d ',start->data) ;
 printf('') ;

 int i;
 ElemType x;
 printf('请输入插入数据的位置：') ;
 scanf('%d',&i) ;
 printf('请输入插入数据的值：') ;
 scanf('%d',&x) ;
 LinkedListInsert(list,i,x) ;
 for(start = list->next; start != NULL; start = start->next) 
	 printf('%d ',start->data) ;
printf('') ;
printf('请输入要删除的元素的值：') ;
scanf('%d',&x) ;
 LinkedListDelete(list,x) ; 
 for(start = list->next; start != NULL; start = start->next) 
 printf('%d ',start->data) ;
 printf('') ;
 return 0;
} 
