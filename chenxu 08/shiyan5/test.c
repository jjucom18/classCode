#define MaxSize 100
#include<stdio.h>
#include<malloc.h>

typedef struct _TreeNode
{
	char element;
	struct _TreeNode *lchild;
	struct _TreeNode *rchild;
}TreeNode;


TreeNode* binaryTree_Create();
void pre_OrderTraverse(TreeNode *t);
void mid_OrderTraverse(TreeNode *t);
void post_OrderTraverse(TreeNode *t);
void leve_OrderTraverse(TreeNode *t);


TreeNode* binaryTree_Create()
{
	TreeNode *t;
	char ch;
	scanf("%c",&ch);
	if( ch == '#' )
	{
		t = NULL;
	}
	else
	{ 
		t = malloc(sizeof(TreeNode));
		t->element = ch;
		t->lchild = binaryTree_Create();
		t->rchild = binaryTree_Create();
	}
	return t;
}

void pre_OrderTraverse(TreeNode *t)
{
	if(t)
	{
		printf("%c", t->element);
		pre_OrderTraverse( t->lchild );
		pre_OrderTraverse( t->rchild );
	}
}

//LDR traverse
void mid_OrderTraverse(TreeNode *t)
{
	if(t)
	{
		mid_OrderTraverse(t->lchild);
		printf("%c", t->element);
		mid_OrderTraverse(t->rchild);
	}
}

//LRD traverse
void post_OrderTraverse(TreeNode *t)
{
	if(t)
	{
		post_OrderTraverse(t->lchild);
		post_OrderTraverse(t->rchild);
		printf("%c", t->element);
	}
}
void  leve_OrderTraverse(TreeNode *t){
	TreeNode *q[MaxSize];
	int front=0,rear=0;
	TreeNode *p;
	if(t==NULL) return ;
	q[rear]=t;
	rear=(rear+1)%MaxSize;
	while(front !=rear){
		p=q[front];
		front=(front+1)%MaxSize;
		printf("%c",p->element);
		if(p->lchild){
			q[rear]=p->lchild;
			rear=(rear+1)%MaxSize;
			
		}
		if(p->rchild){
			q[rear]=p->rchild;
			rear=(rear+1) % MaxSize;
			
		}
		
}
}
int main()
{

	printf("请按先序输入各节点字符，某节点的左子树或右子树为空时输入一个字符#。\n");
	//printf("如输入ABC#G###CE##F##\n");
	TreeNode *t = binaryTree_Create();
	printf("\n先序遍历结果：\n"); 
	pre_OrderTraverse( t );
	printf("\n中序遍历结果：\n");
	mid_OrderTraverse(t);
	printf("\n后序遍历结果：\n"); 
	post_OrderTraverse(t);
	printf("\n层序遍历结果：\n"); 
	leve_OrderTraverse(t);
	printf("\n");
	
	
	return 0;
}
