#include"tree.h"

bitnode *CreatBiNode()
{
		bitnode* p;
		char ch;
		scanf("%c",&ch);
		if(ch == ' ')
		{
			p = NULL;
		 } 
		else
		{
			p = (bitnode*)malloc(sizeof(bitnode));
			p->data = ch;
			p->Lchild = CreatBiNode();
			p->Rchild = CreatBiNode();
		}
	
		return p;
	}
	



void PreOrder(bitnode *node)
{	
	if( node )
	{
		printf("%c",node->data );
		PreOrder(node->Lchild);
		PreOrder(node->Rchild);
	} 
}

void InOrder(bitnode *node)
{
	
	if(node)
	{
		
		InOrder(node->Lchild);
		printf("%c",node->data);
		InOrder(node->Rchild);
	} 

}

void PostOrder(bitnode *node)
{
	if(node)
	{
	PostOrder(node->Lchild);
	PostOrder(node->Rchild);	
	printf("%c",node->data);
	}
}

void  LevelOrder(bitnode *node)
{
    bitnode *arr[MaxSize];
	int front=0, rear=0;
	bitnode *p ;
	if (node == NULL) return;
	arr[rear] = node;
	rear = (rear+1) % MaxSize;
	while (front !=rear) {
	p = arr[front];
	front = (front+1) % MaxSize;
	printf("%c",p->data);
	if (p->Lchild) {
	    arr[rear] = p->Lchild;
		rear = (rear+1) % MaxSize;
	}
	if (p->Rchild) {
	    arr[rear] = p->Rchild;
		rear = (rear+1) % MaxSize;
	}
  }
 }
	
