#include"Linklist.h"
#include<stdio.h>
#include<malloc.h>


void initializeList(LinkedList *list){
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

void addHead(LinkedList *list, void* data){
	Node *node =(Node*)malloc(sizeof(Node));
	node->data = data;
	if (list->head == NULL){
		list->tail = node;
		node->next = NULL;
    }else{
		node->next = list->head;
	}
	list->head = node;

}
void addTail(LinkedList *list,void* data){
Node *node = (Node*) malloc(sizeof(Node));
node->data = data;
node->next = NULL;
if (list->head ==NULL){
	list->head = node;
}else{
	list->tail->next = node;
}
list->tail = node;
}
void delete(LinkedList *list,Node *node){
	if (node == list->head){
		if(list->head->next == NULL){
			list->head = list->tail = NULL;
		}else {
			list->head = list->head->next;
		} 
	}else{
			Node *tmp = list->head;
				while(tmp !=NULL && tmp->next !=node){
					tmp =tmp->next;
				} 
			if (tmp !=NULL){
				tmp->next = node->next;
			}
				}
		free(node);
		}
	Node *getNode(LinkedList *list,COMPARE compare,void* data){
		Node *node = list->head;
		while (node !=NULL){
			if (compare(node->data,data) == 0){
				return node;
			}
			node = node->next;
		}
		return NULL;
	}
void displayLinkList(LinkedList *list,DISPLAY display){
	printf("\nLinked List\n");
	Node *current = list->head;
	while (current != NULL){
		display(current->data);
		current = current->next;
	}
}
int compareEmployee(Employee *e1,Employee *e2){
	return strcmp(e1->name,e2->name);
}
int displayEmployee(Employee* employee){
	printf("%s\t%d\n",employee->name,employee->age);
}









