#ifndef tree_h
#define tree_h
#include <stdio.h>
#include <malloc.h>
#define Maxsize 100
typedef char dataType;
struct TreeNode{
	dataType data;
	TreeNode *left, *right;
};
void CreateTree(TreeNode *&t,dataType x)
void PreOrder(TreeNode *t)
void InOrder(TreeNode *t)
void PostOrder(TreNode *t)
void LevelOrder(TreeOrder *t)
#endif
