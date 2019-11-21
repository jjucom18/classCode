#include<stdio.h>                                                                       
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

	typedef void(*DISPLAY)(void*);
	typedef void(*COMPARE)(void*,void*);



typedef struct _node{
void *data;
	struct _node *next;
}Node;
typedef struct Linklist{
	Node *head;
	Node *tail;
	Node *current;
}Linklist; 

void initializeList(Linklist *list){
	list->head=NULL;
	list->tail=NULL;
	list->current=NULL;

}

 int addHead(Linklist *list,void* data){
	 Node *node=(Node*)malloc(sizeof(Node));
		 node->data=data;
	 if(list->head==NULL){
		 list->tail=node;
		 node->next=NULL;
	 }
	 else {
		 node->next=list->head;
	 }
	 list->head=node;
 }
   
    void addTail(Linklist *list,void* data){
		Node *node=(Node*)malloc(sizeof(Node));
		node->data=data;
		node->next=NULL;
		if(list->head==NULL){
			list->head=node;
		}
		else {
			list->tail->next=node;
		}
		list->tail=node;
	}

   void delete(Linklist *list,Node *node){
	   if(node==list->head){
		   if(list->head->next==NULL){
			   list->head=list->tail=NULL;
		   }
		   else{
    list->head=list->head->next;
		   }
	   }
	   else {
		   Node *tmp=list->head;
		   while(tmp!=NULL&&tmp->next!=node){
			   tmp=tmp->next;
		   }
		   if(tmp!=NULL){
			   tmp->next=node->next;
		   }
	   }
  free(node); }

Node *getNode(Linklist *list,COMPARE compare,void* data){
	Node *node=list->head;
	while(node!=NULL){
		if(compare(node->data,data)==0){
			return node;
		}
		node=node->next;
	}
	return NULL;
}




void displayLinklist(Linklist *L){
	printf("\nLinklist\n");
	Node *current=L->head;
	while(current!=NULL){
		printf("%p",current->data);
		current=current->next;
	}
}
void main(){
Linklist *list=(Linklist *)malloc(sizeof(Linklist));
int data_arr[]={
	1,2,3,4
};
  initializeList(list);
  addHead(list,1);
  addHead(list,2);
  addHead(list,3);
  addHead(list,4);
  delete(list,2);
  display(*list);
  Node *node=getNode(list,5);
  printf("the getNode result: %p\n",node->data);
  
}


