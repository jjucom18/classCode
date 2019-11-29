#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HNodeType;

#define MAXVALUE 10000//为找最小，定义一个较大的数
int main(int argc,char **argv){
void Create_HuffMTree(HNodeType HFMTree[],int n){
	//构造的哈夫曼树存储于HFMTree[],n为叶子节点的个数
    int m1,x1,m2,x2;//x1和x2存储最小和次最小权值，m1和m2存储其位置
	int i,j;
	for(i=0;i<2*n-1;i++){
		HFMTree[i].weight=0;
		HFMTree[i].parent=-1;
		HFMTree[i].lchild=-1;
		HFMTree[i].rchild=-1;
	}
	for(i=0;i<n;i++)
		scanf("%d",&HFMTree[i].weight);
	for(i=0;i<n-1;i++){
		x1=x2=MAXVALUE;
		m1=m2=0;
		for(j=0;j<n;j++){
			if(HFMTree[j].parent==-1&&HFMTree[j].weight<x1){
				//找出根节点具有最小和次最小权值的两棵树
				x2=x1;m2=m1;
				x1=HFMTree[j].weight;m1=j;
			}
			else if(HFMTree[j].parent==-1&&HFMTree[j].weight<x2){
				x2=HFMTree[j].weight;
				m2=j;
            }
		}
		HFMTree[m1].parent=n+i;HFMTree[m2].parent=n+i;
		HFMTree[n+i].weight=HFMTree[m1].weight+HFMTree[m2].weight;
		HFMTree[n+i].lchild=m1;HFMTree[n+i].rchild=m2;
	}
}
} 
