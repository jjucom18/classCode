#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv)
typedef int Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *next;
}Node,*LinkList;

LinkList LinkListlnit(){
	Node *L;
	 L = (Node*)malloc(sizeof(Node));
	 if(L == NULL)
	{
     printf("申请内存空间失败\n");} 
	 L->next = NULL;
	 return 0;
}

int Insert_Head(Node *h, LinkList data) 
{

		if (h == NULL) 
		return FALSE;
		Node *node = (Node*) malloc(sizeof(Node) /sizeof(char) ) ;
		if (node == NULL) 
{

		return FALSE;
} 
					
		node->data = data;
		node->next = h->next;
							
		h->next = node;
								
		return 0;
}
void deleNode(List *list, DataType iData) {

		if(list->head->data == iData) {
        list->head = list->head->next;
} 
		Node *prev = list->head;
		Node *node = prev->next;
		while(node != NULL) {
        if(node->data == iData) {
        prev->next = prev->next->next;
        return;
      } else {
        prev = prev->next;
		node = node->next;
	  } 
	} 

		return;
} 
