#include "linklist.h"


int createlist1(linklist head){
	int flag = 0;
	linklist L = NULL;
	LNode *s;
	int x;
	scanf("%d",&x);
	while(flag){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L;
		L = s;
		scanf("%d",&x);
	}
	return L;

}//在表头插入
int createlist2(linklist head){
	int flag = 0;
	linklist L = NULL;
	LNode *s,*r = NULL;
	int x;
	scanf("%d",&x);
	while(flag){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		if(L = NULL)
			L = s;
		else
			r->next = s;
		r = s;
		scanf("%d",&x);
	} 
	return L;	
};//在表尾插入
int get_linklist(linklist L,int i){
	LNode *p = L ;
	int j = 0;
	while(p->next != NULL && j < i){
		p = p->next;
		return p;
	}
}//返回某个特定的值
int dellist(linklist L ,int i){
	linklist p,s;
	p = get_linklist(L,i);
	if(p == NULL){
		printf("第i-1个结点不存在\n");
		return -1;

	}
	else
		if(p->next == NULL){
			printf("第i个结点不存在\n");
			return -1;
		}
		else {
			s = p->next;
			p->next = s->next;
			free(s);
			return 1;
		}
}//删除单链表中的地i个元素
void linklist_out(linklist head){
	linklist p;
	int i = 0;
	p = head->next;
	while(p != NULL) {
		i++;
		printf("第%d个元素是：",i);
		printf("%d\n",p->data);
		p = p->next;
			}
	printf("链表为空！\n");
}//顺序打印单链表的元素



