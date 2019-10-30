#include "listg.h"
/*SeqList *initSeq();
int getLenSeq(SeqList L);
DataType get(SeqList L, int i);
int searchSeq(SeqList L, DataType d);
void insertSeq(SeqList L, int i, DataType d);
void deleteSeq(SeqList L, int i);
bool fullSeq(SeqList L);
bool emptySeq(SeqList L);
void outSeq(SeqList L);
*/
int main(int argc, char **argv)
{
	SeqList *ptrL = initSeq();
	if(emptySeq(*ptrL)){
		printf("Seq is empty!\n");
	}
	if(fullSeq(*ptrL)){
		printf("Seq is full!\n");
	}
	printf("Seq length: %d\n", getLenSeq(*ptrL));

	DataType arr[] = {2, 9, 8, 1, 4, 3, 7, 6, 12, 43, 56};
	int arrSize = sizeof(arr)/sizeof(arr[0]);

	for(int i = 0; i < arrSize; i++){
		insertSeq(ptrL, i + 1, arr[i]);
	}
	printf("Seq length: %d\n", getLenSeq(*ptrL));
	//outSeq(ptrL);
	printf("%d : %d\n", 8, get(*ptrL, 8));



	return 0;
}


