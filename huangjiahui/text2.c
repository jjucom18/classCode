#include<bits/stdc++.h>
#include<iostream>
#define inf 0xfffffff
#define MAXV 1000
#define sizes 9
using namespace std;
int v;
int x,y;
int m=1;
int maps[sizes][sizes]={
{0,inf,100,200,100,inf,inf,inf,inf},
{inf,0,500,inf,200,inf,inf,inf,inf},
{100,500,0,inf,inf,inf,inf,500,inf},
{200,inf,inf,0,inf,inf,inf,inf,200},
{100,200,inf,inf,0,inf,inf,inf,inf},
{inf,inf,inf,inf,inf,0,100,inf,500},
{inf,inf,inf,inf,inf,100,0,100,inf},
{inf,inf,500,inf,inf,inf,100,0,700},
{inf,inf,inf,200,inf,500,inf,700,0},
};
int mapkey[sizes][sizes];
int dis[100];
int judge;
void dfs(int x,int path[],int d)
{
    d++;
    path[d]=x;
    dis[x]=1;
    if(x==y&&d>=0)
    {
        for(int i=0;i<=d;i++)
        {
            printf("%d ",path[i]);
        }
        cout<<endl;
    }
    for(int i=0;i<sizes;i++)
    {
        if(dis[i]==0&&maps[x][i]!=inf&&x!=i)
        {
            dfs(i,path,d);
            dis[i]=0;
        }
    }
}
void chakan()
{
    int n;
    cout<<"欢迎来到查看函数\n";
    cout<<"请输入想要查看的标记序号\n";
    cin>>n;
    if(n==1)
        cout<<"宿舍"<<endl;
    else if(n==2)
        cout<<"图书馆"<<endl;
    else if(n==3)
        cout<<"办公楼"<<endl;
    else if(n==4)
        cout<<"理学院"<<endl;
    else if(n==5)
        cout<<"文学院"<<endl;
    else if(n==6)
        cout<<"食堂"<<endl;
    else if(n==7)
        cout<<"工程实训中心"<<endl;
    else if(n==8)
        cout<<"计算机中心"<<endl;
    else if(n==9)
        cout<<"校史馆"<<endl;
    system("pause");
    exit(0);
}
void Dispath(int dist[],int path[],int S[])//输出从顶点v出发的所有最短路径
{
    int i,j,k;int apath[MAXV],d;//存放一条最短路径(逆向)及其顶点个数cout<<"请输入另一个节点"<<endl;cin>>i;while(i==v)
    {
        cout<<"非法输入，请重新操作"<<endl;
        cin>>i;
    }if(S[i]==1&&i!=v)
    {
        printf("  从顶点%d到顶点%d的路径长度为:%d\t路径为:",v,i,dist[i]);
        d=0;
        apath[d]=i; //添加路径上的终点
        k=path[i];
        if(k==-1) //没有路径的情况
            printf("无路径\n");
        else //存在路径时输出该路径
        {
            while(k!=v)
            {
                d++;
                apath[d]=k;
                k=path[k];
            }
            d++;
            apath[d]=v; //添加路径上的起点
            printf("%d",apath[d]); //先输出起点
            for(j=d-1;j>=0;j--) //再输出其他顶点
                printf(",%d",apath[j]);
            printf("\n");
        }
    }
}
void dijkstra()
{
    cout<<"欢迎来到查询所有路线函数\n";
    cout<<"请输入起点\n";
    cin>>v;
    int dist[MAXV],path[MAXV];int S[MAXV]; 
//S[i]=1表示顶点i在S中, S[i]=0表示顶点i在U中int Mindis,i,j,u;for (i=0;i<sizes;i++){   dist[i]=maps[v][i];//距离初始化S[i]=0; 
//S[]置空if (maps[v][i]<inf)//路径初始化path[i]=v; 
//顶点v到顶点i有边时，置顶点i的前一个顶点为velsepath[i]=-1; 
//顶点v到顶点i没边时，置顶点i的前一个顶点为-1}S[v]=1;path[v]=0; 
//源点编号v放入S中for(i=0;i<sizes-1;i++)//循环直到所有顶点的最短路径都求出{   Mindis=inf;//Mindis置最大长度初值for(j=0;j<sizes;j++)//选取不在S中（即U中）且具有最小最短路径长度的顶点uif(S[j]==0&&dist[j]<Mindis){   u=j;Mindis=dist[j];}S[u]=1; 
//顶点u加入S中for(j=0;j<sizes;j++)//修改不在S中（即U中）的顶点的最短路径
        {
            if(S[j]==0)
            {
                if(maps[u][j]<inf&&dist[u]+maps[u][j]<dist[j]){   dist[j]=dist[u]+maps[u][j];path[j]=u;}
            }
        }}Dispath(dist,path,S);//输出最短路径
}
void deletes()
{
    int num;
    int node;
    int node1,node2;
    cout<<"欢迎来到删除函数"<<endl;
    cout<<"1.删除节点  2.删除边  请输入你要进行的操作的序号"<<endl;
    scanf("%d",&num);
    if(num==1)
    {
        cout<<"请输入您要删除的节点"<<endl;
        cin>>node;
        for(int i=0;i<sizes;i++)
        {
            if(node==i)
            {
                maps[i][node]=0;
            }
            else
            {
                maps[i][node]=inf;
                maps[node][i]=inf;
            }
        }
    }
    else if(num==2)
    {
        cout<<"请输入您要删除的边"<<endl;
        cin>>node1>>node2;
        while(node1==node2)
        {
            cout<<"非法输入"<<endl;
            cout<<"请输入您要删除的边"<<endl;
            cin>>node1>>node2;
        }
        maps[node1][node2]=inf;
        maps[node2][node1]=inf;
    }
    else
    {
        cout<<"非法输入"<<endl;
        deletes();
    }
    cout<<"进行检查打印"<<endl;
    for(int i=0;i<sizes;i++)
    {
        for(int j=0;j<sizes;j++)
        {
            cout<<maps[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    exit(0);
}
void panduan(int n)
{
    int path[100];
    int d=-1;
    switch(n)
    {
        case 1:
            chakan();
            break;
        case 2:
            dijkstra();
            break;
        case 3:
            deletes();
            break;
        case 4:
            cout<<"请输入你要查找的起点和终点"<<endl;
            scanf("%d%d",&x,&y);
            path[0]=x;
            cout<<"欢迎来到查看函数"<<endl;
            dfs(x,path,d);
            break;
        default:
            printf("请重新输入输入选择项目序号(1-4):\n");
            cin>>n;
            panduan(n);
    }
    return;
}
int main()
{
    system("color 0E");
    int x;
    printf("—————————————————欢迎来到校园导航———————————————————\n");
    printf("——————————————————————菜单项————————————————————————\n");
    printf("—————————————————1.查看景点详细信息——————————————————\n");
    printf("—————————————————2.查询最短路径———————————————————————\n");
    printf("——————————————————3.删除操作———————————————————————————\n");
    printf("———————————————4.查看某景点到其他景点路线——————————————\n");
    printf("输入选择项目序号(1-4):\n");
    cin>>judge;
    panduan(judge);
    return 0;
}
————————————————
版权声明：本文为CSDN博主「幼儿园小班班长」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/w1248517085/article/details/78898871
