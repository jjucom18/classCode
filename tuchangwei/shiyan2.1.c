#include <stdlib.h>
#include <stdio.h>
#include <list.h>

void initializeList(LinkedList *list) {
     list->head = NULL;
     list->tall = NULL;
     list->current = NULL;
}
void addHead(LinkedList *list, DataType iData) {
     Node *node = (Node*) malloc(sizeof(Node));
     node->data = data;
     if (list->head == NULL) {
         list->tail = node;
         node->next = NULL;
     } else {
         node->next = list->head;
     }
     list->head = node;
}
void addTail(LinkedList *list, DataType iData){
      Node *node = (Node *)malloc(sizeof(Node));
      node->data = Data;
      node->next = NULL;

if(list->head == NULL){
          list->head = node;}
      else{
          list->tail->next = node;
      }
      list->tail = node;
}
Node *getNode(LinkedList *list, DataType iData){
      Node *node = (Node *)malloc(sizeof(Node));
      node = list->head;
      while(node != NULL){
          if(node->data == iData){
              return node;
          }else{
              node = node->next;
          }
      }

      return NULL;
}
void delete(LinkedList *list, DataType iData){
     if(list->head->data == iData){
          list->head = list->head->next;
      }
 }
