#include <stdio.h>
#include <malloc.h>
#define MaxSize 100

typedef char dataType;
typedef struct TreeNode {
	dataType data;
	struct TreeNode *left, *right;
}TreeNode;

//创建二叉数
//以先序序列输入各节点的数据。某节点的左指数或右指数为空时，输入一个特点的值x
void CreateTree(TreeNode *t,dataType x)
{
	dataType d;
	scanf("%c",&d);
	if (d == x){
		t=NULL;
	}else{
		t= (TreeNode *)malloc(sizeof(TreeNode ));
		t->data = d;
		//printf("*");
		CreateTree (t->right,x);
		printf("*");
		CreateTree (t->left,x);
	}
}

//先序遍历二叉树
void PreOrder(TreeNode  *t){
	if (t){
		printf("%c",t->data);
		PreOrder(t->left);
		PreOrder (t->right);
	}
}

//中序遍历二叉树
void InOrder(TreeNode  *t){
	if (t) {
		InOrder (t->left);
		printf("%c",t->data);
		InOrder (t->right );
	}
}

//后序遍历二叉树
void PostOrder(TreeNode  *t){
	if (t){
		PreOrder (t->left);
		PreOrder (t->right);
		printf("%c",t->data);
	}
}

//以层次顺序遍历二叉树
void LevelOrde(TreeNode  *t) {
	TreeNode  *q[MaxSize ];
	int front=0,rear=0;
	TreeNode  *p;
	if (t == NULL ) return;
	q[rear] = t;
	rear = (rear+1) % MaxSize ;
	while (front != rear){
		p = q[front];
		front = (front +1) % MaxSize ;
		printf("%c",p->data);
		if (p->left){
			q[rear] = p->left;
			rear = (rear+1) % MaxSize ;
		}
		if(p->right){
			q[rear] = p->right;
			rear = (rear+1) % MaxSize;
		}
	}
}

int main(){
	TreeNode  *t;
	printf(
			"请按先序序列输入各节点的字符，某节点的左子树或右子树为空时输入一个字符#。\n");
	printf("如输入ABD#G###CE##F##\n");
	CreateTree(t,'#');
	//printf("*");
	printf("先序遍历为：");
	PreOrder(t);
	printf("\n");
	printf("中序遍历为: ");
	InOrder(t);
	printf("\n");
	printf("后序遍历为：");
	PostOrder(t);
	printf("\n");
	printf("层序遍历为：");
	LevelOrde(t);
	printf("\n");
}
