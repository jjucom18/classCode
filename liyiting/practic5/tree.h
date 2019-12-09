#ifndef tree_h
#define tree_h

#include <stdio.h>
#define MaxSize 100

typedef char dataType;
struct TreeNode{
	dataType data;
	struct TreeNode *left,*right;
};

int *s = &t;
void createTree(struct TreeNode *s,dataType x)
void preOrder(struct TreeNode *t)
void inOrder(struct TreeNode *t)
void postOrder(struct TreeNode *t)
void levelOrder(struct TreeNode *t)


#endif
