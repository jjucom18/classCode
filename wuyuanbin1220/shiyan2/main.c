#include"shiyan2.h"


int main(int argc, char **argv){
	
	int data;
	char flat;
	Node *node;
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	int DataArr[] = {1,2,3,4,5,6,7,8,9};
	initList(list);
	printf("使用头插法请输入h，使用尾插法请输入t\n");
	scanf("%c",&flat);
	if (flat == 'h' || flat == 'H')
	{
		for (int i = 0; i < (sizeof(DataArr)/sizeof(DataArr[0])); ++i){
		addHead(list, DataArr[i]);
		}
	}else 
	if (flat == 't' || flat == 'T'){

		for (int i = 0; i < (sizeof(DataArr)/sizeof(DataArr[0])); ++i){
		addTail(list,DataArr[i]);
		}
	}
	displayList(list);
	printf("\n请输入你要删除的数据\n");
	scanf("%d",&data);
	node = FindData(list,data);
	delNode(list,node);
	printf("删除成功 ！\n");
	displayList(list);
	printf("\n");
	

	return 0;
}