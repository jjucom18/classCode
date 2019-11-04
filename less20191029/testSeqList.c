#include "seqList.h"

int main(int argc, char **argv)
{
	SeqList *list = initList();
	if(emptyList(list)){
		printf("the list is empty!\n");
	}

	DataType arr[] = {99, 43, 21, 19, 36, 55, 64, 72, 81};
	int size = sizeof(arr)/sizeof(arr[0]);

	for(int i = 0; i < size; i++){
		insertElementList(list, i + 1, arr[i]);
	}
	outList("init: ", list);
	printf("%d is loacal: %d\n", 81, searchLocalList(list, 81));
	printf("local %d: is %d\n", 8, searchElementList(list, 8));
	outList("del local 8 before: ", list);
	delLocalList(list, 8);
	outList("del local 8 after: ", list);
	outList("del element 36 before: ", list);
	delElementList(list, 36);
	outList("del element 36 after: ", list);

	return 0;
}



SeqList *initList();										//初始化列表
bool emptyList(SeqList *list);								//判断表是否为空
bool fullList(SeqList *list);								//判断表是否已满
void insertElementList(SeqList *list, int k, DataType data);//在表的指定位置插入值为data的元素，
int searchLocalList(SeqList *list, DataType data);			//查找指定值元素，返回下标
DataType searchElementList(SeqList *list, int k);			//查找制定位置的元素，返回元素值
void delLocalList(SeqList *list, int k);					//删除制定位置的元素
void delElementList(SeqList *list, DataType data);			//删除指定值的元素
void outList(char *msg, SeqList *list);
