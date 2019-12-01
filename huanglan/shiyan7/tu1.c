#include<stdio.h>//校园导航
#include<string.h>
#include<stdlib.h>
#define INF 999999
#define M 20
int dist[M][M];///距离
int path[M][M];///路径
int Stack[M];///路径栈
int top;///栈顶
int counts;///记录路径数
int visited[M];///标记数组
struct vertex///景点信息结构体
{
    int num;///景点编号
    char name[20];///景点名称
};
struct maps
{
    int n;///点数
    int m;///边数
    vertex v[M];
    int edgs[M][M];///邻接矩阵
} g; ///景点图的结构体
void Creat_vertex()
{
    g.v[0].num=1;
    strcpy(g.v[0].name,"北门");
    g.v[1].num=2;
    strcpy(g.v[1].name,"逸夫图书馆");
    g.v[2].num=3;
    strcpy(g.v[2].name,"厚德楼");
    g.v[3].num=4;
    strcpy(g.v[3].name,"香远楼");
    g.v[4].num=5;
    strcpy(g.v[4].name,"四服楼");
    g.v[5].num=6;
    strcpy(g.v[5].name,"三食堂");
    g.v[6].num=7;
    strcpy(g.v[6].name,"五食堂");
    g.v[7].num=8;
    strcpy(g.v[7].name,"男生宿舍");
    g.v[8].num=9;
    strcpy(g.v[8].name,"女生宿舍");
    g.v[9].num=10;
    strcpy(g.v[9].name,"竞知楼");
    g.v[10].num=11;
    strcpy(g.v[10].name,"莲池");
    g.v[11].num=12;
    strcpy(g.v[11].name,"南门");
    g.v[12].num=13;
    strcpy(g.v[12].name,"红楼");
}
void Creat_maps()
{
    int i,j;
    g.n=13;///13个景点
    g.m=19;///18条双向路径
    for(i=0; i<g.n; i++) ///初始化邻接矩阵
    {
        for(j=0; j<g.n; j++)
        {
            g.edgs[i][j]=INF;
        }
    }
    g.edgs[0][1]=g.edgs[1][0]=960;///写入边的信息
    g.edgs[0][10]=g.edgs[10][0]=690;
    g.edgs[0][12]=g.edgs[12][0]=940;
    g.edgs[1][2]=g.edgs[2][1]=600;
    g.edgs[1][3]=g.edgs[3][1]=510;
    g.edgs[1][12]=g.edgs[12][1]=780;
    g.edgs[2][3]=g.edgs[3][2]=90;
    g.edgs[2][9]=g.edgs[9][2]=900;
    g.edgs[2][12]=g.edgs[12][2]=360;
    g.edgs[3][4]=g.edgs[4][3]=370;
    g.edgs[4][5]=g.edgs[5][4]=210;
    g.edgs[5][6]=g.edgs[6][5]=160;
    g.edgs[5][12]=g.edgs[12][5]=1200;
    g.edgs[6][7]=g.edgs[7][6]=240;
    g.edgs[7][8]=g.edgs[8][7]=180;
    g.edgs[8][9]=g.edgs[9][8]=450;
    g.edgs[8][11]=g.edgs[11][8]=910;
    g.edgs[9][12]=g.edgs[12][9]=540;
    g.edgs[11][12]=g.edgs[12][11]=880;
}
void Search_info()
{
    int i,n;
    printf("九江学院主校区的景点有：\n");
    for(i=0; i<13; i++)
    {
        printf("%d:%s\n",g.v[i].num,g.v[i].name);
    }
    while(1)
    {
        printf("请输入你想要查询的景点编号：\n");
        printf("按0退出\n\n");
        scanf("%d",&n);
        getchar();
        if(n==0)
        {
            break;
        }
        else if(n<0||n>13)
        {
            printf("输入有误，请重新输入！！！\n\n");
            continue;
        }
        else
        {
            printf("%d:%s\n",g.v[n-1].num,g.v[n-1].name);
            printf("%s\n\n",g.v[n-1].info);
        }
    }
    return ;
}
void Floyd() ///弗洛伊德
{
    int i,j,k;
    for(i=0; i<g.n; i++) ///初始化距离与路径矩阵
    {
        for(j=0; j<g.n; j++)
        {
            dist[i][j]=g.edgs[i][j];
            if(i!=j&&dist[i][j]<INF)
            {
                path[i][j]=i;
            }
            else
            {
                path[i][j]=-1;///-1代表不可达
            }
        }
    }
    //printf("%d\n",g.n);
    for(k=0; k<g.n; k++)
    {
        for(i=0; i<g.n; i++)
        {
            for(j=0; j<g.n; j++)
            {
                if(dist[i][j]>(dist[i][k]+dist[k][j]))
                {
                    dist[i][j]=dist[i][k]+dist[k][j];///更新
                    path[i][j]=k;         ///path用于记录最短路径上的结点*/
                }
            }
        }
    }
    return ;
}
void Floyd_print(int s, int e)
{
    if(path[s][e]==-1||path[s][e]==e||path[s][e]==s)///递归终止条件
    {
        return;
    }
    else
    {
        Floyd_print(s,path[s][e]);///将中间点作为终点继续打印路径
        printf("%s->",g.v[path[s][e]].name);///打印中间景点名字
        Floyd_print(path[s][e],e);///将中间点作为起点继续打印路径
    }
}

