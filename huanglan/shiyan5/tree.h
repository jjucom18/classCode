#ifndef tree_h
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char dataType;
typedef struct TreeNode{
	dataType data;
struct Tree *left,*right;
}TreeNode;
void PreOrder(TreeNode *t);
void InOrder(TreeNode *t);
void PostOrder(TreeNode *t);
void LevelOrder(TreeNode *t);
#endif
