#include<stdio.h>
#include<stdlib.h>   
#include<string.h>   
#define INFINITY      32767         
#define MAX_VERTEX_NUM      30   
#define MAX 30   
#define TRUE 1   
#define FALSE 0   
typedef struct  
{  
    int adj;		//路径长度   
}ArCell,ArcNode[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  
typedef struct		//图中顶点表示主要景点，存放景点的编号、名称、简介等信息，   
{  
    char name[30];  
    int num;  
    char info[100];	//简介   
}VexNode;  
typedef struct  
{  
    VexNode vertex[MAX_VERTEX_NUM];  
    ArcNode arcs;  
    int vexnum,arcnum;  
}AdjMatrix;  

int LocateVex(AdjMatrix G,char* v)  
{        
    int m=-1,i;  
    for(i=0;i<G.vexnum;i++)  
    if(strcmp(v,G.vertex[i].name)==0)  
    {  
        m=i;  
        break;  
    }  
    return m;  
}  


AdjMatrix CreateDN()  
{  
    AdjMatrix G;  
    int i,j;  
    G.vexnum=25;  
    G.arcnum=31;  
    for(i=0;i<G.vexnum;i++)  
        G.vertex[i].num=i;  
    for(i=0;i<G.vexnum;i++)  
        for(j=0;j<G.vexnum;j++)  
           G.arcs[i][j].adj=INFINITY;  
        //所有带权边   
    G.arcs[0][3].adj=400;  
    G.arcs[0][4].adj=150;  
    G.arcs[1][2].adj=150;  
    G.arcs[1][6].adj=500;  
    G.arcs[2][3].adj=50;  
    G.arcs[3][5].adj=100;  
    G.arcs[4][5].adj=200;  
    G.arcs[4][6].adj=100;  
    G.arcs[6][7].adj=50;  
    G.arcs[6][11].adj=80;  
    G.arcs[7][8].adj=5;  
    G.arcs[7][15].adj=5;  
    G.arcs[8][9].adj=5;  
    G.arcs[9][10].adj=35;  
    G.arcs[9][14].adj=20;  
    G.arcs[10][11].adj=20;  
    G.arcs[10][12].adj=5;  
    G.arcs[10][14].adj=30;  
    G.arcs[11][12].adj=5;  
    G.arcs[12][13].adj=10;  
    G.arcs[15][16].adj=20;  
    G.arcs[15][17].adj=10;  
    G.arcs[16][19].adj=100;  
    G.arcs[16][18].adj=250;  
    G.arcs[18][20].adj=20;  
    G.arcs[19][21].adj=50;  
    G.arcs[20][22].adj=30;  
    G.arcs[22][23].adj=100;  
    G.arcs[19][24].adj=400;  
    G.arcs[21][24].adj=400;  
    G.arcs[22][24].adj=450;  
          //所有景点信息   
    strcpy(G.vertex[0].name,"西门");  
    strcpy(G.vertex[0].info,"大门之一，主要进出通道");  
    strcpy(G.vertex[1].name,"教工食堂");  
    strcpy(G.vertex[1].info,"教职、教工食堂，学生也可就餐");  
    strcpy(G.vertex[2].name,"主图书馆");  
    strcpy(G.vertex[2].info,"馆藏丰富");  
    strcpy(G.vertex[3].name,"校医院");  
    strcpy(G.vertex[3].info,"校医院有着比较先进的设备，并且学生，教职工看病十分便宜");  
    strcpy(G.vertex[4].name,"教务处");  
    strcpy(G.vertex[4].info,"		");  
    strcpy(G.vertex[5].name,"财务中心");  
    strcpy(G.vertex[5].info,"		");  
    strcpy(G.vertex[6].name,"红楼");  
    strcpy(G.vertex[6].info,"		");  
    strcpy(G.vertex[7].name,"游泳池");  
    strcpy(G.vertex[7].info,"		");  
    strcpy(G.vertex[8].name,"竞知楼");  
    strcpy(G.vertex[8].info,"		");  
    strcpy(G.vertex[9].name,"男生宿舍");  
    strcpy(G.vertex[9].info,"		");  
    strcpy(G.vertex[10].name,"女生宿舍");  
    strcpy(G.vertex[10].info,"		");  
    strcpy(G.vertex[11].name,"顺丰快递点");  
    strcpy(G.vertex[11].info,"		");  
    strcpy(G.vertex[12].name,"服务楼");  
    strcpy(G.vertex[12].info,"		");  
    strcpy(G.vertex[13].name,"学生五食堂");  
    strcpy(G.vertex[13].info,"		");  
    strcpy(G.vertex[14].name,"学生三食堂");  
    strcpy(G.vertex[14].info,"		");  
    strcpy(G.vertex[15].name,"公用机房");  
    strcpy(G.vertex[15].info,"		");  
    strcpy(G.vertex[16].name,"文友楼");  
    strcpy(G.vertex[16].info,"		");  
    strcpy(G.vertex[17].name,"厚德楼");  
    strcpy(G.vertex[17].info,"		");  
    strcpy(G.vertex[18].name,"室内田径馆");  
    strcpy(G.vertex[18].info,"室内田径馆美观大方，同时也是新生报到点");  
    strcpy(G.vertex[19].name,"逸夫图书馆");  
    strcpy(G.vertex[19].info,"		");  
    strcpy(G.vertex[20].name,"中通快递点");  
    strcpy(G.vertex[20].info,"		");  
    strcpy(G.vertex[21].name,"学生一食堂");  
    strcpy(G.vertex[21].info,"		");  
    strcpy(G.vertex[22].name,"操场");  
    strcpy(G.vertex[22].info,"		");  
    strcpy(G.vertex[23].name,"南门");  
    strcpy(G.vertex[23].info,"		");  
    strcpy(G.vertex[24].name,"北门");  
    strcpy(G.vertex[24].info,"		");  
    for(i=0;i<G.vexnum;i++)  
        for(j=0;j<G.vexnum;j++)  
            G.arcs[j][i].adj=G.arcs[i][j].adj;  
     return G;  
}  
  
// 计算出起点到各个顶点之间的最短路径,v0为起点   
void ShortestPath_DIJ(AdjMatrix G)  
{  
    int v,w,i,min,c=0,x,ex=1,v0 ;  
    int last[MAX], D[MAX], p[MAX][MAX];  
    while(ex)  
    {  
        printf("请输入一个起始景点编号:");  
        scanf("%d",&v0);  
        if(v0<0||v0>G.vexnum)  
        {  
             printf("景点编号不存在!请重新输入景点编号:");  
             scanf("%d",&v0);  
        }  
    if(v0>=0&&v0<G.vexnum)  
    ex=0;  
    }  
    for(v=0;v<G.vexnum;v++)  
    {  
        last[v]=FALSE;  
        D[v]=G.arcs[v0][v].adj;  
        for(w=0;w<G.vexnum;w++)  
           p[v][w]=FALSE;  
        if(D[v]<INFINITY)  
        {  
            p[v][v0]=TRUE;  
            p[v][v]=TRUE;  
        }  
    }  
    D[v0]=FALSE;  
    last[v0]=TRUE;  
    for(i=1;i<G.vexnum;i++)  
    {  
        min=INFINITY;  
        for(w=0;w<G.vexnum;w++)  
           if(!last[w])  
              if(D[w]<min)  
              {  
                  v=w;  
                  min=D[w];  
              }  
        last[v]=1;  
        for(w=0;w<G.vexnum;w++)  
            if(!last[w]&&(min+G.arcs[v][w].adj<D[w]))  
            {  
               D[w]=min+G.arcs[v][w].adj;  
               for(x=0;x<G.vexnum;x++)   
                    p[w][x]=p[v][x];  
               p[w][w]=TRUE;  
            }  
  
       
    }  
    for(v=0;v<G.vexnum;v++)  
    {  
        if(v0!=v)printf("%s",G.vertex[v0].name);  
        for(w=0;w<G.vexnum;w++)  
        {  
            if(p[v][w]&&w!=v0)printf("-->%s",G.vertex[w].name);  
            c++;  
        }  
        if(c>G.vexnum-1&&v0!=v)  
              printf("       最短总路线长%dm\n\n",D[v]);  
    }  
}  
typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];  
typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  
void ShortestPath_Floyd(AdjMatrix G,PathMatrix *P,DistancMatrix *D)  
{ /* 求有向网G中各对顶点v和w之间的最短路径P[v][w]及其 */  
  /* 带权长度D[v][w]。若P[v][w][u]为TRUE,则u是从v到w当前求得最短 */  
  /* 路径上的顶点。算法7.16 */  
  int u,v,w,i,k,j,ex=1;  
  for(v=0;v<G.vexnum;v++) /* 各对结点之间初始已知路径及距离 */  
    for(w=0;w<G.vexnum;w++)  
    {  
      (*D)[v][w]=G.arcs[v][w].adj;  
      for(u=0;u<G.vexnum;u++)  
        (*P)[v][w][u]=FALSE;  
      if((*D)[v][w]<INFINITY) /* 从v到w有直接路径 */  
      {  
        (*P)[v][w][v]=TRUE;  
        (*P)[v][w][w]=TRUE;  
      }  
    }  
  for(u=0;u<G.vexnum;u++)  
    for(v=0;v<G.vexnum;v++)  
      for(w=0;w<G.vexnum;w++)  
        if((*D)[v][u]+(*D)[u][w]<(*D)[v][w]) /* 从v经u到w的一条路径更短 */  
        {  
          (*D)[v][w]=(*D)[v][u]+(*D)[u][w];  
          for(i=0;i<G.vexnum;i++)  
            (*P)[v][w][i]=(*P)[v][u][i]||(*P)[u][w][i];  
        }  
    while(ex)  
    {  
        printf("请输入出发点和目的地的编号(以空格分开):\n\n");  
        scanf("%d%d",&k,&j);  
        if(k<0||k>G.vexnum||j<0||j>G.vexnum)  
        {  
            printf("景点编号不存在!请重新输入出发点和目的地的编号:\n\n");  
            scanf("%d%d",&k,&j);  
        }  
        if(k>=0&&k<G.vexnum&&j>=0&&j<G.vexnum)  
        ex=0;  
    }  
    printf("%s",G.vertex[k].name);  
    for(u=0;u<G.vexnum;u++)  
        if((*P)[k][j][u]&&k!=u&&j!=u)  
           printf("-->%s",G.vertex[u].name);  
    printf("--->%s",G.vertex[j].name);  
    printf("      最短总路线长%dm\n",(*D)[k][j]);  
}  
   
