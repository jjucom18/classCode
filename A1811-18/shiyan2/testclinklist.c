#include "linklist.c"

	int main(int argc, char **argv)
{
	int data;
	char flat;
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	int DataArr[] = {1,2,3,4,5,6,7,8,9,10};
	initList(list);
		for (int i = 0; i < (sizeof(DataArr)/sizeof(DataArr[0])); i++){
		addHead(list, DataArr[i]);
		}

		for (int i = 0; i < (sizeof(DataArr)/sizeof(DataArr[0])); ++i){
		addTail(list,DataArr[i]);
		}
	displayList(list);
	printf("\n请输入你要删除的数据\n");
	scanf("%d",&data);
	delNode(list,FindData(list,data));
	displayList(list);
	printf("\n");


	return 0;
}
