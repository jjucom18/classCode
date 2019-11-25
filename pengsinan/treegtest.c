#include<stdio.h>
#include<malloc.h>
#include"treeg.c"
#include"treeg.h"

int main () {
	TreeNode *t ;
	ptintf("Input the char you want in preorder,and if the left or right chlid is null,please intput a #\n");
	printf("such as ABD#G###CE##F##\n");
	CreatTree (t , '#');
	printf("preorder is : ");
	PreOreder (t);
	ptintf("\n");
	ptintf("inorder is : ") ;
	InOrder (t);
	ptintf("\n");
	printf("postorder is : ") ;
	PostOrder (t);
	printf("\n");
	printf("levelorder is : ") ;
	LevelOrder (t) ;
	printf("\n");

}

