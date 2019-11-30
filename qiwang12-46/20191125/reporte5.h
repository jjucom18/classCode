#ifndef reporte5_h
#define reporte5_h

#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100

typedef char dataType;

typedef struct  _TreeNode{
	dataType data;
	struct _TreeNode *left, *right;
}TreeNode;

typedef struct _Tree{
	TreeNode *root;
}Tree;

void CreateTree(Tree *tree, dataType data);
void PreOrder(TreeNode *tree);								
void InOrder(TreeNode *tree);								
void PostOrder(TreeNode *tree);								
void LevelOrder(TreeNode *tree);							

#endif