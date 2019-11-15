#include "test1.h"

int main(int argc,char **argv){
	int data,head,tail;
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	initList(list);
	printf("输入头插数据\n");
	scanf("%d",&head);
	addHead(list,head);
	printf("输入尾插数据\n");
	scanf("%d",&tail);
	addTail(list,tail);
	displayLinkedList(list);
	printf("输入要删除的数据\n");	
	scanf("%d",&data);
	delete(list,getNode(list,data));
	printf("已删除\n");
	displayLinkedList(list);

	return 0;
}