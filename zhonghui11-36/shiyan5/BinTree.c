#include"BinTree.h"

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
