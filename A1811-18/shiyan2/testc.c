#include "linklist.c"
#include "linklist.h"
int main(int argc,char **argv)

{
	linklist head;
	head = (linklist)malloc(sizeof(LNode));
	linklist L = (linklist)malloc(sizeof(LNode));
	printf("请插入元素，输入0结束插入！\n");
	printf("头插法\n");
	createlist1(head);//头插法
	linklist_out(head);
	printf("尾插法\n");
	createlist2(head);//尾插法
	linklist_out(L);
	printf("请输入想删除第几个元素\n");
	int i;
	scanf("%d",&i);
	dellist(L,i);
	get_linklist(L,i);
	return 0;
}
