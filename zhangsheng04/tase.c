#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data
		struct LNode *next;
}
void LNode *LinkListInit()
{
	LNode *L;
	//L=(LNode*)malloc(sizeof(LNode));//为一个节点分配空间
	L=new LNode;
	if(L==NULL)
	{
		return NULL;
	}
	L->next=NULL;//头指针的指针域设为空
	return L；
} {

	int main()
		return 0;
} 

