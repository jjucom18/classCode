#include"1.h"
#include<stdlib.h>
int main(int argc,char **argv) {
	char *arr[]={1,2,3,4,5,6,7,8,9} ;
	LinkList *list=(LinkedList *)malloc(sizeof(LinkedList));
	initializeList(list);
	printf("成功\n");
	addHead(list,10);
	addTail(list,10);
	Node *getNode(list,6);
	delete(list,5);
	displayLinkedlist(list);
	return 0;} 
