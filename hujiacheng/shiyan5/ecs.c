#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MaxSize 100


struct TreeNode{
	char data;
    	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode ;



void CreateTree(TreeNode *t,char x){//创建二叉树
	char d;
	scanf("%c",&d);
	if (d == x){
	t = NULL;
	} else {
	t = (TreeNode *)malloc(sizeof(TreeNode));
	t->data = d;
	CreateTree(t->left,x);
	CreateTree(t->right,x);
	}
}
void PreOrder(TreeNode *t){//先序
	if(t){
	printf("%c ",t->data);
	PreOrder(t->left);
	PreOrder(t->right);
	}
}
void InOrder(TreeNode *t){//中序
 	if(t){
	InOrder(t->left);
	printf("%c ",t->data);
	InOrder(t->right);
	}
}
void PostOrder(TreeNode *t){//后序
	if(t){
	PostOrder(t->left);
	PostOrder(t->right);
	printf("%c ",t->data);
	}
}
void LeavlOrder(TreeNode *t){//层次顺序
	TreeNode *q[MaxSize];
	int front=0, rear=0;
	TreeNode *p;
	if(t == NULL) return;
	q[rear]= t;
       	rear = (rear+1) % MaxSize;
	while (front != rear){
		p = q[front];
		front = (front+1) % MaxSize;
		printf("%c ",p->data);
		if(p->left){
			q[rear] = p->left;
			rear = (rear+1) % MaxSize;
		}
		if(p->right){
			q[rear] = p->right;
			rear = (rear+1) % MaxSize;
		}
	}	
}

int main(){
	TreeNode *t;
	printf("请按先序输入各字节字符，某节点的左子树或右子树为空时输入一个字符\n");
	printf("如输入ABD#G###CE##F##\n");
	t = CreateTree(t, '#');
	printf("先序：");
	PreOrder(t);
	printf("\n");
	printf("中序：");
	InOrder(t);
	printf("\n");
	printf("后序：");
	PostOrder(t);
	printf("\n");
	printf("层次顺序：");
	LeavlOrder(t);
	printf("\n");	
}
