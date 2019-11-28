#include"Tree.h"

void CreateTree(TreeNode *&t,dataType x){
	dataType d;
	scanf("%c",&d);
	if(d==x){
		t=NULL;
	}else{
		t=(TreeNode*)malloc(sizeof(TreeNode));
		t->data=d;
		CreateTree(t->left,x);
		CreateTree(t->right,x);
	}
}
//先序遍历二叉树
void PreOrder(TreeNode *t){
	if(t){
		printf("%c",t->data);
		PreOrder(t->left);
		PreOrder(t->right);
	}
}
//中序遍历二叉树

void InOrder(TreeNode *t){
	if(t){
		InOrder(t->left);
		printf("%c",t->data);
		InOrder(t->right);
	}
}
//后序遍历二叉树

void PostOrder(TreeNode *t){
	if(t){
		PostOrder(t->left);
		PostOrder(t->right);
		printf("%c",t->data);
	}
}
//以层次顺序遍历二叉树
void LevelOrder(TreeNode *t){
	TreeNode *q[MAXSIZE];
	int front=0,rear=0;
	TreeNode *p;
	if(t==NILL) return;
q[rear]=t;
rear=(rear+1)%MAXSIZE;
while(front!=rear){
	p=q[front];
	front=(front+1)%MAXSIZE;
	printf("%c",p->data);
	if(p->left){
		q[rear]=p->left;
		rear=(rear+1)%MAXSIZE;
	}
	if(p->right){
		q[rear]=p->right;
		rear=(rear+1)%MAXSIZE;
	}
}
	}

