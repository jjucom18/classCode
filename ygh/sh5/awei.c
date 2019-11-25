#include <stdio.h>
#include <malloc.h>
#define ManSize 100

typedef char dateType;
struct TreeNode{
	dataType date;
	TreeNode *left, *right;
};

//创建二叉树
//以先序序列输入各节点的数据。某节点的左子树或右子树为空时，输入一个特定的值x
void CreateTree(TreeNode *&t,	dataType x) {
	dataType d;
	scanf("%c",&d);
	if(d == x) {
		t = NULL;
	} else{
		t = (TreeNode*)malloc(sizeof(TreeNode));
		t->data = d;
		CreateTree(T->left, x);
		CreateTree(t->right, x);
	}
}

//先序遍历二叉树
void PreOrder(TreeNode *t) {
	if (t) {
		printf("%c",t->data);
		PreOrder(t->left);
		PreOrder(t->right);
	}
}

//中序遍历二叉树
void InOrder(TreeNode *t) {
	if (t) {
		InOrder(t->left);
		printf("%c",t->data);
		InOrder(t->right);
	}
}
//后序遍历二叉树
void PostOrder(TreeNode *t) {
	if (t) {
		PreOrder(t->left);
		PreOrder(t->right);
		printf("%c",t->data);
	}
}
//以层次顺序遍历二叉树
void LevelOrder(TreeNode *t) {
	TreeNode *q[ManSize];
	int front=0,rear=0;
	TreeNode *p;
	if (t == NULL) return;
	q[rear] = t;
	rear = (rear+1) % ManSize;
	while (front != rear) {
		p = q[front];
		front = (front+1) % ManSize;
		printf("%c",p->data);
		if (p->left) {
			q[rear] = p->left;
			rear = (rear+1) % ManSize;
		}
		if (p->right) {
			q[rear] = p->right;
			rear = (rear+1) %ManSize;
		}
	}
}

int main() {
	TreeNode *t;
	printf("请按先序序列输入各节点的字符，某节点的左子树或右子树为空时输入一个字符#。\n")
		printf("如输入ABD#G###CE##F##\n");
	CreateTree(t,'#');
	printf("先序遍历为:");
	PreOrder(t);
	printf("\n");
	printf("中序遍历为:");
	InOrder(t);
	printf("\n");
	printf("后续遍历为:");
	PostOrder(t);
	printf("\n");
	printf("层次遍历为:");
	LevelOrder(t);
	printf("\n");
}
