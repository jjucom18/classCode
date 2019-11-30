#include"shiyan5.h"
void CreateTree(Tree *tree, dataType data){
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	if (tree->root == NULL){
		tree->root = node;
	}else{
		TreeNode *tmp = tree->root;
		while(tmp != NULL){
			if (data < tmp->data){
				if (tmp->left == NULL){
					tmp->left = node;
					return;
				}else{
					tmp = tmp->left;
				}
			}else{
				if (tmp->right ==NULL){
					tmp->right = node;
					return;
				}else{
					tmp = tmp->right;
				}
			}
		}
	}
	return;
}
void PreOrder(TreeNode *tree){
	if (tree){
		printf("%d\t",tree->data );
		PostOrder(tree->left);
		PostOrder(tree->right);
	}
	return;
}
void InOrder(TreeNode *tree){
	if (tree){
		InOrder(tree->left);
		printf("%d\t",tree->data );
		InOrder(tree->right);
	}
	return;
}
void PostOrder(TreeNode *tree){
	if (tree){
		PostOrder(tree->left);
		PostOrder(tree->right);
		printf("%d\t",tree->data );
	}
	return;
}	
void LevelOrder(TreeNode *tree){
	TreeNode *node[MaxSize];
	int front = 0, rear = 0;
	TreeNode *tmp;
	if (tree == NULL)	return;
	node[rear] = tree;
	rear = (rear + 1) % MaxSize;
	while(front != rear){
		tmp = node[front];
		front = (front + 1) % MaxSize;
		printf("%d\t",tmp->data );
		if (tmp->left){
			node[rear] = tmp->left;
			rear = (rear + 1) % MaxSize;
		}
		if (tmp->right){
			node[rear] = tmp->right;
			rear = (rear + 1) % MaxSize;
		}
	}
	return;
}
