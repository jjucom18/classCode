#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int DataType;

typedef struct Node{
DataType data;//定义单链表数据域

struct Node *next;//定义单链表指针域
}Node,*LinkedList;
LinkedList initLinkedList(){
Node *L;
L=(Node *)malloc(sizeof(Node));//分配内存空间
if(L==NULL)//判断是否分配成功
	printf("分配内存空间失败");
L->next=NULL;
return L;
    
}

//单链表的头插法
LinkedList Creat_LinkedListT(){
Node *L;
L=(Node *)malloc(sizeof(Node));//给头结点申请内存
L->next=NULL;//初始化一个空链表
DataType x;

scanf("%d",&x);
while(x!=EOF){
Node *p;
p=(Node *)malloc(sizeof(Node));
p->data=x;//申请节点填充数据
p->next=L;
L=p;//将节点p插入链表头部

}
return L;

}

//单链表的尾插法
LinkedList Creat_LinkedListW(){
Node *L;
L=(Node *)malloc(sizeof(Node));
L->next=NULL;//初始化一个控链表
Node *r;
r=L;

DataType x;
scanf("%d",&x);
while(x!=EOF){
Node *p;
p=(Node *)malloc(sizeof(Node));//申请新节点
p->data=x;
r->next=p;
r=p;

}
r->next=NULL;
  return L;

  }

//链表节点的删除
LinkedList Delete_LinkedList(LinkedList L,DataType i){
//删除单链表中第i个数据节点
LinkedList p,s;
p=Get_LinkedList(L,i-1);//查找第i-1个节点
if(p==NULL){
printf("第i-1个节点不存在");
  return -1;
   }
else if(p->next==NULL){
printf("第i个节点不存在");
  return 0;
    }
else {
s=p->next;
p->next=s->next;
free(s);
  return 1;
}

}


//在链表中间i个位置插入,并返回
LinkedList InsertLinkedList(LinkedList L,int i,DataType x){
Node *prior;
prior=L;
int temp=0;
for(temp=1;temp<i;temp++)
	prior=prior->next;//查找第i个前驱节点
Node *p=(Node *)malloc(sizeof(Node));
p->data=x;
p->next=prior->next;
prior->next=p;
  return L;
}










