#ifndef huffman_h
#define huffman_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE  MAXLEAF*2-1


typedef struct{
	int bit[MAXBIT];
	int start;
}HCodeType;
typedef struct{
	int weight;
	int parent;
	int lchild;
	int rchild;
	int value;
}HNodeType;

void HuffmanTree(HNodeType HuffNode[MAXNODE],int n);
void decodeing(char string[],int* Buf[],int Num);


#endif
