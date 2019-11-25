#include<stdio.h>
#include<malloc.h>
#include "treeg.h"

void CreateTree(TreeNode *&t ,dataType x){
	dataType d ;
	scanf("%c" , &d);
	if (d == x) {
		t = NULL ;
	} else {
		t = (TreeNode *)malloc(sizeof(TreeNode));
		t -> data = d ;
		CreateTree (t -> left , x);
		CreateTree (t -> right , x);
		
	}
}
void InOrder (TreeNode *t) {
	if (t) {
		InOrder(t -> left);
		prtint("%c" , t -> data);
		InOrder (t -> right) ;
	}
}

void PostOrder(TreeNode *t) {
	if (t) {
		PostOrder(t -> left) ;
		PostOrder(t -> right) ;
		printf("%c" , t -> data);
	}
}

void LevelOrder(TreeNode *t) {
	TreeNode *q[MaxSize];
	int front = 0 ,rear = 0 ;
	treeNode *p ;
	if (t == NULL) return ;
	q[rear] = t;
	rear = (rear + 1) % MaxSize ;
	while (front != rear) {
		p = q[front] ;
		front = (front + 1) % MaxSize ;
		print ("%c" , p -> data) ;
		if (p -> left) {
			q(rear) = p -> left ;
			rear = (rear + 1) % MaxSize ;
		}
	}
}
