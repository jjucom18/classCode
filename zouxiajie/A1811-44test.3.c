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
        printf("�����ʼ���ɹ�\n");
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
         printf ("����(ͷ�巨)�����ɹ�\n");
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
         printf ("����(β�巨)�����ɹ�\n");
         return 1;}

     int printlist(Linklist *L){
         Linklist p;
         int i=0;
         p=(*L)->next;
         printf("------��ӡ����-----\n");
         if(p==NULL){
         printf("����һ��������\n");}
         while(p){
          i++;
         printf("��%d���ڵ������dataΪ=%d\n",i,p->data);
         p=p->next;}
         return 1;}

     int getElem(Linklist *L,int i,ElemType * getdata){
          Linklist p;
          p=(*L)->next;
          if(p=NULL){
          printf("����Ϊ��,�봴��һ������\n");
          *getdata =-1;
          return 0;}
          if(i<1){
          printf("����ѯ�Ľڵ�%d,Ӧ��f����0,�����������ѯ\n",i);
          *getdata =-1;
          return 0;}
          int j=1;
          while(p&&j<i){
          j++;p=p->next;}
          if(p=NULL){
          printf("����ѯ�Ľڵ�%d,�Ѿ�����������ĳ���\n",i);
          *getdata=-1;
          return 0;}
          *getdata=p->data;
          printf("��ѯ�ɹ�!\n",i);
          return 1;}

     int insertlist(Linklist *L,int i,ElemType data){
         Linklist p;
         Linklist insNode;
         p=(*L);
         int j=0;
         if (p->next==NULL){
          printf("����Ϊ��,Ĭ���ڵ�һ��λ�ò���һ���ڵ�\n");
          insNode=(Linklist)malloc(sizeof(Node));
          insNode->data=data;
          insNode->next=p->next;
          p->next=insNode;
          printf("�ڵ����ɹ�\n");
          return 1;}
         while(p&&j<i-1){
          j++;p=p->next;
          printf("j=%d\t p->data=%d\n",j,p->data);}
         if(p->next==NULL){
           printf("�����λ�ó���������ĳ���%d,�����²���!\n",j);
           return 0;}
          insNode=(Linklist)malloc(sizeof(Node));
          insNode->data=data;
          insNode->next=p->next;
          p->next = insNode;
          printf("�ڵ����ɹ�\n");
          return 1;}

     int insertlistHead(Linklist *L,ElemType  *data){
      Linklist n;
      Linklist p=(*L);
      while(p){
        n=p;n=p->data;
        p=(Linklist)malloc(sizeof(Node));
        p->data=NULL;
        n->data=p;
        printf("�ڵ����ɹ�\n");
        return 1;}}

     int insertlistTail(Linklist *L,ElemType  *data){
        Linklist q;int * temp;
        Linklist p=(*L);
        while(p){
         temp=q;q=p->next;
         p=(Linklist)malloc(sizeof(Node));
         p->next=NULL;
         temp->next=p;
         printf("�ڵ����ɹ�\n");
         return 1;}}

     int deletelist(Linklist *L,int i,ElemType *data){
         Linklist p,pnext;
         int j=0;
         p=(*L);
         if(p->next==NULL){
          printf("����Ϊ�գ��޷�ɾ��ָ���ڵ�");
          *data=-1;
          return 0;}
          while(p->next&&j<i-1){
          j++;p=p->next;
          printf("j=%d\t p->data=%d\n",j,p->data);}
         if(p->data==NULL){
          printf("ɾ���Ľڵ㳬��������ĳ���%d,�����²���!\n",j);
          *data=-1;
          return 0;}
         pnext=p->next;
         p->next=pnext->next;
         *data=pnext->data;
         free(pnext);
         printf("�ڵ�ɹ�ɾ��\n");
         return 1;}}
