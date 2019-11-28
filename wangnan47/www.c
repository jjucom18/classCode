#define tree_h
#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
  typedef char dataType;
  typedef struct _TreeNode {
	  dataType data;
	  struct_TreeNode *left, *right;
  } TreeNode;

void CreateTree(TreeNode *tree, dataType x); //创建二叉树
void PreOrder(TreeNode *tree);  //先序遍历二叉树
void InOrder(TreeNode *tree); //中序遍历二叉树
void PostOrder(TreeNode *tree);  //后序遍历二叉树
void LevelOrder(TreeNode *tree); //以层次遍历二叉树
#endif

#include<stdio.h>
void CreateTree(TreeNode *tree, dataType x) 
{
	dataType data;
	scanf("%c", &data);
	if (data == x) {
		tree = NULL;
	} else {
		tree = (TreeNode*)malloc(sizeof(TreeNode));
		tree->data = data;
		CreateTree(tree->left, x);
		CreateTree(tree->right, x);
	}
return;
}

//先序遍历二叉树
void PreOrder(TreeNode *tree) {
	if (tree) {
		printf("%c\t", tree->data);
	    PreOrder(tree->left);
		PreOrder(tree->right);
   } 
	return;
}

//中序遍历二叉树
void InOrder(TreeNode *tree) {
	if (tree) {
		InOrder(tree->left);
		printf("%c", tree->data);
		InOrder(tree->right);
	}
	return;
}

//后序遍历二叉树
void PostOrder(TreeNode *t) {
	if (tree) {
		PostOrder(tree->left);
		PostOreder(tree->right);
		printf("%c", tree->data);
	}
	return;
}

//以层次顺序遍历二叉树
void LevelOrder(TreeNode *tree) {
	TreeNode *node[MaxSize];
	int front=0, rear=0;
	TreeNode *tmp;
	if (tree == NULL) return;
	node[rear] = tree;
	rear = [rear+1] % MaxSize;
	while (front != rear) {
	tmp = node[front];
		front = (front+1) % MaxSize;
		printf("%c\t", tmp->data);
		if (tmp->left) {
			node[rear] = tmp->left;
			rear = (rear+1) % MaxSize;
		}
		if (tmp->right){
			node[rear] = tmp->right;
			rear = (rear+1) % MaxSize;
		}
	}
	return;
}

