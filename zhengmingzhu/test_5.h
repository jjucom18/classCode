#ifndef test_5_h
#define test_5_h
#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100

typedef char dataType;
typedef struct _TreeNode{
	
	dataType data;
	struct _TreeNode *left,*right;
	
}TreeNode;

void CreatTree(TreeNode *t,dataType x);
void PreOrder(TreeNode *t);
void InOrder(TreeNode *t);
void PostOrder(TreeNode *t);
void LevelOrder(TreeNode *t);



#endif
