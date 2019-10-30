#include "listg.h"


SeqList *initSeq(){
	SeqList *ptrList = (SeqList *)malloc(sizeof(SeqList));
	if(NULL == ptrList){
		printf("fail!\n");
		return NULL;
	}
	ptrList->size = 0;

	return ptrList;
}

int getLenSeq(SeqList L){
	return L.size;
}

DataType get(SeqList L, int i){
	return L.data[i - 1];
}

int searchSeq(SeqList L, DataType d){
	int i = 0;
	while(i < size){
		if(L.data[i] == d){
			return i;
		}
		i++;
	}

	return -1;
}

void insertSeq(SeqList L, int i, DataType d){
	if(fullSeq(L)){
		printf("seq full!\n");
	}
	if(i > 0 && i <= L.size){
		for(int j = i - 1; j < L.size; j++){
			L.data[j + 1] = L.data[j]
		}
		L.data[i - 1] = d;
	}
	L.size++;

	return;
}

void deleteSeq(SeqList L, int i){
	if(emptySeq(L)){
		printf("faile delete!\n");
	}
	if(i > 0 && i <= L.size){
		for(int j = i - 1; j < L.size; j++){
			L.data[j] = L.data[j + 1];
		}
	}
	L.size--;

	return;
}

bool fullSeq(SeqList L){
	return L.size == MAXSIZE;
}

bool emptySeq(SeqList L){
	return L.size == 0;
}

void outSeq(SeqList L);
