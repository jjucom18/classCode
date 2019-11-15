#include <stdio.h>
#include <malloc.h>
 
typedef int ElemType;
typedef struct Node {
	    ElemType data;
	    struct Node *next;
}Node,*LinkedList;


LinkedList LinkedListInit() {
	    Node *L;
	        L = (Node *)malloc(sizeof(Node));
		if(L == NULL) {
		printf("failure\n");
	}
		L->next = NULL;
		return L;
LinkedList LinkedListCreatH() {
	Node *L;
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
	ElemType x;
	while(scanf("%d",&x) != EOF) {
	Node *p;
	p = (Node *)malloc(sizeof(Node));
	p->data = x;
	p->next = L->next;
	L->next = p; 
}
return L; 
}
LinkedList LinkedListCreatT() {
	Node *L;
	L = (Node *)malloc(sizeof(Node)); 
	L->next = NULL;
	Node *r;
	r = L;
	ElemType x;
	while(scanf("%d",&x) != EOF) {
	Node *p;
	p = (Node *)malloc(sizeof(Node));
	p->data = x;
	r->next = p; 
	r = p; 
}
	r->next = NULL; 
	return L;   
}
LinkedList LinkedListDelete(LinkedList L,ElemType x){
	Node *p,*pre;
	p = L->next;
	while(p->data != x){
	pre = p; 
	p = p->next;
}
	pre->next = p->next;
	free(p);
return L;
	}

int main() {
	LinkedList list,start;
	printf("please input data:"); 
	list = LinkedListCreatH();
	for(start = list->next; start != NULL; start = start->next) {
	printf("%d ",start->data);
}
    printf("\n");
        int i;
	ElemType x;
	printf("pleas input data location:");
	scanf("%d",&i);
	printf("please input the value of the data:");
	scanf("%d",&x);
LinkedListInsert(list,i,x);
	for(start = list->next; start != NULL; start = start->next) {
	printf("%d ",start->data);
	}
        printf("\n");
        printf("please input the data you want to delete:");
	scanf("%d",&x);
	LinkedListDelete(list,x); 
	for(start = list->next; start != NULL; start = start->next) {
	printf("%d ",start->data);
	}
        printf("\n");
        return 0;
}
