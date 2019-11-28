#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>

#define Maxsize 100
typedef char dataType; 
typedef struct TreeNode{
	dataType data;
	struct TreeNode *left,*right;
}TreeNode;

void CreateTree(TreeNode *t,dataType x);
void PreOrder(TreeNode *t);//先序遍历二叉树
void InOrder(TreeNode  *t);//中序遍历二叉树
void PostOrdef(TreeNode *t);//后序遍历二叉树
void LeveOrdef(TreeNode *t);//层次遍历二叉树



#endif
