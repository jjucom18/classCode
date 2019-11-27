#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MaxSize 100
#define BitNode


typedef struct BitNode{
	datatype data;
	struct BitNode *left;struct BitNode *right;
}
BitNode;*BiTree;




//创建二叉树
BiTree CreateBiTree(){
	char p;BiTree T;
	scanf("%c",&p);
	if(p==''){
		T=NULL;
	}
	else{
		T=(BitNode*)malloc(sizeof(BitNode));
	T->data=p;
	T->left=CreateBiTree();
	T->right=CreateBiTree();
	}return(T);
}
//先序
void PreOrder(BiTree &T){
	if(T!=NULL){
		printf("%c",T->data);
		PreOrder(T->left);
		PreOrder(T->right);
	}
}

//中序
void InOrder(BiTree &T){
	if(T!=NULL){
		InOrder(T->left);
		printf("%c",T->data);
		InOrder(T->right);
	}
}


//后序
void PostOrder(BiTree &T){
	if(T!=NULL){
	PostOrder(T->left);
	PostOrder(T->right);
	printf("%c",T->data);
}
} 

//以层次顺序
void LevelOrder(BiTree &T){
	BiTree *q[MaxSize];
	int front=0,rear=0;
	BiTree *p;
if(T==NULL)return;
q[rear]=T;
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
void main(){
	int BiTree Ta;
	Ta=CreateBiTree();
	printf("请按先序序列输入各节点的字符，某节点的左子树或右子树为空时输入一个字符#\n");
	printf("如输入ABD#G###CE##F##\n");
	printf("先序遍历:");
	PreOrder(Ta);
	printf("\n");
	printf("中序遍历：");
	InOrder(Ta);
	printf("\n");
	printf("后序遍历：");
	PostOrder(Ta);
	printf("\n");
	printf("层次遍历：");
	LevelOrder(Ta);
	printf("\n");

}


