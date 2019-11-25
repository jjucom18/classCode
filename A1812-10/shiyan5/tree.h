#ifndef __TREE_H__
#define __TREE_H__
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100

typedef char dataType;
struct TreeNode {
	int t;
	datatype data;
	TreeNode *left, *right;
};

void CreateTree();
void PreOrder();
void InOrder();
void PostOrder();
void LeveOrder();


#endif
