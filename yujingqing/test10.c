#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 
#include <string.h>
#define INFINITY  10000
#define M 20 
typedef struct{  
  char V[M][10];  //顶点数组，用来存储辖区的值即辖区的名称，二维数组，此时代表两随意区域。
  int R[M][M]; //图的邻接矩阵，邻接矩阵的元素值为辖区之间的距离（对称）
  int vexnum; //辖区的个数
 }Graph;// 
int locatevex(Graph *g,char a[10]) //查找顶点u在辖区图中的位置
{
	int i;
	   for(i=0;i<g->vexnum;i++)//循环执行条件是当u=V[i]时停止，求i值
		  {
	             if(strcmp(a,g->V[i])==0)//比较字符串的大小，若a=V[i],说明二者差值为0。.
                     return i; //说明此时找到了符合要求的i使u=V[i]
	                        }
	   if(i==g->vexnum)
		 return -1; //
}
int creatgraph(Graph *g) //创建辖区无向图，图中含有n个结点，创建辖区邻接矩阵
{
   int i=0,j,m,k,p;
   char a[10],b[10];
   printf("*****欢迎使用本程序解决地铁建设问题*****\n");
   printf("*******请按照提示依次输入相关信息*******\n");
   printf("***请输入所有的辖区，以0作为结束标志****\n");
   scanf("%s",g->V[i]);//输入结点值,也就是第1个定义的辖区名。
   while(strcmp("0",g->V[i])!=0)//当输入的第1个结点值不为0时，说明此时还要继续输入下一个结点，如果出现0，则要跳出这个循环。
  {
     i++;//开始第二个结点
     scanf("%s",g->V[i]);//输入V[1],由于1时下标，故此时表示第2个结点的输入
					     }
     g->vexnum=i;//把i此时的值赋给V,代表此时所输入的结点数，也就是所有的辖区。
 for(i=0;i<g->vexnum;i++)
 for(j=0;j<g->vexnum;j++)
 g->R[i][j]=INFINITY;//初始化//好像时定义了邻接图的初始矩阵，出来了一个初步的框架，也代表权值不大于10000（此时的10000代表无穷大）
 printf("*请输入辖区之间的路程，格式为 辖区辖区路程 以0 0 0为结束标志*\n")；
 scanf("%s%s%d",a,b,&m); //输入辖区结点及辖区之间的距离
 while(strcmp("0",a)!=0 || strcmp("0",b)!=0 || m!=0)//只有当输入的a,b,m都为0时，才能跳出while循环
{
  k=locatevex(g,a);  p=locatevex(g,b);//查找a,b在图中的位置
  if(k==-1)//代表返回值时-1，，则说明没有找到z输入的辖区
{
	printf("*****对不起，输入错误，没有%s这个辖区*****\n",a);
        return 0;
											   	 }
	if(p==-1)//同上
{
       printf("*****对不起，输入错误，没有%s这个辖区*****\n",b);
       return 0;
									 }
       g->R[k][p]=g->R[p][k]=m;//k到p和p到k之间的距离相同（无向图）
       scanf("%s%s%d",a,b,&m); //输入辖区结点及辖区之间的距离
					  }
       return 1;
}
struct tree{
	    int weizhi;
	    int lowcost;
};//此时应该是准备构造一个辅组数组
int minimun(struct tree *a,Graph g){ //求出第k辖区，此时i辖区与k辖区之间的距离最短
	int i,k,m=0;
	for(i=0;i<g.vexnum;i++)
          {  
	     if(m==0 && a[i].lowcost!=0)
		   {    m=1;
			k=i   ;
		             } 
	 if(m==1 && a[i].lowcost!=0)
             {
	        if(a[i].lowcost<a[k].lowcost)
	        k=i;
		        }
            }
	 return k;
}
void MiniSpanTree_PRIM(Graph g,char a[10])
{
	struct tree closedge[M];
	 int i,j,k,money=0;
	 k=locatevex(&g,a);
	 for(i=0;i<g.vexnum;i++)
{
         if(i!=k)
{
	closedge[i].lowcost=g.R[k][i]; //两辖区k，i之间的距离
	closedge[i].weizhi=k; //与辖区i相邻的最近的辖区设为辖区k
					 }
		      }
	closedge[k].lowcost=0;//初始化，U={u}
printf("********根据您的输入建立邻接表为:********\n"); 
  for(i=0;i<g.vexnum;i++)//这一块有两个循环，首先i=0,然后进入j的循环，当j=输入的顶点数，跳出j循环，输出的一系列为R[0]{[0][1][2]......[vexnum]}
                         //然后第二次循环，i自增为1，j循环再次开始，结束后跳出j循环，最终输出为R[1]{[0][1][2].......[vexnum]}
  {                      //以此类推，直到i=vexnun，跳出所有循环，输出了整个邻接矩阵 
        for(j=0;j<g.vexnum;j++)   
            {  
               printf("|%d| ",g.R[i][j]); //j循环
	       }	         
	     printf("\n\n"); 
	        } //邻接矩阵输出完毕
    printf("****得到应建设地铁的辖区及之间权值为:****\n");
      for(i=1;i<g.vexnum;i++)
	 {
            k=minimun(closedge,g); //求出最小生成树T的下一个结点，第k结点
            money+=closedge[k].lowcost;
            printf("%d:%s  %s %d\n",i,g.V[closedge[k].weizhi],g.V[k],closedge[k].lowcost); //输出生成树的边
            closedge[k].lowcost=0;  //第k顶点并入U集
            for(j=0;j<g.vexnum;j++)
             { 
                   if(g.R[k][j]<closedge[j].lowcost) //新顶点并入集后，选择新的边，将小的边放到辅助数组
                      { 
                          closedge[j].weizhi=k;
                          closedge[j].lowcost=g.R[k][j];
		                                        }       
		              } 
		} 
      printf("******据统计地铁的总建设路程为：%d *******\n",money);
}
void main()
{
	int i;
	Graph g;
	char a[10];
	i=creatgraph(&g);
        if(i){
	printf("***********请输入起始地点为：************\n");
	scanf("%s",a);
	MiniSpanTree_PRIM(g,a);}//最小生成树出来
	printf("**********感谢使用本程序，谢谢！*********\n\n ");
}
