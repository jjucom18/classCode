#ifndef Bitree_h
#define Bitree_h
#include <stdio.h>
#include <malloc.h>

#define MaxSize 100

typedef char datatype;
typedef struct _TreeNode{
	datatype datatype;
	struct _TreeNode *left,*right;
}TreeNode;

void CreateTree(TreeNode *t,datatype x);   //创建二叉树
void PreOrder(TreeNode *t);   //先序遍历
void InOrder(TreeNode *t);   //中序遍历
void PostOrder(TreeNode *t);   //后序遍历
void LevelOrder(TreeNode *t);   //以层次顺序遍历

#endif