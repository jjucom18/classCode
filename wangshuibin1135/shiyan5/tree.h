#include<stdio.h>
#include<stdlib.h>
#define MaxSize  100

typedef struct  node
{ 
	char data;
	struct node* Lchild;
	struct node* Rchild;
}bitnode;   //创建二叉树


bitnode* CreatBiNode();			//建立一颗二叉树 
void PreOrder(bitnode* node);	//先序遍历 
void InOrder(bitnode* node);	//中序遍历 
void PostOrder(bitnode* node);	//后序遍历
void LevelOrder(bitnode* node);  //层次顺序遍历
