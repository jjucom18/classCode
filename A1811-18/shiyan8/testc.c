#include "linklist.h"
#include "linklist.c"
int main(int argc,char **argv)
{	
	int i;
	linklist *head;
	head = (linklist *)malloc(sizeof(linklist));
	head = Init();
	printf("请输入想插入几本书：\n");
	scanf("%d",&i);
	for(int j = 0;j < i;j++){
		insert(head);
	}
	count(head);
	display(head);
	dle(head);//删除id为1的图书
	display(head);
	bubble_id(head);
	display(head);
	bubble_price(head);
	display(head);
	findByname(head);
	findByauthor_name(head);
	seacher(head);

	return 0;
}
