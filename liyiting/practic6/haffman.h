#ifndef haffman_h
#define haffman_h

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;  

struct BTreeNode  

{  
	    ElemType data;  
   	    struct BTreeNode* left;  
	    struct BTreeNode* right;  
};

void PrintBTree_int(struct BTreeNode* BT);
struct BTreeNode* CreateHuffman(ElemType a[], int n);
ElemType WeightPathLength(struct BTreeNode* FBT, int len);
void HuffManCoding(struct BTreeNode* FBT, int len);  

#endif
