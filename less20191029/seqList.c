#include "seqList.h"

SeqList *initList(){										//初始化列表
	SeqList *list = (SeqList *)malloc(sizeof(SeqList));
	list->last = -1;

	return list;
} 

bool emptyList(SeqList *list){								//判断表是否为空
	return list->last == -1;
} 

bool fullList(SeqList *list){								//判断表是否已满
	return list->last == MaxSize - 1;
} 

void insertElementList(SeqList *list, int k, DataType data){//在表的指定位置插入值为data的元素，
	if(fullList(list)){
		printf("list is full\n");
	}
	if(k < 1 || k > list->last + 2){
		printf("local error!\n");
	}
	for(int i = list->last; i >= k - 1; i--){
		list->data[i + 1] = list->data[i];
	}
	list->data[k - 1] = data;
	list->last++;

	return;
} 

int searchLocalList(SeqList *list, DataType data){			//查找指定值元素，返回下标
	int local = -1;
	for(int i = 0; i < list->last + 1; i++){
		if(data == list->data[i]){
			local = i + 1;
		}
	}

	return local;
} 

DataType searchElementList(SeqList *list, int k){			//查找制定位置的元素，返回元素值
	return list->data[k - 1];
} 

void delLocalList(SeqList *list, int k){					//删除制定位置的元素
	if(emptyList(list)){
		printf("list is empty\n");
	}
	if(k < 1 || k > list->last + 1){
		printf("local error!\n");
	}
	for(int i = k - 1; i < list->last + 1; i++){
		list->data[i] = list->data[i + 1];
	}
	list->last--;

	return;
} 

void delElementList(SeqList *list, DataType data){			//删除指定值的元素
	int result = searchLocalList(list, data);
	if(-1 == result){
		printf("no element!\n");
		return;
	}
	delLocalList(list, result);

	return;
} 

void outList(char* msg, SeqList *list){
	printf("%s: \n", msg);
	for(int i = 0; i < list->last + 1; i++){
		printf("%d\t", list->data[i]);
	}
	printf("\n");

	return;
} 
