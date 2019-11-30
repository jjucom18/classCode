#ifndef Tree_h
#define Tree_h
#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100

typedef char dataType;
struct TreeNode{
	dataType data;
	TreeNode *left, *right;
};
void CreateTree(TreeNode *&t,dataType x);
void PreOrder(TreeNode *t);
void InOrder(TreeNode *t);
void PostOrder(TreeNode *t);
void LevelOrder(TreeNode *t);

#endif
