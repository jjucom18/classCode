#include <stdio.h>
#include <stdlib.h>
#include "test1.h"

void initList(LinkedList *list){
	list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

void addHead(LinkedList *list,int data){
	Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
 
    if(list->head == NULL){
        list->tail = node;
    }else{
        node->next = list->head;
    }
    list->head = node;
}

void addTail(LinkedList *list,int data){
	Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
 
    if(list->head == NULL){
        list->head = node;
    }else{
        list->tail->next = node;
    }
    list->tail = node;
}

void delete(LinkedList *list,Node *node){
	if(node == list->head){
		if(list->head->next == NULL){
			list->head = list->tail = NULL;
		}else{	
        list->head = list->head->next;
    	}
    }else{
    Node *tmp = list->head;
    while(tmp != NULL && tmp->next != node){
    	tmp = tmp->next;
    }	
        if(tmp != NULL){
            tmp->next = node->next;
		} 
        free(node);
    }
}          

Node *getNode(LinkedList *list,int data){
	Node *node = list->head;
    while(node != NULL){
        if(node->data == data){
            return node;
        }else{
            node = node->next;
        }
    }
    return NULL;
}

void displayLinkedList(LinkedList *list){
	printf("\nLinked List\n");
	Node *current = list->head;
    while(current != NULL){
        printf("%d/n",current->data);
        current = current->next;
    }
}
