//This is c program code!
/* *=+=+=+=+* *** *=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
  * 文档信息: *** :~/classCode/zhengmingzhu/test1.c
  * 版权声明: *** :(魎魍魅魑)MIT
  * 联络信箱: *** :guochaoxxl@163.com
  * 创建时间: *** :2019年12月04日的下午12:35
  * 文档用途: *** :数据结构与算法分析-c语言描述
  * 作者信息: *** :guochaoxxl(http://cnblogs.com/guochaoxxl)
  * 修订时间: *** :2019年第48周 12月04日 星期三 下午12:35 (第338天)
  * 文件描述: *** :idibi添加
 * *+=+=+=+=* *** *+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+*/
#include "test1.h"

void initList(List * list){
    list->head = NULL;
	list->tail = NULL;
    list->current = NULL;

	return;
}		//初始化

void addHead(List * list, DataType data  ){

	Node *node = (Node *) malloc (sizeof(Node));
	node->data = data;
	node->next = NULL;

	if(list->head = NULL){
		list->tail = node;
	}else{
		node->next = list->head;
	}
	list->head = node;

	return ;
}		//头插法

void addTail(List * list, DataType data){

	Node *node = (Node *) malloc (sizeof(Node));
	node->data = data;
	node->next = NULL;

	if(list->head = NULL){
		list->head = node;
	}else{
		list->tail->next = node;
	}
	list->tail = node;
	
	return ;
}		//尾插法

void deleteNode(List *list, Node *node){
	if(node == list->head){                                        
		if(list->head->next == NULL){
			list->head = list->tail = NULL;
    }
		else{
			list->head = list->head->next;
    }
}
	else{
		Node *tmp = list->head;
		while(tmp != NULL && tmp->next != node){
			tmp = tmp->next;
    }
		if(tmp != NULL){
			tmp->next = node->next;
    }
}
	free(node);
}		//删除特定元素


Node *getNode(List *list, DataType date){
    Node *node = (Node *) malloc (sizeof(Node));
    node = list->head;

    while(node != NULL){
        if(node->data == date){
			return node;
        }else{
            node = node->next;
        }
    }
     return NULL;
}		//获得特定元素


void displayList(List *list){
    Node *node = list->head;
    int i = 0;

    while(node != NULL){
		printf("%d,%d\n", i + 1, node->data);
        node = node->next;
        i++;
    }
    printf("display finished!\n");
     
	return NULL;
}		//输出
