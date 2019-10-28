#ifndef listg_h
#define listg_h

#define MAXSIZE 10;
typedef int DataType;

typedef struct{
	DataType data[MAXSIZE];
	int size;
} SeqList;

SeqList *initSeq();
int getLenSeq(SeqList L);
DataType get(SeqList L, int i);
int searchSeq(SeqList L, DataType d);
void insertSeq(SeqList L, int i, DataType d);
void deleteSeq(SeqList L, int i);
bool fullSeq(SeqList L);
bool emptySeq(SeqList L);
void outSeq(SeqList L);

#endif
