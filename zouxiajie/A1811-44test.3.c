#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElemType;
typedef struct Node{
   ElemType data;
   struct Node *next;}Node;typedef struct Node * Linklist;

   int initlist(Linklist *L){
        (*L)=(Linklist)malloc(sizeof(Node));
        (*L)->next = NULL;
        printf("链表初始化成功\n");
        return 1;}

    int createlistHead(Linklist *L,int n){
         Linklist p;
         int i = 0;
         srand((int)time(0));
         for(i =0;i<n;i++){
         p=(Linklist)malloc(sizeof(Node));
         p->data=rand()&100;
         printf("testing:Node[%d]=%d\n",i+1,p->data);
         p->next=(*L)->next;
         (*L)->next=p;
         printf ("链表(头插法)创建成功\n");
         return 1;}

     int createlistTail(Linklist *L,int n){
        Linklist p; int * temp;
        temp = (*L);int i;
        srand((int)time(0));
        for(i=0;i<n;i++){
         p=(Linklist)malloc(sizeof(Node));
         p->data=rand()%100;
         printf("testing:Node[%d]=%d\n",i+1,p->data);
         p->next =NULL;
         temp->next = p;
         temp = p;}
         printf ("链表(尾插法)创建成功\n");
         return 1;}

     int printlist(Linklist *L){
         Linklist p;
         int i=0;
         p=(*L)->next;
         printf("------打印链表-----\n");
         if(p==NULL){
         printf("这是一个空链表\n");}
         while(p){
          i++;
         printf("第%d个节点的数据data为=%d\n",i,p->data);
         p=p->next;}
         return 1;}

     int getElem(Linklist *L,int i,ElemType * getdata){
          Linklist p;
          p=(*L)->next;
          if(p=NULL){
          printf("链表为空,请创建一个链表\n");
          *getdata =-1;
          return 0;}
          if(i<1){
          printf("所查询的节点%d,应该f大于0,请重新输入查询\n",i);
          *getdata =-1;
          return 0;}
          int j=1;
          while(p&&j<i){
          j++;p=p->next;}
          if(p=NULL){
          printf("所查询的节点%d,已经超出了数组的长度\n",i);
          *getdata=-1;
          return 0;}
          *getdata=p->data;
          printf("查询成功!\n",i);
          return 1;}

     int insertlist(Linklist *L,int i,ElemType data){
         Linklist p;
         Linklist insNode;
         p=(*L);
         int j=0;
         if (p->next==NULL){
          printf("链表为空,默认在第一个位置插入一个节点\n");
          insNode=(Linklist)malloc(sizeof(Node));
          insNode->data=data;
          insNode->next=p->next;
          p->next=insNode;
          printf("节点插入成功\n");
          return 1;}
         while(p&&j<i-1){
          j++;p=p->next;
          printf("j=%d\t p->data=%d\n",j,p->data);}
         if(p->next==NULL){
           printf("插入的位置超过了链表的长度%d,请重新操作!\n",j);
           return 0;}
          insNode=(Linklist)malloc(sizeof(Node));
          insNode->data=data;
          insNode->next=p->next;
          p->next = insNode;
          printf("节点插入成功\n");
          return 1;}

     int insertlistHead(Linklist *L,ElemType  *data){
      Linklist n;
      Linklist p=(*L);
      while(p){
        n=p;n=p->data;
        p=(Linklist)malloc(sizeof(Node));
        p->data=NULL;
        n->data=p;
        printf("节点插入成功\n");
        return 1;}}

     int insertlistTail(Linklist *L,ElemType  *data){
        Linklist q;int * temp;
        Linklist p=(*L);
        while(p){
         temp=q;q=p->next;
         p=(Linklist)malloc(sizeof(Node));
         p->next=NULL;
         temp->next=p;
         printf("节点插入成功\n");
         return 1;}}

     int deletelist(Linklist *L,int i,ElemType *data){
         Linklist p,pnext;
         int j=0;
         p=(*L);
         if(p->next==NULL){
          printf("链表为空，无法删除指定节点");
          *data=-1;
          return 0;}
          while(p->next&&j<i-1){
          j++;p=p->next;
          printf("j=%d\t p->data=%d\n",j,p->data);}
         if(p->data==NULL){
          printf("删除的节点超过了链表的长度%d,请重新操作!\n",j);
          *data=-1;
          return 0;}
         pnext=p->next;
         p->next=pnext->next;
         *data=pnext->data;
         free(pnext);
         printf("节点成功删除\n");
         return 1;}}
