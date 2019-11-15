#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
	void *data;
	struct _node *next;
} Node;

typedef struct _linkedList {
	Node *head;
	Node *tail;
	Node *current;
	int age;
} linkedList;

void initializeList(LinkedList *list)  //初始化单链表
{
	list ->head = NULL;
	list ->tail = NULL;
	list ->current = NULL;

void addHead(LinkedList *list, void* data) //给链表的头结点添加数据
{
	Node *node = (Node*) malloc(sizeof(Node));
	node ->data = data;
	if (list ->head == NULL){
		list ->tail == node;
		node ->next == NULL;
	} else {
		node ->next = list ->head;
	}
	list ->head = node;
}

void addTail(LinkedList *list, void* data) //给链表的尾结点添加数据
{
	Node *node = (Node*) malloc(sizeof(Node));
	node ->data = data;
	node ->next = NULL;
	if (list ->head == NULL) {
		list ->head = node;
	} else {
		list ->tail ->next = node;
	}
    list ->tail = node;
	}
void delete(LinkedList *list, Node *node)  //从链表删除结点
{
	if (node == list ->head) {
		if (list ->head ->next == NULL) {
			list ->head = list ->tail = NULL;
		} else {
			list ->head = list ->head ->next;
		}
	} else {
		Node *tmp = list ->head;
		while (tmp != NULL && tmp ->next != node) {
			tmp = tmp ->next;
		}
		if(tmp != NULL) {
			tmp ->next = node ->next;
		}
	}
    free(node);
	}
Node *getNode(LinkedList *list, COMPARE compare, void* data) //返回包含指定数据的结点指针
{
    Node *node = list ->head;
	  while (node != NULL) {
		  if (compare(node ->data,data) == 0){
			 return node;
		}
		node = node ->next;
	}
    return NULL;
} 
void displayLinkedList(LinkedList *list, DISPLAY display) //打印链表
{
	printf("\nLinked List\n");
	Node *current = list ->head;
	while (current != NULL) {
		display(current ->data);
		current = current ->next;
	}
}

int main(int argc,char **argv)
{
	LinkedList *list = initializelist();
	addHead(list,1,10);
	addtail(list,1,20);
	delete(list,2);
	printf("链表的元素个数为：%d\n",size(list));
	print(list);
	printf("链表的第二个元素为：%d",getNode(list,2));
	return 0;
}
