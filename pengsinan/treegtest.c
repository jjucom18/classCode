#include<stdio.h>
#include<malloc.h>
#include"treeg.c"
#include"treeg.h"

int main () {
	TreeNode *t ;
	printf("Input the char you want in preorder,and if the left or right chlid is null,please intput a #\n");
	printf("such as ABD#G###CE##F##\n");
	CreateTree (t , '#');
	printf("preorder is : ");
	PreOrder (t);
	printf("\n");
	printf("inorder is : ") ;
	InOrder (t);
	printf("\n");
	printf("postorder is : ") ;
	PostOrder (t);
	printf("\n");
	printf("levelorder is : ") ;
	LevelOrder (t) ;
	printf("\n");

}