//显示所有的景点信息   
void ShowAll(AdjMatrix  G)  
{  
    int v;  
    printf("       *******************************************************************************************\n\n");  
    printf("       * 编号  	 *景点名称    	 	   * 简介                                            *\n\n");  
    for(v=0;v<G.vexnum;v++)  
    printf("       *%-3d	 *%-15s		    *%-65s*\n",G.vertex[v].num,G.vertex[v].name,G.vertex[v].info);           
    printf("       *******************************************************************************************\n\n");  
}  

//查询景点   
void Find(AdjMatrix G)  
{  
    int k,ex=1;  
    while(ex)  
    {  
       printf("请输入要查询的景点标号:\n\n");  
       scanf("%d",&k);  
       if(k<0||k>G.vexnum)  
       {  
           printf("请重新输入景点标号:\n\n");  
           scanf("%d",&k);  
           
       }  
      if(k>=0&&k<G.vexnum)  
         ex=0;  
    }  
    printf("\n\n景点编号:%d \n",G.vertex[k].num);  
    printf("\n\n景点名称:%s \n",G.vertex[k].name);  
    printf("\n\n景点简介:%s \n\n\n",G.vertex[k].info);  
}  
void Display()  
{   
    printf("\n                                           九江学院校园导游\n\n");  
    printf("                                                      \n");  
    printf("                                ********************************************** \n\n");  
    printf("                                *            1.浏览校园全部地点              *\n\n");  
    printf("                                *            2.查询任意地点信息              *\n\n");  
    printf("                                *            3.查看全部游览最短路线          *\n\n");  
    printf("                                *            4.查询任意两点的最短路线        *\n\n");  
    printf("                                *            5.退出系统                      *\n\n");  
    printf("                                **********************************************\n\n\n\n");  
    printf("选择功能如下:\n\n");  
}  
void main()  
{  
    system("color D");    //设置淡紫色   
    system("mode con: cols=128 lines=60"); //设置显示宽、高   
    AdjMatrix g;  
    int i;  
    PathMatrix a;  
    DistancMatrix b;  
    g=CreateDN();     
    Display();  
    while(1)  
    {  
        scanf("%d",&i);  
        if(i==1)  
        {  
            system("cls"); //清屏   
            Display();  
            ShowAll(g);   //显示全景   
            printf("\n\n您可以继续使用本系统的其他服务，输入5退出系统!\n\n");  
            continue ;  
        }  
        if(i==2)  
        {  
            system("cls");  
            Display();  
            Find(g);  
            printf("\n\n您可以继续使用本系统的其他服务，输入5退出系统!\n\n");  
            continue;  
        }  
        if(i==3)  
        {  
            system("cls");  
            Display();  
            ShortestPath_DIJ(g);    
            printf("\n\n您可以继续使用本系统的其他服务，输入5退出系统!\n\n");  
            continue;  
        }  
        if(i==4)  
        {  
            system("cls");  
            Display();  
            ShortestPath_Floyd(g,&a,&b);  
            printf("\n\n您可以继续使用本系统的其他服务，输入5退出系统!\n\n");  
            continue;  
        }  
        if(i==5)  
        {  
             exit(0);  
        }  
    }  
} 
