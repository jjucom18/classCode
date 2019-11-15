#include<stdio.h>
#include<malloc.h>
typedef int datdType;
typedef struct node {
        dataType data;
        struct node{
        dataType data;
        struct node *next;
        }LinkList;
        LinkList *CreateList(){
        LinkList *head;
        head = (LinkList*)malloc(sizeof(LinkList));
        head->next = NULL;
        return head;
        }
         LinkedList LinkedListCreatH()
        {
                     Node *L;
                L = (Node *)malloc(sizeof(Node));
                L->next = NULL;

                Elemtype x
                while (scanf("%d", &x) != EOF)
        {
           Node *p;
           p = (Node *)malloc(sizeof(Node));
           p->data = x;
           p->next = L->next;
           L->next = p;
        }
          return L;
        }
