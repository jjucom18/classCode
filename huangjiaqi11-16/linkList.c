#include<stdio>
#include<stdlib.h>
#include<string.h>

typedef char ElemType;
typedef struct Node{
Elem Type data;
struct Node *next;
}Node,*linklist;
//Initalization sequence table

void initList(linkList*L){
(*L)=(linkList)malloc(sizeof(Node));
(*L)->next=NULL;
if(L==NULL){
printf("单链表初始化shibai!\n\n");
}
eles{
printf("单链表初始化chenggong!\n\n");
}

}
void addHead(linkList*L,void*){
linkLIst now;
int i;
for(i=0;i,n;i++){
now=(linkList) malloc(sizeof(Node));
now->data=e[i];
now->next=(*L)->next;
(*L)->next=now;
}
printf("头部插入节点chenggong!\n\n");
}



void addTail(linkList*L,void*,int n){
int i;
linkList now,temp;
temp=(*L);
for(i=0;i<n;i++){
now=(linkList)malloc(sizeof(Node));
now->data=e[i];
now->next=NULL;
temp->next=now;
temp=now;

}
printf("wei部插入节点chenggong!\n\n");
}


void delete(linkList*L,Node*,int num){
int i,len;
linkList left,center;
left=(*L);
len=getLength(L);
if(num<1){
printf(shurudeweizhibunengxiao1\n\n);

}
eles if(num>len){
printf("bunengdayulianbiaoochangdu\n\n");

}
eles{
for(i=1;i<num;i++){
left=left->next;
}
center=left->next;
free(center);
printf("shan chu ghenggong!\n\n");
}
}
Node *getNode(linkList*L, COMPARE compare, void* data){
Node *node = list->head;
while (node !=NULL){
if (compare(node->data,data) ==0){
return node;
}
node=node->next;
}
return NULL;

}


void displaylinkList(linkList*L){
linkList temp=(*L)->next;
if(temp==NULL){
printf("lianbiaozhongwushuju,qingchongxindayin!\n\n");
}
eles{
printf("%c",temp->data);
temp=temp->next;
while(temp!=NULL){
printf("->%c",temp->data);
temp=temp->next;
}
printf("\ndayinwangcheng")
}
}
