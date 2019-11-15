#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
	void *data;
	struct _node *next;
} Node;
typedef struct _linkedList{
	Node *head;
	Node *tail;
	Node *current;
} LinkedList;
void initList(LinkedList *list);
Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
  void addHead(LinkedList *list, void *data);
Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
  if(list->head == NULL){
	if(NULL == list->head){
		list->tail = node;
	}else{
		node->next = list->head;
	}
	list->head = node;
  return;
}

void addTail(LinkedList *list, void *data);
Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if(list->head == NULL){
		list->head = node;
	}else{
		list->tail->next = node;
	}
	list->tail = node;
}
void delNode(LinkedList *list, void *data);
Node *tmp = (Node *)malloc(sizeof(Node));
	tmp = list->head;
	if(*(tmp->data) == *data){
		if(tmp->next == NULL){
			list->head = list->tail = NULL;
		}else{
			list->head = list->head->next;
		}
	}else{
		while(tmp != NULL && *(tmp->data) != *data){
			tmp = tmp->next;
		}
		if(tmp != NULL){
			tmp->next = tmp->next->next;
		}
	}
  free(tmp);
  return;
}
Node *getNode(LinkedList *list, void *data)
{
Node *tmp = (Node *)malloc(sizeof(Node));
	tmp = list->head;
	if(*(tmp->data) == *data){
		return tmp;
	}else{
		while(tmp != NULL && *(tmp->data) != *data){
			tmp = tmp->next;
		}
		if(tmp != NULL){
			return tmp;
		}
	}
  return NULL;
}
void displayList(LinkedList *list);
Node *tmp = (Node *)malloc(sizeof(Node));
	tmp = list->head;
	while(tmp != NULL){
		printf("%d \t", *(tmp->data));
		tmp = tmp->next;
	}
	printf("\n");
  return;
}
int main()
{
  initList();
  for (int num = 0;;)
  {
    printf("请输入你的选项：\n");
		printf("1、在头部插入\n2、在尾部插入\n3、删除节点\n4、返回特定位置的数据\n5、输出所有内容\n0、退出\n");
		scanf("%d", &num);
		getchar();
		if (num == 1)
		{
			insertHead();
		}
		else if (num == 2)
		{
			insertTail();
		}
		else if (num == 3)
		{
			deleteNode();
		}
		else if (num == 4)
		{
			returnNode();
		}
		else if (num == 5)
		{
			showAllNode();
		}
		else if (num == 0)
		{
			break;
		}
		else
		{
			printf("输入错误！请重新输入\n");
		}
	}
         return 0;
}
