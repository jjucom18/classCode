#include "list.h"

List *initSeq(){
	List *ptrList = NULL;
	*ptrList = (List *)malloc(sizeof(List));
	if(NULL == *ptrList){
		printf("fail!\n");
		return NULL;
	}
	(*ptrList)->size = 0;
	printf("fnish!\n");

	return *ptrList;
}

int getLenSeq(List L){
	return L.size;
}

DataType get(List L, int i){
	return L.data[i - 1];
}

int searchSeq(List L, DataType d){
	int i = 0;
	while(i < L.size){
		if(L.data[i] == d){
			return i;
		}
		i++;
	}

	return -1;
}

void insertSeq(List* L, int i, DataType d){
	if(fullSeq(*L)){
		printf("seq full!\n");
	}
	if(i > 0 && i <= L->size){
		for(int j = i - 1; j < L->size; j++){
			L->data[j + 1] = L->data[j];
		}
		L->data[i - 1] = d;
	}
	L->size++;

	return;
}

