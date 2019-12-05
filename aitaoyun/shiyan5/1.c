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
