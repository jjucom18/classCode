#ifndef shiyaner_h
#define shiyaner_h
#include <stdio.h>
#include<stdlib.h>



typedef struct _node
{
	int data;
	struct _node *next;
}Node;
typedef struct _linkedList
{
	Node *head;
	Node *tail;
	Node *current;
}LinkedList;
 
void initializeList(LinkedList *list);
void addHead(LinkedList *list, int data);
void addTail(LinkedList *list, int data);
void delete(LinkedList *list,Node *node);
Node *getNode(LinkedList *list,int data);
void displayList(LinkedList *list);
#endif




#include"shiyaner.c"


int main(int argc, char **argv){
	int data;
	char flat;
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	int DataArr[] = {1,2,3,4,5,6,7,8,9};
	initializeList(list);
	printf("插入节点请输入h\n");
	scanf("%c",&flat);
	if (flat =='h' || flat =='H')
{

	for (int i = 0;i <(sizeof(DataArr)/sizeof(DataArr[0])); ++i){
		addHead(list, DataArr[i]);
	}
}else
if (flat == 't'|| flat == 'T'){
	for (int i=0;i <(sizeof(DataArr)/sizeof(DataArr[0])); ++i){
		addTail(list,DataArr[i]);
	}
}
displayList(list);
printf("\n请输入你要删除的数据\n");
scanf("%d",&data);
delete(list,getNode(list,data));
printf("删除成功 ！\n");
displayList(list);
printf("\n");



rturn 0;
} 

