#ifndef HTree_h
#define HTree_h

#include <stdio.h>
#define MaxValue 10000
#define n 20
typedef struct {
	int weight;
	int parent;
	int lchild;
	int rchild;
}HNodeType;
typedef struct {
	int bit[n];
	int start;
}HCodeType;
HCodeType HCode[n];

HNodeType HTree[2*n - 1];

void Creat_HuffMTree(HNodeType HTree[],int n);   //构造哈夫曼树
void HaffmanCode(HNodeType HTree[],HCodeType HCode[]);   //哈夫曼编码
#endif