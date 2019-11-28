#ifndef testTree_h
#define testTree_h
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MaxSize 100
typedef char dataType;

struct TreeNode {
	dataType data;
 struct TreeNode *left,*right;
};

void CreateTree(struct TreeNode *t,dataType x)
{dataType d;
	scanf("%c",&d);
	if(d==x){
		t=NULL;}
	else{
		t=(struct TreeNode*)malloc(sizeof(struct TreeNode));
		t->data=d;
		CreateTree(t->left,x);
		CreateTree(t->right,x);}
}
void PreOrder(struct TreeNode *t)
{if(t) {printf("%c",t->data);
	PreOrder(t->left);
	PreOrder(t->right);}
}
void InOrder(struct TreeNode *t)
{if(t) {InOrder(t->left);
	printf("%c",t->data);
	InOrder(t->right);}
}
void PostOrder(struct TreeNode *t)
{if(t) {PostOrder(t->left);
	PostOrder(t->right);
	printf("%c",t->data);}
}
void LevelOrder(struct TreeNode *t)
{struct TreeNode *q[MaxSize];
	int front=0,rear=0;
	struct TreeNode *p;
	if (t==NULL)
		return;
	q[rear]=t;
	rear=(rear+1)%MaxSize;
	while (front!=rear){
		p=q[front];
		front=(front+1)%MaxSize;
		printf("%c",p->data);
		if(p->left) {
			q[rear]=p->left;
			rear=(rear+1)%MaxSize;}
		if(p->right) {
			q[rear]=p->right;
			rear=(rear+1)%MaxSize;


#endif
