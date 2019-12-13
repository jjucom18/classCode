#include<stdio.h>
#include<malloc.h>
#define MaxSize 100

typedef char dataType;
struct TreeNode{
dataType data;
TreeNode *left,*right;
};	//创建二叉树
void CreateTree(TreeNode *&t,dataType x){
	dataType d ;
	scanf("%C,"&d);
	if(d==x){
		t=NULL；
	}
	else{
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
TreeNode *q[MaxSize];
int front=0,rear=0;
TreeNode *p;
	if(t==NULL)return;
	q[rear]=t;
	rear=(rear+1)%MaxSize;
	while(front!=rear){
		p=q[front];
		front=(front+1)%MaxSize;
		printf("%c",p->data);
		if(p->left){
			q[rear]=p->left;
			rear=(rear+1)%MaxSize;
		}
	if(p->right){
			q[rear]=p->right;
			rear=(rear+1)%MaxSize;
		}
	
}
      }

nt main() {
    TreeNode *t;
    printf (
      "按先序序列输入各节点的字符，节点的左子树或右子树为空时输入#。 \n");
    printf ("如输入ABD#G###CE##F##\n");
    CreateTree(t, '#');
    printf("先序遍历为: ");
    PreOrder(t);
    printf("\n");
    printf("中序遍历为: ");
    InOrder(t);
    printf("\n");
    printf("后序遍历为: ");
    Postorder(t);
    Printf("\n");
    printt("层序遍历为: ");
    LevelOrder(t);
    printf("\n");
}    
