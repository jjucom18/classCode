#include <stdio.h>
#include <malloc.h>
typedef int dataType;
typedef struct node {
	dataType data;
	struct node *next;
} LinkList;
LinkList* CreatList() {
	LinkList *head;
	head = (LinkList*)malloc(sizeof(LinkList));
	head->next = NULL;
	return head;
}//创建链表
void initializeList(LinkedList *list){
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}//初始化链表
void addHead(LinkList *list, void* data） {
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = data;
	if (list->head == NULL) {
	list->tail = node;
	node->next = NULL;
}else {
node->next = list->head;
}
list->head = node;
}//给链表的头节点添加数据
void addTail(LinkedList *list, void* data) {
        Node *node = (Node*) malloc(sizeof(Node)); 
	node->data = data;
	node->next = NULL;
	if (list->head == NULL) {
	list->head = node;
	} else {
	list->tail->next = node;
	}
	list->tail = node;
}//给链表的尾节点添加数据
void delete(LinkedList *list, Node *node) {
	if (node == list->head) {
		if (list->head->next == NULL) {
			list->head = list->tail = NULL;
		} else {
			list->head = list->head->next;
		}
	} else {
		Node *tmp = list->head;
		while (tmp != NULL && tmp->next != node) {
			tmp = tmp->next;
		}
		if (tmp != NULL) {
			tmp->next = node->next;
		}
	}
	free(node);
}//从链表删除节点
Node *getNode(LinkedList *list, COMPAREUF compare , void* data) {
	Node *node *node = list->head;
	while (node != NULL) {
		if (compare(node->data, data) == 0) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}//返回包含指定数据的节点指针
void diaplayLinkedList(LinkedList *list, DISPLAY display) {
	printf("\nLinked List\n");
	Node *current = list->head;
	while (current != NULL) {
		display(current->data);
		current = current->next;
	}
}//打印链表
int main(int argc, char **argv)
{
	int dataArr[] = {21, 34, 56, 78, 91};
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	initList(list);
}
