#ifndef shiyan5_h
#define shiyan5_h
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef int dataType;
typedef struct  _TreeNode{
	dataType data;
	struct _TreeNode *left, *right;
}TreeNode;
typedef struct _Tree{
	TreeNode *root;
}Tree;
void CreateTree(Tree *tree, dataType data);
void PreOrder(TreeNode *tree);								//先序遍历二叉树
void InOrder(TreeNode *tree);								//中序遍历二叉树
void PostOrder(TreeNode *tree);								//后序遍历二叉树
void LevelOrder(TreeNode *tree);							//以层次遍历二叉树


#endif
