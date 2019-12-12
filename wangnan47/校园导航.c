#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#define MaxInt 30000
#define Max 200
typedef struct
{
	int adj;
}ArcCell; //边的函数
typedef struct
{
	char name[20];
	char name[MAx];
}VexType; //顶点的数组
typedef struct
{
	ArcCell arcs[Max][Max];
	VexType vexs[Max];
	int vexnum,arcnum; //顶点数 边数
}MGragh//图的数组
void main()
{
	int P[Max][Max],D[Max];
	MGraph G;
	CreateGraph(G);
	while(1)
	{
		printf("\n\t\t*****江西省九江学院校园导航******\n");
		printf("\t\t\t 输入1 ：浏览校园景点\n");
		printf("\t\t\t 输入2 ：显示指定景点信息");
		printf("\t\t\t 输入3 ：搜索景点路径\n");
		printf("\t\t\t 输入4 ：展示学校地图\n");
		printf("\t\t\t*请您按序号输入，谢谢*");
		int i;
		scanf("%D",&i);
		switch(i)
		{
			case 1:
			{
				clrscr();
				ShowAllPlace(G);
				break;
			}
			case 2:
			{
				clrscr();
				ShowAllPlace(G);
				information(G);
				break;
			}
			case 3:
			{
				clrscr();
				int i,n;
				ShowAllPlace(G);
				printf("输入你所在位置序号");
				scanf("%d",&i);
				printf("输入你目标位置序号");
				scanf("%d",&n);
				ShortestPath_DIJ(G,i,P,D);
				PrintShortest(G,i,n,P,D);
				break;
			}
			case 4:
			{
				clrscr();


				printf("1.南门\n");
				printf("  |\n");
				printf("  |\n");
				printf("2.教工食堂____3.图书主馆\n");
				printf("  |\n");
				printf("  |\n");
				printf("4.电子竞知楼____5.一食堂");
				printf("  |\n");
				printf("  |\n");
				printf("6.女生宿舍区____7.男生宿舍区");
				printf("  |\n");
				printf("  |\n");
				printf("8.三食堂__四服楼__文友楼__厚德楼__公共机房\n");
				printf("  |\n");


				break;
			}
			default:
			{
				clscr();
				printf("输入错误");
				break;
			}
	}




    
	} 

} 
void ShowAllPlace(MGraph G)
{
	int i;
	for(i=0;i<G.vexnum;i++)
	{
		printf("%d,%s\t",i+1,G.vexs[i].name);
	}
	printf("\n");
}
void information(MGraph G)
{
	int i;
	printf("请输入查询点的序号\n");
	scanf("%d",&i);
	printf("%s",G.vexs[i-1].info);
}


void clrscr() //清屏
{
	system("cls");
}
void CreateGraph(MGraph &G) //对该无向网进行初始化  
{
	int i,j;
	FILE *fp;
	if((fp = fopen("江西省九江学院.txt","t"))==NULL) //打开文件
	{
		printf("文件格式错误 ！\n");
		exit(0);
	}
	fscanf(fp,"%d%d",&G.vexsnum,&G.arcnum); //读入景点个数和边数
	for(i = 0;i<G.vexnum;++i) //读入景点名称和详细介绍信息
		fscanf(fp,"%s%s\n",&G.vexs[i].name,&G.vexs[i].info);

	for(i = 0;j<G.vexnum;++i)
		for(j=0;j<G.vexnum;++j)
			fscanf(fp,"%d",&G.arcs[i][j].adj);

	fclose(fp);
}


void ShortestPath_DIJ(MGraph G,int q,intP[][Max],int *D) //查询景点v0到任意景点的最短路径
{
	int v,w,i,t,min,*final;
	int v0=q-1;
	final=(int*)malloc((G.vexnum+1)*sizeof(int))) ;
	if(final==NULL)
	{
		printf("\t*****内存分配失败 ！**************\n");
		exit(0);
	}
	for(v=0;v<g.vexnum;v++)
	{
		final[v]=0;
		D[v]=G.arcs[v0][v].adj; //将v0到各个终点的最短路径长度初始化为弧上的权值
		for(w=0;w<G.vexnum;w++)
			P[v][w]=0; //v点到各点初始化
		if(D[v]<MaxInt) //如果v0点到v点有弧 将v的前驱置为1
		{
			P[v][v0]=1;
			P[v][v]=1;
		}
		
	}
	D[v0]=0;
	final[v0]=1;
	/*初始化结束，开始主循环，每次求得v0到某个顶点v得最短路径，将v加到S集__*/
	for(i=0;i,G.vexnum;++i)
	{
		min=MaxInt;
		for(w=0;w<G.vexnum;++w)
			if(!final[w])
				if(D[w]<min) //如果v0到v点有路
				{
					v=w;
					min=D[w];//存储路径最短
				}
		final[v]=1; //标记有路
		for(w=0;w<G.vexnum;++w)
			if(!final[w]&&((min+G.arcs[v][w].adj)<D[w])//如果v0点到v点有路且最短路径加上
{
 D[w] = min+G.arcs[v][w].adj;
 for(t=0;t<G.vexnum;t++)
 P[w][t]=P[v][t];
 P[w][w]=1;
}
			

			
	}


}
void PrintShortest(MGraph,int t1,int t2,intP[][Max] ,int *D )//输入最短路径
{
int v1=t1-1,v2=t2-1;
if(vv1==v2)
{
printf("起点和终点不能相同！\n");
return;
}
int i,j,k;
printf("\n\t从%s到%s的最短距离为：%d\n\n",G.vexs[v1].name,G.vexs[v2].name,D[v2]) ;
printf("\t最短路径是：%s",G.vexs[v1].name);
k=j=0;
for(i=0;i<G.vexnum;++i)
{
	P[v2][v1]=0;
	while(j<G.vexnum&&(G.arcs[v1][j].adj>=MaxInt||P[v2][j]==0))
		j++;
	if(G.arcs[v1][j].adj<MaxInt&&P[v2][j]==1)
	{
		printf("%s",G.vexs[j].name);
		k++;
		P[v2][j]=0;
		v1=j;
		if(k%6==0)
			printf("\n");
	}
}
} 

