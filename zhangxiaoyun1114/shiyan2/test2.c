#include<stdio.h>
#include<stdlib.h>

typedef struct{
datatype data[MAXSIZE];
int last;
}SeqList;
SeqList *init_SeqList() {
	SeqList *L;
	L=(SeqList*)malloc(sizeof(SeqList));
	L->last=-1;
	return L;
}
main(){
	SeqList *L;
	L=init_SeqList();
}
int Insert_SeqList(SeqList *L,int i,datatype x) {
	int j;
	if(L->last=MAXSIZE-1){
		printf("list is full");
		return(-1);
	}
	for(j=L->last;j>=i-1;j--;)
		L->data[j+1]=L->data[j];
	L->data[i-1] =x;
	L->last++;
	return(1);
}
int Delete_SeqList(SeqList *L,int i){
	int j;
	for(j=i,j<L->last;j++)
		L->data[j-1]=L->data[j];
	L->last--;
		return(1);
}
int Location_SeqList(SeqList *L,datatype x){
	int i=0;
	while(i<=L->last&&L->data[i]!=x)
		i++;
	if(i>L->last)
		return -1;
	else return i;
}
void OutSeqList(SeqList L){
	ListNode *L;
	L=head;
	printf("\n当前单链表的数据为：")
	while(L!=NULL){
		printf("%d",L->data);
		L=L->next;
	}
}
