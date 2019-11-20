#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef int *COMPARE;
typedef int dataType;
typedef struct node{
dataType data;
struct node *next;
}LinkList,node;
LinkList* CreateList(){
LinkList *head;
head = (LinkList*)malloc(sizeof(LinkList));
head->next = NULL;
return head;
}
int Size(LinkList *l){
struct node *p = l->next;
	int a = 0;
	int k;
	while (p){
		k++;
		p = p->next;
	}
	return a;
}
void Insert(LinkList *l,int a,dataType b){
	if (a<1) exit(1);
node *p = l;
int i = 0;
while (p && i<a-1){
	p = p->next;
	i++;
}
if (!p) exit(1);
node *s = (node*)malloc(sizeof(node));
s->data = b;
s->next = p->next;
p->next = s;
}
void Delate(LinkList *l,int a){
if (a<1) exit(1);
node *p = l;
int i = 0;
while(p->next && i<a-1){
	p = p->next;
	i++;
}
if (p->next==NULL) exit(1);
node *q = p->next;
p->next = q->next;
free(q);
}
node *GetNode(LinkList *l,COMPARE compare ,void* data){
node *node = l->next;
while(node != NULL){
	if((node->data,data) == 0){
		return node;
	}
	node = node->next;
}
	return NULL;
}
void Print(LinkList *l){
node *p = l->next;
while(p) {
	printf("%d", p->data);
	p = p->next;
}
printf("\n");

int main (int argc,char **argv){
	 LinkList *l = CreateList();
	 Insert(l,1,10);
	 Insert(l,1,20);
	 Delete(l,2);
	 Insert(l,1,30);
	 Insert(l,1,40);
	 printf("链表的元素个数为： %d\n", Size(l));
	 print(l);
	 printf("链表的第2个元素为%d", GetData(l,2));
	 system("pause");
         GetNode(l,l,30);
}}
