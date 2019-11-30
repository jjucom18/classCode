#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 5
#define m 2*n-1
typedef struct
{
	int weight;
	int lchild,rchild,parent;
}HTNode;
typedef HTNode HuffmanTree[m];

typedef struct
{
	char ch;
	char bits[n+1];
}CodeNode;
typedef CodeNode HuffmanCode[n];

void InitHuffmanTree(HuffmanTree t)
{
	int i;
	for (i=0;i<m;i++)
	{
		t[i].weight=0;
		t[i].lchild=t[i].rchild=t[i].parent=0;
	}
}

void InputWeight(HuffmanTree t)
{
	int i;
	char noslip;
	for (i=0;i<n;i++)
	{
		printf("请输入第%d个权值:",i+1);
		scanf("%d",&t[i].weight);
	}
	noslip=getchar();
	printf("%c",noslip);
}

void SelectMin(HuffmanTree t,int i,int *p1,int *p2)
{
	int j,min1,min2;
	min1=min2=-1;
	for(j=0;j<=i;j++)
		if(t[j].parent==0)
		{
			if(t[j].weight<min1||min1==-1)
			{
				if(min1!=-1)
				{
					min2=min1;
					*p2=*p1;
				}
				min1=t[j].weight;
				*p1=j;
			}
			else
				if(t[j].weight<min2||min2==-1)
				{
					min2=t[j].weight;
					*p2=j;
				}
		}
}

void CreateHuffmanTree(HuffmanTree t)
{
	int i,p1,p2;
	InitHuffmanTree(t);
	InputWeight(t);
	for(i=n;i<m;i++)
	{
		SelectMin(t,i-1,&p1,&p2);
		t[p1].parent=t[p2].parent=i;
		t[i].lchild=p1;
		t[i].rchild=p2;
		t[i].weight=t[p1].weight+t[p2].weight;
	}
}

void Huffmancode(HuffmanTree t,HuffmanCode h)
{
	int c,p,i;
	char cd[n+1];
	int start;
	cd[n]='\0';
	printf("请输入字符");
	for(i=0;i<n;i++)
	{
		//printf("%d",i);
		h[i].ch=getchar();
		start=n;
		c=i;
		while((p=t[c].parent) !='\0')
		{
			cd[--start]=(t[p].lchild==c)?'0':'1';
			c=p;
		}
		strcpy(h[i].bits,&cd[start]);
	}
	printf("\n");
	for(i=0;i<n;i++)
		printf("第%d个字符%c的编码为%s\n",i+1,h[i].ch,h[i].bits);
}

void main()
{
	HuffmanTree t;
	HuffmanCode h;
	printf("\n请输入5个权值\n");
	CreateHuffmanTree(t);
	Huffmancode(t,h);
}
