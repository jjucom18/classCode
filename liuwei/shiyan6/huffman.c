#include"huffman.h"

void HuffmanTree(HNodeType HuffNode[MAXNODE],int n){
	int i,j,m1,m2,x1,x2;
	for(i=0;i<2*n-1;i++)
	{
		HuffNode[i].weight=0;
		HuffNode[i].parent=-1;
		HuffNode[i].lchild=-1;
		HuffNode[i].rchild=-1;
		HuffNode[i].value=i;
	}

	for(i=0;i<n;i++){
		printf("please input weight of leaf node %d :\n,i");
		scanf("%d",&HuffNode[i].weight);
	}

	for(i=0;i<n-1;i++){
		m1=m2=MAXVALUE;
		x1=x2=0;
		for(j=0;j<n+i;j++)
		{
			if(HuffNode[j].weight<m1 && HuffNode[j].parent==-1)
			{
				m2=m1;
				x2=x1;
				m1=HuffNode[j].weight;
				x1=j;
			}
			else if(HuffNode[j].weight<m2&&HuffNode[j].parent==-1)
			{
				m2=HuffNode[j].weight;
				x2=j;
			}
		}

		HuffNode[x1].parent=n+i;
		HuffNode[x2].parent=n+i;
		HuffNode[n+i].weight=HuffNode[x1].weight+HuffNode[x2].weight;
		HuffNode[n+i].lchild=x1;
		HuffNode[n+i].rchild=x2;
		printf("x1.weight and x2.weight in round %d: %d,%d\n",i+1,HuffNode[x1].weight,HuffNode[x2].weight);
		printf("\n");
	}
	void decodeing(char string[],int* buf[],int Num)
	{
		int i,tmp=0,code[1024];
		int m=2*Num-1;
		char *nump;
		char num[1024];
		for(i=0;i<strlen(string);i++)
		{
			if(string[i]=='0')
				num[i]=0;
			else
				num[i]=1;
		}
		i=0;
		nump=&num[0];
		while(nump<(&num[strlen(string)]))
		{tmp=m-1;
			while(buf[tmp].lchild!=-1&&(buf[tmp].rchild!=-1))
			{
				if(*nump==0)
				{
					tmp=buf[tmp].lchild;
				}
				else tmp=buf[tmp].rchild;
				nump++;
			}
			printf("%d",buf[tmp].value);
		}
	}
}
