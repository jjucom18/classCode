#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAXSIZE 10
typedef int datatype;
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
void Insert_SeqList(SeqList *L,int i,datatype x) {
	int j;
	if(L->last=MAXSIZE-1){
		printf("list is full");
		return(-1);
	}
	for(j=L->last;j>=i-1;j--);
		L->data[j+1]=L->data[j];
	    L->data[i-1] =x;
	    L->last++;
	return(1);
}
void Delete_SeqList(SeqList *L,int i){
	int j;
	for(j=i,j<L->last;j++;);
		L->data[j-1]=L->data[j];
	    L->last--;
		return(1);
}
void Location_SeqList(SeqList *L,datatype x){
	int i=0;
	while(i<=L->last&&L->data[i]!=x)
		i++;
	if(i>L->last)
		return -1;
	else return i;
}
void Output_SeqList(SeqList *L,int i){
    printf("顺序表为：\n");
	while(i=0,i<last;i++;);
    printf("%d",data[i]);
}
int main(){
	SeqList *L=init_SeqList();
	Insert_SeqList(L,1,5);
	Insert_SeqList(L,1,10);
	Delete_SeqList(L,2);
    Insert_SeqList(L,1,25);
	Location_SeqList(L,25);
	Output_SeqList(L);

}
