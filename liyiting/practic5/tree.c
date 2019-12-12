#include "tree.h"
#include <malloc.h>

void createTree(TreeNode *&t,dataType x)
{
	dataTypa d;
	scanf("%c",&d);
	if (d == x) {
		t = NULL;}
	else{
		t = (TreeNode*)malloc(sizeof(TreeNode));
		t ->data = d;
		createTree(t->left,x);
		createTree(t->right,x);
	}
}
void preOrder(TreeNode *t)
{
	if (t){
		printf("%c",t->data);
		preOrder(t->left);
		preOrder(t->right);
	}
}
void inOrder(TreeNode *t)
{
	if (t){
		inOrder(t->left);
		printf("%c",t->data);
        	inOrder(t->right);
	}
}
void postOrder(TreeNode *t)
{
	if (t){
		postOrder(t->left);
		postOrder(t->right);
		printf("%c",t->data);
	}
}


void levelOrder(TreeNode *t)
{
	TreeNote *q[MaxSize];
	int front=0,rear=0;
	treenode *p;
	if(t == NULL) return;
	q[rear] = t; 
	rear = (rear+1)% MaxSize;
	while (front != rear){
		p = q[front];
		front =(front+1)%MaxSize;
		printf("%c",p->data);
		if (p->left){
			q[rear] = p->left;
			rear = (rear +1)%MaxSize;
		}
        	if (p->right){
			q[rear] = p->right;
			rear = (rear +1)%MaxSize;
		}
	}
}




