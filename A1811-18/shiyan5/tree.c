#include "tree.h"
void CreateTree(TreeNode *t,dataType x){
	dataType d;
	scanf("%c",&d);
	if(d == x){
		t == NULL;
	}
	else{
		t = (TreeNode *)malloc(sizeof(TreeNode));
		t->data = d;
		CreateTree(t->left,x);
		CreateTree(t->right,x);

	}
}
void PreOrder(TreeNode *t){
	if(t){
		printf("%c",t->data);
		PreOrder(t->left);
		PreOrdef(t->right);
	}
}//先序遍历二叉树
void InOrder(TreeNode  *t){
	if(t){
		InOrder(t->left);
		printf("%c",t->data);
		InOrder(t->right);
	}
}//中序遍历二叉树
void PostOrdef(TreeNode *t){
	if(t){
		PostOrdef(t->left);
		PostOrdef(t->right);
		printf("%c",t->data);
	}
}//后序遍历二叉树
void LeveOrdef(TreeNode *t){
		TreeNode *q[Maxsize];
		int front = 0;
		int rear = 0;
		TreeNode *p;
		if(t == NULL)
			return;
		else{
			q[rear] = p->left;
			rear = (rear + 1) % Maxsize;

		}
		while(front != rear){
			p = q[front];
			front = (front +1) % Maxsize;
			printf("%c",p->data);
			if(p->left){
				q[rear] = p->left;
				rear = (rear + 1) % Maxsize;

			}
			if(p->right){
				q[rear] = p->right;
				rear = (rear + 1) % Maxsize;
			}
		}
	}



