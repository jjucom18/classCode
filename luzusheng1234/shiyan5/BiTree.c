#include "BiTree.h"

void CreateTree(TreeNode *t,datatype x){   //创建二叉树
	datatype d;
	scanf("%c",&d);
	if(d == x){
		t =NULL;
	}else {
		t = (TreeNode*)malloc(sizeof(TreeNode));
		t -> datatype = d;
		CreateTree(t -> left,x);
		CreateTree(t -> right,x);
	}
}

void PreOrder(TreeNode *t){   //先序遍历
	if(t){
		printf("%c\n",t -> datatype );
		PreOrder(t -> left);
		PreOrder(t -> right);
	}
}

void InOrder(TreeNode *t){   //中序遍历
	if(t){
		InOrder(t -> left);
		printf("%c\n",t -> datatype );
		InOrder(t -> right);
	}
}

void PostOrder(TreeNode *t){   //后序遍历
	if(t){
		PostOrder(t -> left);
		PostOrder(t -> right);
		printf("%c\n",t -> datatype );
	}
}

void LevelOrder(TreeNode *t){   //以层次顺序遍历
	TreeNode *q[MaxSize];
	int front = 0,rear = 0;
	TreeNode *p;
	if (t == NULL) return;
	q[rear] = t;
	rear = (rear + 1)% MaxSize;
	while(front != rear){
		p = q[front];
		front = (front + 1)%MaxSize;
		printf("%c\n",p -> datatype );
		if (p -> left){
			q[rear] = p ->left;
			rear = (rear + 1)%MaxSize;
		}
		if (p -> right){
			q[rear] = p -> right;
			rear = (rear + 1)%MaxSize;
		}
		
	}
}