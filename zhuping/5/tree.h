#ifndef tree_h
#define tree_h

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize 100

typedef char dataType;
struct TreeNode{
	dataType data;
	TreeNode *left,*right;
}TreeNode;

void PreOrder(t); 
void InOrder(t) ;
void PostOrder(t); 
void LevelOrder(t); 

#endif
