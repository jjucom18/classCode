#define tree_h
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
  typedef char dataType;
  typedef struct _TreeNode {
	  dataType data;
	  struct_TreeNode *left, *right;
  } TreeNode;

void CreateTree(TreeNode *tree, dataType x);
void PreOrder(TreeNode *tree);
void InOrder(TreeNode *tree);
void PostOrder(TreeNode *tree);
void LevelOrder(TreeNode *tree);
 
#endif
