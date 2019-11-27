#include <stdio.h>
#include <iostream>


#include <queue>
#include <stack>
#include <malloc.h>
#define SIZE 100
using namespace std;
typedef namespace std;//定义二叉树节点结构
{ 
char data;//数据域
struct BiTNode*lchild,*rchild;//左右孩子指针域
}BiTNode,*BiTree;
int visit(BiTree t);
void CreateBiTree(BiTree &T);//生成一个二叉树
void PreOrder(BiTree);//递归先序遍历二叉树
void inOrder(BiTree);//递归中序遍历二叉树
void PostOrder(BiTree);//递归后序遍历二叉树

