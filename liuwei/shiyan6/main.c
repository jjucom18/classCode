#include"huffman.h"

int main(int argc,char *argv)
{
	HNodeType HuffNode[MAXNODE];
	HCodeType HuffCode[MAXLEAF],cd;
	int i,j,c,p,n;
	char pp[100];
	printf("please input n:\n");
	scanf("%d",&n);
	HuffmanTree(HuffNode,n);
	for(i=0;i<n;i++)
	{
		cd.start=n-1;
		c=i;
		p=HuffNode[c].parent;
		while(p!=-1)
		{
			if(HuffNode[p].lchild==c)
				cd.bit[cd.start]=0;
			else 
				cd.bit[cd.start]=1;
			cd.start--;
			c=p;
			p=HuffNode[c].parent;
		}
		for(j=cd.start+1;j<n;j++)
		{
			HuffCode[i].bit[j]=cd.bit[j];}
		HuffCode[i].start=cd.start;
	}
	for(i=0;i<n;i++)
	{
		printf("%d's Huffman code is:",i);
		for(j=HuffCode[i].start+1;j<n;j++)
		{
			printf("%d",HuffCode[i].bit[j]);
		}
			printf("start:%d",HuffCode[i].start);
			printf("\n");
		}
		printf("decoding?please enter code:\n");
		scanf("%s",&pp);
		decodeing(pp,HuffNode,n);
		getch();
		return 0;
	}
