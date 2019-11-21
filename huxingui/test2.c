   #include<stdio.h>
   #include<stdlib.h>
   
   typedef int Elemtype;
   typedef struct Node
   {
       Elemtype data;
       struct Node *next;
   }Node, *LinkedList;
  
  //单链表的初始化
  LinkedList LinkedListInit()
  {
      Node *L;
      L = (Node*)malloc(sizeof(Node));
      if (L == NULL)
      {
          printf("申请内存空间失败\n");
      }
      L->next = NULL;
      return L;
  }
  
  //单链表的创建一：头插法建立单链表
  LinkedList LinkedListCreatH()
  {
      Node *L;
      L = (Node *)malloc(sizeof(Node));
      L->next = NULL;
  
     Elemtype x;
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
  
  //单链表的创建二：尾插法建立单链表
  LinkedList LinkedListCreatT()
  {
      Node *L;
      L = (Node *)malloc(sizeof(Node));
      L->next = NULL;
  
      Node *r;
      r = L;
      Elemtype x;
      while (scanf("%d", &x) != EOF)
      {
          Node *p;
          p = (Node *)malloc(sizeof(Node));
          p->data = x;
          //p->next = NULL;
          r->next = p;
          r = p;
      }
      r->next = NULL;
      return L;
 }
  //删除
void Delete (LinkList *1,int k){
if (k<1) exit(1);
node *p =1;
int i =0;
while (p->next&&i<k-1){
p=p->next;
i++;
}
if (p->next==NULL) exit(1);
node *q=p->next;
p->next=q->next;
free(q);
}
//特定值返回
node* Find(LinkList *1,dataType x){
node *p=1->next;
while (p&&p->data!=x)
p=p->next;
return p;
}
//输出列表
void Print(LinkList *1){
node *p=1->next;
while(p){
printf("%d",p->data);
p=p->next;
}
printf("\n");
}
  
