
#include<stdio.h>
#include<string.h>
#define N 100
using namespace std;
typedef struct
{char data[5];
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;
typedef struct
{char cd[N];
	int start;
}HCode;
void CreateHF(HFNode ht[],int n)
{int lnode,rnode;
	double min1,min2;
	for(int i=0;i<2*n-1;i++)
		ht[i].parent=ht[i].rchild=-1;
	for(int i=n;i<2*n-1;i++)
	{min1=min2=32767;
		lnode=rnode=-1;
		for(int k=0;k<=i-1;k++)
		{
			if (ht[k].parent==-1)
			{if (ht[k].weight<min1)
				{min2=min1;rnode=lnode;
					min1=ht[k].weight;lnode=k;
				}
				else if(ht[k].weight<min2)
				{min2=ht[k].weight;rnode=k;
				}
			}
		}
		ht[i].weight=ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild=lnode;ht[i].rchild=rnode;
		ht[lnode].parent=i;ht[rnode].parent=i;
	}
}
void CreateHCode(HTNode ht[],HCode hcd[],int n)
{
	int f,c;
	HCode hc;
	for(int i=0;i<n;i++)
	{
		hc.start=n;c=i;
		f=ht[i].parent;
		while(f!=-1)
		{if (ht[f].lchild==c)
			hc.cd[hc.start--]='0';
			else 
				hc.cd[hc.start--]='1';
			c=f;f=ht[f].parent;
		}
		hc.start++;
	}
}
void DispHCode(HTNode ht[],HCode hcd[],int n)
{
	int sum=0,m=0,j;
	for(int i=0;i<n;i++)
	{
		j=0;
		cout<<ht[i].data<<":";
		for(int k=hcd[i].start;k<=n;k++)
		{
			cout<<hcd[i].cd[k];
			j++;
		}
		m+=ht[i].weight;
		sum+=ht[i].weight*j;
		cout<<end1;
	}
	cout<<"平均长度："<<sum/m;
	main()
		int n=15;
	char str[][5]={"T].parent=i;ht[rnode].parent=i;
	}
}
void CreateHCode(HTNode ht[],HCode hcd[],int n)
{
	int f,c;
	HCode hc;
	for(int i=0;i<n;i++)
	{
		hc.start=n;c=i;
		f=ht[i].parent;
		while(f!=-1)
		{if (ht[f].lchild==c)
			hc.cd[hc.start--]='0';
			else 
				hc.cd[hc.start--]='1';
			c=f;f=ht[f].parent;
		}
		hc.start++;
	}
}
void DispHCode(HTNode ht[],HCode hcd[],int n)
{
	int sum=0,m=0,j;
	for(int i=0;i<n;i++)
	{
		strcpy(ht[i].data,str[i]);
		ht[i].weight=fnum[i];
	}
	CreateHT(ht,n);
	CreateHCode(ht,hcd,n);
	DispHCode(ht,hcd,n);
	return 0;
}
