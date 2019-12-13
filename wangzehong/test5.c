#include <stdio.h>

#include <stdlib.h>

#define MAXSIZE 30



typedef char ElemType;

typedef struct TNode *BiTree;



struct TNode {

	char data;

	BiTree lchild; 

	BiTree rchild;

};



int IsEmpty_BiTree(BiTree *T) {

	if(*T == NULL)

	return 1;

	else

	return 0;

}



void Create_BiTree(BiTree *T){

    char ch;

    ch = getchar();

    //当输入的是"#"时，认为该子树为空

    if(ch == '#')

        *T = NULL;

    //创建树结点

    else{        

	*T = (BiTree)malloc(sizeof(struct TNode));

	(*T)->data = ch;//生成树结点

	//生成左子树

	Create_BiTree(&(*T)->lchild);

	//生成右子树

	Create_BiTree(&(*T)->rchild);

	}

}



void TraverseBiTree(BiTree T) {	//先序遍历

 	if(T == NULL)

		return;

 	else {

		printf("%c ",T->data);

		TraverseBiTree(T->lchild);

		TraverseBiTree(T->rchild);

		}

}



void InOrderBiTree(BiTree T) {		//中序遍历 

	if(NULL == T)

	return;

else {

		InOrderBiTree(T->lchild);

		printf("%c ",T->data);

		InOrderBiTree(T->rchild);	

	}

}

void PostOrderBiTree(BiTree T) {

	if(NULL == T)

	return;

else {

		InOrderBiTree(T->lchild);

		InOrderBiTree(T->rchild);

		printf("%c ",T->data);

	}

} 



int TreeDeep(BiTree T) {

	int deep = 0;

	if(T)

	{int leftdeep = TreeDeep(T->lchild);

		int rightdeep = TreeDeep(T->rchild);

		deep = leftdeep+1 > rightdeep+1 ? leftdeep+1 : rightdeep+1; 

	}

	return deep;

}



int Leafcount(BiTree T, int num) {

	if(T)

	{

		if(T->lchild ==NULL && T->rchild==NULL)	

		{

			num++;

			printf("%c ",T->data);

		}	

	Leafcount(T->lchild,num);

		Leafcount(T->rchild,num);

	}



	return num;



}	





void LevelOrder_BiTree(BiTree T){

    //用一个队列保存结点信息,这里的队列采用的是顺序队列中的数组实现

    int front = 0;

    int rear = 0;

BiTree BiQueue[MAXSIZE];

    BiTree tempNode;

    if(!IsEmpty_BiTree(&T)){

        BiQueue[rear++] = T;

          while(front != rear){

            //取出队头元素，并使队头指针向后移动一位　

            tempNode = BiQueue[front++];

			 if(!IsEmpty_BiTree(&(tempNode->lchild)))

				 BiQueue[rear++] = tempNode->lchild;

			 if(!IsEmpty_BiTree(&(tempNode->rchild)))

				 BiQueue[rear++] = tempNode->rchild; 

			 if(!IsEmpty_BiTree(&(tempNode->rchild)))

				 BiQueue[rear++] = tempNode->rchild; 

			 printf("%c ",tempNode->data);

			 }

			 }

			 }

int main(void)

{

	BiTree T;

	BiTree *p = (BiTree*)malloc(sizeof(BiTree));

	int deepth,num=0 ;

Create_BiTree(&T);

	printf("先序遍历二叉树\n");

	TraverseBiTree(T);

	printf("中序遍历二叉树\n");

	printf("\n");

	InOrderBiTree(T);

	printf("后序遍历二叉树\n");

	printf("\n");

	PostOrderBiTree(T);

	printf("\n层次遍历结果\n");

    LevelOrder_BiTree(T);



	return 0;

}
