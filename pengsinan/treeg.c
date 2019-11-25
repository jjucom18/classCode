#include<stdio.h>
#include<malloc.h>
#include "treeg.h"

void CreateTree(TreeNode *t ,dataType x){
	dataType d ;
	scanf("%c" , &d);
	if (d == x) {
		t = NULL ;
	} else {
		t = (TreeNode *)malloc(sizeof(TreeNode));
		t -> dataType = d ;
		CreateTree (t -> left , x);
		CreateTree (t -> right , x);
		
	}
}
void InOrder (TreeNode *t) {
	if (t) {
		InOrder(t -> left);
		printf("%c" , t -> dataType);
		InOrder (t -> right) ;
	}
}

void PostOrder(TreeNode *t) {
	if (t) {
		PostOrder(t -> left) ;
		PostOrder(t -> right) ;
		printf("%c" , t -> dataType);
	}
}

void LevelOrder(TreeNode *t) {
	TreeNode *q[MaxSize];
	int front = 0 ,rear = 0 ;
	TreeNode *p ;
	if (t == NULL) return ;
	q[rear] = t;
	rear = (rear + 1) % MaxSize ;
	while (front != rear) {
		p = q[front] ;
		front = (front + 1) % MaxSize ;
		printf ("%c" , p -> dataType) ;
		if (p -> left) {
			q[rear] = p -> left ;
			rear = (rear + 1) % MaxSize ;
		}
	}
}
