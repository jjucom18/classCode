//This is c program code!
/* *=+=+=+=+* *** *=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
  * 文档信息: *** :~/classCode/zhengmingzhu/struct5.c
  * 版权声明: *** :(魎魍魅魑)MIT
  * 联络信箱: *** :guochaoxxl@163.com
  * 创建时间: *** :2019年11月25日的下午07:03
  * 文档用途: *** :数据结构与算法分析-c语言描述
  * 作者信息: *** :guochaoxxl(http://cnblogs.com/guochaoxxl)
  * 修订时间: *** :2019年第47周 11月25日 星期一 下午07:03 (第329天)
  * 文件描述: *** :自行添加
 * *+=+=+=+=* *** *+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void CreateTree(TreeNode *t,dataType x){//创建二叉树
	dataType d;
	scanf("%c",&d);
	if(d == x){
		t == NULL;

	}else {
		t = (TreeNode *)malloc(sizeof(TreeNode));
		t -> data = d;
		CreateTree(t->left = x);
		CreateTree(t->right = x);
		front = (front + 1) % MAXSIZE;
	}
}

void PreOrder(TreeNode *t){	//先序遍历，根，左，右
	if(t){
		printf("%d\n",t->data);	
		PreOrder(t->left);	
		PreOrder(t->right);	
	}
} 

void InOrder(TreeNode *t){	//中序遍历，左，根，右
	if(t){
		InOrder(t->left);
		printf("%d\n",t->data);
		InOrder(t->right);
	}
} 

void PostOrder(TreeNode *t){	//后序遍历，左，右，根
	if(t){	
		PostOrder(t->left);
		PostOrder(t->right);
		printf("%d\n",t->data);
	}
}

void LevelOrder(TreeNode *t){//层序遍历
	TreeNode *q[MAXSIZE];
	int front = 0,rear = 0;
	TreeNode *p;
	
	if(t==NULL)		return ;
		q[rear] = t;
		rear= (rear+1) % MAXSIZE;
	while(front != rear){
		p = q[front];
		front = (front+1) % MAXSIZE;
	printf("%c",p->data);
	if(p->left){
		q[rear] = p->left;
		rear = (rear+1) % MAXSIZE;
	}
	if(p->right){
		q[rear] = p->right;
		rear = (rear+1) % MAXSIZE;
		}
	}
}
 

