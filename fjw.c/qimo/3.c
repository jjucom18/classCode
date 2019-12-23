#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
/*----------------------------------*/
/*对于操作返回值以及链栈进行宏定义*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define MAXSIZE 100
/*----------------------------------*/


/*----------------------------------*/
/*数据类型的定义*/
typedef int Status;
typedef int Boolean;
typedef struct{
    int x,y,dir;
}point; // 点坐标的xy，以及下一步方向dir定义
/*
    对于dir的说明：
    1 表示向右
    2 表示向下
    3 表示向左
    4 表示向上
*/
typedef struct node{
    point point;
    struct node* next;
}Node; // 对于链栈中节点的定义
typedef Node ElemType;
typedef struct{
    Node * top;
    Node * bottom;
}Linkstack,*pLinkstack; // 对于链栈整体的定义

int NoSoutionReason = 0; //1 代表起点为障碍，2代表重点为障碍
int mp[MAXSIZE][MAXSIZE],n,m; // m,n表示迷宫规模，mp用来保存迷宫
int mpcopy[MAXSIZE][MAXSIZE]; // mpcopy用来保存和输出任务2所要求的路径
int visit[MAXSIZE][MAXSIZE];  // visit数组用来保存地图中某点是否访问过
point solution[MAXSIZE];  // solution用来保存任务2的遍历序列
int dx[] = {0,1,0,-1}; // dx为x方向坐标移动数组
int dy[] = {1,0,-1,0}; // dy为y方向坐标移动数组
int StartX = 0,StartY = 0;
int EndX = 0, EndY = 0;

/*----------------------------------*/

/*----------------------------------*/
/*
    链栈的操作
    包括：  初始化，判空，进栈，出栈，取栈顶，求栈长操作。
*/
Status Init(Linkstack &S)
{
    Node * p = (Node *)malloc(sizeof(Node));
    if(!p) return ERROR;
    S.bottom = S.top = p;
    p->next = NULL;
    return OK;
}
Status IsEmpty(Linkstack S)
{
    if(S.bottom == S.top) return TRUE;
    else return FALSE;
}
Status Push(Linkstack & S, ElemType e)
{
    Node * p = (Node *)malloc(sizeof(Node));
    if(!p) return ERROR;
    p->point.x = e.point.x;
    p->point.y = e.point.y;
    p->point.dir = e.point.dir;
    p->next = S.top;
    S.top =  p;
    return OK;
}
Status Pop( Linkstack & S,ElemType & e)
{
    if(S.bottom == S.top) return ERROR;
    Node * p = S.top;
    e.point.x  = p->point.x;
    e.point.y  = p->point.y;
    e.point.dir = p->point.dir;
    S.top = p->next;
    free(p);
    return OK;
}
Status GetTop(Linkstack S, ElemType &e)
{
    if(S.bottom == S.top) return ERROR;
    else {
        e.point.x = S.top->point.x;
        e.point.y = S.top->point.y;
        e.point.dir = S.top->point.dir;
    }
    return OK;
}
Status GetLength(Linkstack S)
{
    Node * p = S.top;
    int cnt = 0;
    while(p != S.bottom){
        cnt++;
        p = p->next;
    }
    return cnt;
}
/*----------------------------------*/