void Dfs_allpath(int s,int e)
{
    int dis=0;
    int i,j;
    Stack[top]=s;
    top++;  ///起点入栈
    visited[s]=1;///标记入栈
    for(i=0; i<g.n; i++)
    {
        if(g.edgs[s][i]>0&&g.edgs[s][i]!=INF&&!visited[i])
        {
            ///表明两点可达且未被访问
            if(i==e)///DFS到了终点，打印路径
            {
                printf("第%d条路:",counts++);
                for(j=0; j<top; j++)
                {
                    printf("%s->",g.v[Stack[j]].name);
                    if(j<top-1)///统计路径长度
                    {
                        dis=dis+g.edgs[Stack[j]][Stack[j+1]];
                    }
                }
                dis=dis+g.edgs[Stack[top-1]][e];
                printf("%s\n",g.v[e].name);///打印终点
                printf("总长度是：%dm\n\n",dis);
            }
            else///不是终点接着DFS
            {
                Dfs_allpath(i,e);
                top--;///支路全被访问一遍,顶点出栈
                visited[i]=0;///出栈点标记为已出栈，允许下次访问
            }
        }
    }
}
void Bestpath_Multispot()
{
    int vNum[M]= {0};
    int i,j,dis;
    j=1;
    dis=0;///统计全程总长
    printf("请输入你要游览的第%d个景点的编号（输入-1结束输入）：",j);
    scanf("%d",&vNum[j-1]);
    while(vNum[j-1]!=-1&&j<13)
    {
        printf("请输入你要游览的第%d个景点编号：",++j);
        scanf("%d", &vNum[j-1]);
        if(vNum[j-1]==-1)
        {
            break;
        }
    }
    printf("\n这是最佳访问路径：");
    for(i=0; vNum[i]>0&&vNum[i+1]>0; i++)
    {
        printf("%s->",g.v[vNum[i]-1].name);///输出路径上的起点
        Floyd_print(vNum[i]-1,vNum[i+1]-1);///利用佛洛依德算法
        dis+=dist[vNum[i]-1][vNum[i+1]-1];
    }
    printf("%s\n\n",g.v[vNum[j-2]-1].name);///*输出路径上的终点*/
    printf("全程总长为：%dm\n\n",dis);
}

void Dis_menu()
{
    printf("\n");
    printf("       ************欢迎使用九江学院导游咨询系统***********\n\n");
    printf("       *****   2.两景点之间最短路查询       ******************\n");
    printf("       *****   3.两景点间所有路径查询       ******************\n");
    printf("       *****   4.多景点间访问路线查询       ******************\n");
    printf("       *****   5.退出系统                   ******************\n");
    printf("       *******************************************************\n");
    return ;
}
void Dis_map()
{
    printf("\n                          *九江学院校园景点地图一览*\n\n");
    printf("                                                         (1)北门       \n");
    printf("                                                            ◎-----------|    \n");
    printf("                                    ------------------- ----|            |    \n");
    printf("                                    | (11)莲池              |            |    \n");
    printf("                       --------------                       |----------◎     \n");
    printf("                       |（7）五食堂   （6)三食堂  (5)四服楼 |     (2)逸夫图书馆       \n");
    printf("                       |◎                    ◎   ◎       |            |    \n");
    printf("      (8)男生宿舍◎----|------------------—-|------|-------(4)香远楼    |    \n");
    printf("                |                            |              |            |     \n");
    printf("                |                            |              |            |     \n");
    printf("                |                            |          (3)厚德楼  ------|     \n");
    printf("            (9)◎女生宿舍  (10)竞知楼        |              |            |     \n");
    printf("                |-----------|---------------------------------           |     \n");
    printf("                |                            |                           |     \n");
    printf("                |                            |                           |     \n");
    printf("     (12)南门-- ◎主图------------------(13)红楼-------------------------     \n");
}
int main()
{
    int i,n;
    int start,ends;
    Creat_vertex();
    Creat_maps();
    Dis_map();
    while(1)
    {
        Dis_menu();
        printf("请输入需要操作的命令：\n");
        scanf("%d",&n);
        getchar();
        if(n<1||n>5)
        {
            printf("输入有误，请重新输入！！！\n");
            continue;
        }
        else
        {
            if(n==1)
            {
                Search_info();
            }
            else if(n==2)
            {
                Dis_map();
                printf("请输入起点的景点：\n");
                scanf("%d",&start);
                printf("请输入终点的景点：\n");
                scanf("%d",&ends);
                Floyd();///弗洛伊德
                printf("从%s到%s最短距离是：%d\n",g.v[start-1].name,g.v[ends-1].name,dist[start-1][ends-1]);
                printf("%s->",g.v[start-1].name);
                Floyd_print(start-1, ends-1);
                printf("%s\n",g.v[ends-1].name);
            }
            else if(n==3)
            {
                Dis_map();
                counts=1;///起始路径数为1
                printf("请输入起点的景点：\n");
                scanf("%d",&start);
                printf("请输入终点的景点：\n");
                scanf("%d",&ends);
                Dfs_allpath(start-1,ends-1);
            }
            else if(n==4)
            {
                Dis_map();
                Floyd();///弗洛伊德
                Bestpath_Multispot();
            }
            else if(n==5)
            {
                return 0;
            }
        }

    }
    return 0;
}

