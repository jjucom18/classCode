#include<stdio.h>

#include<stdlib.h>

#include<malloc.h>

#include<string.h>

#define NAME_MAX 30//姓名的最大长度

#define WEIGHT_MAX 30000//最大权值

typedef struct AA

{
	
	int number;
	
	int weight;
	
	struct AA *next;
	
}Node;//邻接表的结点

typedef struct

{
	
	char name[30];
	
	Node *next;
	
}Graph;//邻接表的表头结点

typedef struct

{
	
	int begin;
	
	int end;
	
	int weight;
	
}min_tree;//存储树的三元组，

int seek_i(Graph metro[],int length,char str[])
	
{
	
	/*前提条件：metro为一图的邻接表，length为表的长度，str为一不为空的字符串
	 *
	 * 后置条件：若metro中的name域存在与str相同的字符串则返回第几个，不存在返回0*/
	
	int i;
	
	for(i=1;i<=length;i++)
		
		if(strcmp(str,metro[i].name)==0)
			
			break;
	
	if(i>length)
		
		return 0;
	
else
	
	return i;

}

void append_(Graph G,int w,int weight)
	
{
	
	/*前置条件：G为邻接表的一个结点，w与weight为要插入的结点的数据域
	 *
	 * 后置条件：把w与weight组成一个结点并插入表头结点G中*/
	
	Node *s=(Node *)malloc(sizeof(Node));
	
	s->number=w;
	
	s->weight=weight;//s为w和weight所组成的一个结点。
	
	s->next=G.next;
	
	G.next=s;
	
}

void plim(Graph metro[],int length,int ver,min_tree min_t[])//普利姆算法
	
{
	
	/*前置条件：metro为图的邻接表，length为其长度，ver为要开始的序号，min_t为三元组的空表。
	 *
	 * 后置条件：min_t储存最小生成树的三元组。*/
	
	struct BB
		
	{
		
		int vertex;//结点的序号
		
		int short_distance;//从short_distance为0的顶点到不为0的顶点的最短距离
		
	}*assist=(struct BB *)malloc((length+1)*sizeof(struct BB));//辅助数组
	
	/*---------初始化辅助数组----------*/
	
	int i;
	
	for(i=0;i<=length;i++)
		
	{
		
		assist[i].short_distance=WEIGHT_MAX;
		
		assist[i].vertex=0;
		
	}
	
	/*----------加入ver的结点------------*/
	
	assist[ver].short_distance=0;
	
	Node *p;
	
	p=metro[ver].next;
	
	while(p)
		
	{
		
		assist[p->number].short_distance=p->weight;
		
		assist[p->number].vertex=ver;
		
		p=p->next;
		
	}
	
	int min_t_length=0;//assist中short_distance域为0的个数
	
	for(i=1;i<length;i++)
		
	{
		
		int min=0,j;
		
		for(j=1;j<=length;j++)
			
		{
			
			if(assist[j].short_distance!=0&&assist[j].short_distance<assist[min].short_distance)
				
				min=j;
			
		}//找出assist中short_distance域除0外最小值的序号
		
		/*----------把序号为min的信息存入三元组中------------*/
		
		min_t_length++;
		
		min_t[min_t_length].begin=min;
		
		min_t[min_t_length].end=assist[min].vertex;
		
		min_t[min_t_length].weight=assist[min].short_distance;
		
		/*---------------修改assist数组----------*/
		
		assist[min].short_distance=0;
		
		p=metro[min].next;
		
		while(p)
			
		{
			
			if(assist[p->number].short_distance!=0&&p->weight<assist[p->number].short_distance)
				
			{
				
				assist[p->number].vertex=min;
				
				assist[p->number].short_distance=p->weight;
				
			}
			
			p=p->next;
			
		}
		
	}
	
}

int main()
	
{
	
	int n;
	char name[10];
	/*---------输入地点的信息---------*/
	
	printf("请输入辖区的个数:");
	
	scanf("%d",&n);
	
	getchar();
	
	Graph *metro=(Graph *)malloc((n+1)*sizeof(Graph));
	
	int i;
	
	for(i=1;i<n+1;i++)
		
	{
		
		printf("请输入第%d个辖区的名称:",i);
		
		scanf("%s",name);
		strcpy(metro[i].name,name);
		
		metro[i].next=NULL;
		
	}
	
	/*------输入边的信息-------*/
	
	printf("请输入边的条数:");
	
	int edge;
	
	scanf("%d",&edge);
	
	getchar();
	
	printf("请输入各条边的信息（格式：辖区名称辖区名称直接距离）\n");
	
	for(i=1;i<=edge;i++)
		
	{
		
		printf("请输入第%d条边:",i);
		
		char str1[NAME_MAX],str2[NAME_MAX];
		
		int weight;
		
		scanf("%s%s%d",str1,str2,&weight);
		
		getchar();
		
		int w1,w2;
		
		w1=seek_i(metro,n,str1);
		
		w2=seek_i(metro,n,str2);
		
		if(w1==0||w2==0||weight<=0)
			
		{
			
			printf("输入错误！请重新输入！\n");
			
			i--;
			
			continue;
			
		}
		
		append_(metro[w1],w2,weight);
		
		append_(metro[w2],w1,weight);
		
	}
	
	/*------输出邻接表---------*/
	
	printf("\n邻接表如下\n");
	
	int a;
	
	for(a=1;a<=n;a++)
		
	{
		
		printf("%d %s-->",a,metro[a].name);
		
		Node *q;
		
		q=metro[a].next;
		
		while(q)
			
		{
			
			printf("%d_%d  ",q->number,q->weight);
			
			q=q->next;
			
		}
		
		putchar(10);
		
	}
	
	min_tree *min_t=(min_tree *)malloc(n*sizeof(min_tree));
	
	plim(metro,n,1,min_t);
	
	/*---------输出生成树---------*/
	
	printf("\n方案如下(辖区名称辖区名称直接距离):\n");
	
	int sum=0;
	
	for(i=1;i<n;i++)
		
	{
		
		printf("%s\t\t%s\t\t%d\n",metro[min_t[i].begin].name,metro[min_t[i].end].name,min_t[i].weight);
		
		sum+=min_t[i].weight;
		
	}
	
	printf("总的距离为%d\n",sum);
	
	return 0;
	
}

