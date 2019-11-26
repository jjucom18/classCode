#ifndef tree_h
#define tree_h

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSize 100

typedef char dataType;
typedef struct _TreeNode{
dataType data;
struct _TreeNode *left,*right;
}TreeNode;
void buOrder(TreeNode *t);
void CreatTree(TreeNode *t,dataType x);
void PreOrder(TreeNode *t);
void InOrder(TreeNode *t);
void PostOrder(TreeNode *t);
void LevelOrder(TreeNode *t);


#endif