/*----------------------------------*/
/*迷宫求解部分*/
Status OutPut_Path_1(Linkstack S)
{
    /*按照任务1的要求输出(x,y,dir)三元组来表示路径*/
    if(S.top == S.bottom) return ERROR;
    printf("任务1的一条可行路径：");
    Node * p = S.top;
    Linkstack Stemp; //临时栈
    Init(Stemp);
    Node nodetemp;
    /*将栈S中的序列逆置到Stemp中*/
    while(p != S.bottom){
        nodetemp.point.x = p->point.x;
        nodetemp.point.y = p->point.y;
        nodetemp.point.dir = p->point.dir;
        Push(Stemp,nodetemp);
        p=p->next;
    }
    p = Stemp.top;
    /*输出栈Stemp*/
    while(p!= Stemp.bottom){
        printf("(%d,%d,%d) ",p->point.x,p->point.y,p->point.dir);
        p = p->next;
    }
    printf("\n\n");
    return OK;
}
void OutPut_Puzzle()
{
    /*输出迷宫*/
    for(int i = 0; i<m; ++i){
        for(int j = 0; j<n; ++j){
            //printf("%d %d\n",i,j);
            if(i == StartX && j == StartY && mp[i][j] != 1){
                printf("S ");
                continue;
            }
            if(i == EndX && j == EndY && mp[i][j] != 1 ){
                printf("E ");
                continue;
            }
            if(mp[i][j] == 1) printf("■");
            else printf("  ");
        }
        printf("\n");
    }
}
bool check(int x ,int y)
{
    /*检查xy坐标是否越界，以及mp[x][y]是否符合访问规则*/
    if(x<=0||x>m||y<=0||y>n||visit[x][y] == 1||mp[x][y] == 1)
        return false;
    return true;
}
bool Solve_1(Linkstack &S)
{
    /*
        按照任务1的用非递归输出1条路径
        1.首先将起点入栈
        2.然后依次找到下一个访问节点，依次入栈
        3.若当前节点无法拓展，则出栈
        4.直到走到出口，返回true，或者无通路，返回false
    */
    if(mp[StartX][StartY] == 1){
        printf("当前迷宫无通路\n");
        printf("因为入口%d %d为障碍\n",StartX,StartY);
        return false;
    }  //若起点为1， 特判
    if(mp[EndX][EndY] == 1) {
        printf("当前迷宫无通路\n");
        printf("因为出口%d %d为障碍\n",EndX,EndY);
        return false;
    }    //若终点为1， 特判
    point temp = {StartX,StartY,0};
    Node nodetemp = {temp,NULL},nodemem;
    Init(S);
    Push(S,nodetemp);
    visit[StartX][StartY] = 1;
    while(!IsEmpty(S)){
        GetTop(S,nodetemp);
        bool isfind = false;
        if(nodetemp.point.x == EndX && nodetemp.point.y == EndY)
            return true;
        for(int i = 0; i<4;++i){
            int nextx = nodetemp.point.x+dx[i];
            int nexty = nodetemp.point.y+dy[i];
            if(check(nextx,nexty)){
                int dir = i+1;
                Pop(S,nodemem);
                nodemem.point.dir = dir;
                Push(S,nodemem);
                nodetemp.point.x = nextx;
                nodetemp.point.y = nexty;
                nodetemp.point.dir = 0;
                visit[nextx][nexty] = 1;
                Push(S,nodetemp);
                isfind = true;
                break;
            }
        }
        if(!isfind) Pop(S,nodetemp);
    }
    printf("当前迷宫无通路\n");
    return false;
}
void OutPut_Path_2(int id)
{
    /*
        按照任务2的要求，输出所有可能的路径
        1.首先将原mp拷贝给mpcopy
        2.按照solution数组给mpcopy做好标记
        3.输出mpcopy数组
    */
    for(int i = 0 ; i<m;++i)
        for(int j = 0 ; j<n;++j)
            mpcopy[i][j] = mp[i][j];
    for(int i = 0; i<=id;++i){
        point p = solution[i];
        mpcopy[p.x][p.y] = p.dir;
    }
    for(int i = 0 ; i<m;++i){
        for(int j = 0 ; j<n;++j){
            if(i == StartX && j == StartY){
                 printf(" S");
                 continue;
            }
            if(i == EndX && j == EndY){
                printf(" E");
                continue;
            }
            if(mpcopy[i][j] == 2) printf("→");
            else if(mpcopy[i][j] == 3) printf("↓");
            else if(mpcopy[i][j] == 4) printf("←");
            else if(mpcopy[i][j] == 5) printf("↑");
            else if(mpcopy[i][j] == 1) printf("■");
            else printf("  ");
        }
        printf("\n");
    }
    printf("\n");
}
void dfs(int id , int x, int y)
{
    /*
        按照任务2的要求，输出所有可能的路径
        此处dfs搜索的过程
    */
    visit[x][y] = 1;
    for(int i = 0;i<4;++i){
        int nextx = x+dx[i];
        int nexty = y+dy[i];
        if(check(nextx,nexty)){
            visit[nextx][nexty] = 1;//置为访问
            solution[id] = {x,y,i+2};
            if(nextx == EndX && nexty == EndY){
                OutPut_Path_2(id);
                visit[EndX][EndY] = 0;
                return;
            }
            dfs(id+1,nextx,nexty);
            visit[nextx][nexty] = 0;//回溯时置为未访问
        }
    }
}
void Solve_2()
{
    /*
        按照任务2的要求，输出所有可能的路径
        此处为调用dfs函数的过程
    */
    memset(visit,0,sizeof(visit));
    printf("任务2的所有可行解：\n");
    dfs(0,StartX,StartY);

}
void input()
{
    /*输入要处理的地图*/
    memset(mp,0,sizeof(mp));
    memset(visit,0,sizeof(visit));
    printf("所输入的迷宫为\n");
    for(int i = 0; i<m;++i){
        for(int j = 0; j<n;++j){
            scanf("%d",&mp[i][j]);
        }
    }
}
/*----------------------------------*/

int main()
{
    freopen("in.txt.","r",stdin);
    //freopen("out.txt","w",stdout);
    Linkstack S;
    int kase = 1;
    while(scanf("%d %d",&m,&n) != EOF){
        int NoSoutionReason = 0;
        printf("/*----------------------------------*/\n");
        printf("Case %d \n",kase++);
        scanf("%d %d",&StartX,&StartY);
        scanf("%d %d",&EndX,&EndY);
        printf("%d %d %d %d\n",StartX,StartY,EndX,EndY);
        input();
        OutPut_Puzzle();
        if(Solve_1(S)){
            OutPut_Path_1(S);
            Solve_2();
        }
        printf("\n");
    }
    return 0;
}1
