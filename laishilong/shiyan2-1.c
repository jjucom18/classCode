#include <stdlib.h>
#include <stdio.h>

#include "list.h"
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
          list->head = node;
      }else{
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
      Node *prev = list->head;
      Node *node = prev->next;
      while(node != NULL){
          if(node->data == iData){
              prev->next = prev->next->next;
 
              return;
          }else{
              prev = prev->next;
              node = node->next;
          }
      }
 
      return;
}
void displayLinkedList(List *list){
     Node *node = list->head;
     int i = 0;
     while(node != NULL){
         printf("the %dth node: %d\n", i + 1, node->data);
         node = node->next;
         i++;
     }
     printf("display finished!\n");

     return;
}
    


