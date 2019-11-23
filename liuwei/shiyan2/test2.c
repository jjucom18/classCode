#include"test2.h"





void initList(List *list)
{
	list->head=NULL;
	list->tail=NULL;
}


void addHead(List *list,datatype idata)
{
	Node *node=(Node *)malloc(sizeof(Node));
	node->data=idata;
	node->next=NULL;

	if(list->head==NULL){
	    list->tail=node;
	}else{
	node->next=list->head;
        }
        list->head=node;
        return;
 }

  
void addTail(List *list,datatype idata)
{
	Node *node=(Node *)malloc(sizeof(Node));
	node->data=idata;
	node->next=NULL;

	if(list->head==NULL){
		list->head=node;
	}else{
	   list->tail->next=node;}
	list->tail=node;
   	   return;
}	   


void delNode(List *list,datatype idata){

	if(list->head->data==idata){
		list->head=list->head->next;
	}
	Node *prev=list->head;
	Node *node=prev->next;
	while(node!=NULL){
		if(node->data==idata){
		  prev->next=prev->next->next;


		  return;
		}else{
	      		prev=prev->next;
			node=node->next;
		}
	}

	return;
}

Node *getNode(List *list,datatype idata){
	Node *node=(Node *)malloc(sizeof(Node));
	node=list->head;
	while(node!=NULL){
		if(node->data==idata){
			return node;
		}else{
			node=node->next;
		}
	}

	return NULL;
}

void dispList(List *list){
	Node *node=list->head;
	int i=0;
       while(node!=NULL){
 	   printf("the %dth node: %d\n",i+1,node->data);
	   node=node->next;
	   i++;
       }
        printf("disp finished!\n");


	return;
}
			




	

              


	
	


