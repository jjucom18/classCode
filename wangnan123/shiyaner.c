#include<stdio.h>



 void initializeList(LinkedList *List){
	 list ->head = NULL;
	 list ->tail = NULL;
	 list ->current =NULL;

 return;}
 void addHead(LinkedList *list, void* data){
	 Node *node = (Node*) malloc(sizeof(Node));
	 node->data =data;
	 if (list->head == NULL){
		 list->tail =node;
		 node->next =NULL;
	 }else {
		 node->next = list->head;
	 }
	 list->head = node;
 }
 void delelte(LinkedList *list, Node *node){
	 if (node == list->head){
		 if (list->head->next == NULL){
             list->head = list->tail = NULL;
		 }else{
			 list ->head = list ->head->next;} 

			 }else{
				 Node *tmp = list->head;
				 while (tmp !=NULL && tmp->next != node){
					 tmp =tmp->next;

				 }
				 if (tmp->next = node->next;)
			 }
		 }
	 free(node);
	 
return;
 Node *getNode(LinkedList *list,  compare , void* data){
	 Node *node = list->head;
	 while (node !=NULL){
		 if(compare(node->data, data) ==0){
			 return node;
		 }
		 node = node->next;
	 }
	 return NULL;
 }


void displayList(LinkedList *list){
	Node *tmp =list->head;
	while(tmp !=NULL){
		printf("%d\t",tmp->data);
		tmp = tmp->next;
	

