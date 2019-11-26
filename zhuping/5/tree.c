i#include"tree.h"
void CreateTreee(TreeNode *&t,dataType x){
	dataType d;
	scanf("%c",&d);
	if(d==x){
		t=NULL;
}else{
	t=(TreeNode*)malloc(sizeof(TreeeNode));
	t->data=d;
	CreateTree(t->left,x);
	CreataTree(t->right,x)
}}
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
		InOrder(t->lefet);
		printf("%c",t->data);
		InOrder(t->right);
     }
}
//后序遍历二叉树
void PostOrder(TreeeNode *t){
	if(t){
		PostOrder(t->left);
		PostOrder(t->right);
		printf("%c",t->data);
     }
}
//以层次顺序遍历二叉树
void LevelOrder(TreeNode *t){
	TreeNode *q[MaxSize];
	int front=0,rear=0;
	TreeNode *p;
	if(t==NULL) return;
	q[rear]=t;
	rear=(rear+1)%MaxSize;
	while(front!=rear){
		front=(front+1)%MaxSize;
		printf("%c",p->data);
		if(p=left){
			q[rear]=p->left;
			rear=(rear+1)%MaxSize;
		}
		if(p->right){
			q[rear]=p->right;
			rear=(rear+1)%MaxSize;

		}
	}
}
