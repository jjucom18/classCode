#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
	void *data;
	struct _node *next;
} Node;
typedef struct _linkedList{
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;
    void initializeList(LinkedList *list){
		list->head=NULL;
		list->tail=NULL;
		list->current=NULL;
		return;
	}
    void addHead(LinkedList *list,void *data){
		Node *node=(Node*)malloc(sizeof(Node));
		node->data=data;
		if(list->head==NULL){
			list->tail=node;
			node->next=NULL;
		}else{
			node->next=list->head;
		}return;
	}
	void addTail(LinkedList *list,void *data){
		Node *node=(Node*)malloc(sizeof(Node));
		node->data=data;
		node->next=NULL;
		if(list->head==NULL){
			list->head=node;
		}else{
			list->tail->next=node;
		}
		list->tail=node;
		return;
	}
	void delete(LinkedList *list,Node *node){
		if(node==list->head){
			if(list->head->next==NULL){
				list->head=list->tail=NULL;
			}else{
				list->head=list->head->next;
			}
		}else{
			Node *tmp=list->head;
			while(tmp!=NULL && tmp->next!=node){
				tmp=tmp->next;
			}
			if(tmp!=NULL){
				tmp->next=node->next;
			}
		}
		free(node);
		return;
	}
	Node *getNode(LinkedList *list,void*data){
		Node *node=list->head;
		while(node!=NULL){
			if((node->data,data)==0){
				return node;
			}
			node=node->next;
		}
		return NULL;
	}
	void displayLinkedList(LinkedList *list){
		Node *current=list->head;
		while(current!=NULL){
			(current->data);
			current=current->next;
		}
		return;
	}

