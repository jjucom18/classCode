#ifndef ercha_h
#define ercha_h
#define MaxSize 100
#include<stdio.h>
#include<malloc.h>

typedef struct _TreeNode
{
	char element;
	struct _TreeNode *lchild;
	struct _TreeNode *rchild;
}TreeNode;


TreeNode* binaryTree_Create();
void pre_OrderTraverse(TreeNode *t);
void mid_OrderTraverse(TreeNode *t);
void post_OrderTraverse(TreeNode *t);
void leve_OrderTraverse(TreeNode *t);












#endif
