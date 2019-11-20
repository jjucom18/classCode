#include "testc2.h"
#include<stdlib.h>
#include<stdio.h>

void initList(List * list){
        list->head = NULL;
	list->tail = NULL;
       	list->current = NULL;
}//1

void addHead(List * list, DataType data  ){

	Node *node = (Node *) malloc (sizeof(Node));
	node->data = data;
	node->next = NULL;
	if(list->head = NULL){
	list->tail = node;
	} else{
	   node->next = list->head;
	}
	list->head = node;

	return NULL;
}//2

void addTail(List * list, DataType data){

	Node *node = (Node *) malloc (sizeof(Node));
	node->data = data;
	node->next = NULL;
	if(list->head = NULL){
	list->head = node;
	}else{
	  list->tail->next = node;
	}
	list->tail = node;
	return NULL;
}//3


void deleteNode(List *list, DataType data){
    if(list->head->data == data){
        list->head = list->head->next;
    }
    Node *prev = list->head;
    Node *node = prev->next;
    while(node != NULL){
        if(node->data == data){
            prev->next = prev->next->next;
              return;
        }else{
            prev = prev->next;
            node = node->next;
        }
    }
      return NULL;
}//4


Node *getNode(List *list, DataType date){
    Node *node = (Node *) malloc (sizeof(Node));
    node = list->head;
    while(node != NULL){
        if(node->data == date){
            return node;
        }else{
            node = node->next;
        }
    }
     return NULL;
}//5


void displayList(List *list){
    Node *node = list->head;
    int i = 0;
    while(node != NULL){
        printf("%d,%d\n", i + 1, node->data);
        node = node->next;
        i++;
    }
    printf("display finished!\n");
     return NULL;
}//6
