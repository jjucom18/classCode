/**********************************************
 * Author:tmw
 * date:2018-2-13
 * **********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define MAXSIZE 100
 
/**二叉树数据结构定义**/
typedef struct BiTreeNode
{
	    char data;
	        struct BiTreeNode *left;
		    struct BiTreeNode *right;
}BiTreeNode,*BiTree;
 
/**二叉树的建立--按照先序方式建立--插入**/
void CreateBiTree(BiTree *T)
{
	    char val;
	        scanf("%c",&val);
		 
		    if(val == '#')
			            *T = NULL;  //null表示为空枝
		     
		        else
				    {
					            *T = (BiTree)malloc(sizeof(BiTreeNode));
						            (*T)->data = val;
							            CreateBiTree(&(*T)->left);
								            CreateBiTree(&(*T)->right);
									        }
}
 
 
/**先序遍历  根左右**/
void PreOrderTravel(BiTree T)
{
	    if(T==NULL)
		            return;
	        printf("%c ",T->data);
		    PreOrderTravel(T->left);
		        PreOrderTravel(T->right);
}
 
/**中序遍历 左根右**/
void InOrderTravel(BiTree T)
{
	    if(T==NULL)
		            return;
	        InOrderTravel(T->left);
		    printf("%c ",T->data);
		        InOrderTravel(T->right);
}
 
/**后序遍历 左右根**/
void TailOrderTravel(BiTree T)
{
	    if(T==NULL)
		            return;
	        TailOrderTravel(T->left);
		    TailOrderTravel(T->right);
		        printf("%c ",T->data);
}
int main()
{
	 
	    printf("测试代码\n");
	        BiTree T;
		    T = (BiTree)malloc(sizeof(BiTreeNode));
		     
		        printf("请给二叉树按照先序方式依次输入结点的值(空结点为#):\n");
			    CreateBiTree(&T);
			     
			     
			        printf("先序方式遍历结果：\n");
				    PreOrderTravel(T);
				        printf("\n");
					 
					    printf("中序方式遍历结果：\n");
					        InOrderTravel(T);
						    printf("\n");
						     
						        printf("后序方式遍历结果：\n");
							    TailOrderTravel(T);
							        printf("\n");
								    return 0;
}


