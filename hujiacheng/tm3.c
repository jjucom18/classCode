#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef struct{
		int n ;//线性链表的长度
		int maxsize;
		int *element;//线性链表的首地址
} SeqList;
SeqList ptr_arr;//头结点
 int Init(SeqList *ptr_arr,int maxsize) {
	 ptr_arr->maxsize = maxsize;
	 ptr_arr->n = 0;
	 ptr_arr->element = NULL;
	 ptr_arr=(SeqList*) malloc(maxsize*sizeof(int) ) ;
	 if(ptr_arr->element) 
		 return true;
	 else
		 return false;
 } 
int insert(SeqList *ptr_arr,int i,int x) {
	int j;
	if(i<-1|| i>ptr_arr->n-1) 
		return false;
	if(ptr_arr->n == ptr_arr->maxsize) {
	ptr_arr = (SeqList*) realloc(ptr_arr,2*ptr_arr->maxsize*sizeof(int) ) ;
	free(ptr_arr) ;
	} 
	for(j=ptr_arr->n;j>i;j--) 
		ptr_arr->element[j+1]  = ptr_arr->element[j] ;
	ptr_arr->element[i+1]  = x;
	ptr_arr->n = ptr_arr->n+1;
	return true;
} 
 void Output(SeqList *ptr_arr) {
	 int i=0;
	 if(!ptr_arr->n) 
		 printf("表为空") ;
	 else
		 for(i;i<ptr_arr->n;i++) 
			 printf("%d%d\n",ptr_arr,ptr_arr[i] ) ;
 } 
void main() {

	int i=0,maxsize,x,h;
	SeqList ptr_arr;
	printf("请输入线性表的最大长度maxsize\n") ;
	scanf("%d\n",&maxsize) ;
	Init(&ptr_arr,maxsize) ;
	printf("请输入插入的值(整型) :x 循环的步长:h\n") ;
	for(i;i<maxsize-1;i=i+h) 
	{scanf("%d\n",&x) ;
		insert(&ptr_arr,i-1,x) ;
		scanf("%d\n",&h) ;
	} 
	Output(&ptr_arr) ;
} 
