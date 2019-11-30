nclude<stdin to.h>
# include<string.h>
# include<stdlib.h>
//校园导航系统
# define Max 100
# define INF 10000
typedef struct place {
    char name[20];//名字 
    int index;//下标 
    char intro[30];//简介 
}PLA;//定义位置
typedef struct {
    PLA place[Max];
    float edge[Max][Max];
    int vertexnum;//点的数目 
    int edgenum;//边数目 
}Graph;//定义一个图 
void Init_Graph(Graph *G);//初始化一个图
void show_menu(Graph * G);//输出菜单 
void shortestdistance(Graph *G);//求最短距离 
void display(Graph *G,int start,int end);//展示路径 
int path[Max][Max]={0};
int main(void)
{   Graph G;
    Init_Graph(&G);
    show_menu(&G);
    return 0;
}
void Init_Graph(Graph *G)
{
    int i,j;
    G->vertexnum=17;
    G->edgenum=20;
    ///////最初初始化一下图 
    for(i=0;i<G->vertexnum;i++)
    {
        for(j=0;j<G->vertexnum;j++)
        {
            if(i==j)
            {
                G->edge[i][j]=0;//初始化如果自己和自己就为0 
            }
            else
            {
                G->edge[i][j]=INF;//否则初始化为无线大 
            }
        }
    }
    ////////////////////具体输入图
    G->place[0].index=1;
    strcpy(G->place[0].name,"北大门");
    strcpy(G->place[0].intro,"学校北边出口\n");
    G->place[1].index=2;
    strcpy(G->place[1].name ,"田径馆");
    strcpy(G->place[1].intro,"内部有室内篮球场\n");
    G->place[2].index=3;
    strcpy(G->place[2].name,"香远楼");
    strcpy(G->place[2].intro,"里面有外国语，马克思等学院\n");
    G->place[3].index=4;
    strcpy(G->place[3].name,"厚德楼");
    strcpy(G->place[3].intro,"有一些创新创业的科技园\n");
    G->place[4].index=5;
    strcpy(G->place[4].name,"学生一食堂");
    strcpy(G->place[4].intro,"学校比较经济实惠的食堂\n");
    G->place[5].index=6;
    strcpy(G->place[5].name,"教工宿舍");
    strcpy(G->place[5].intro,"老师住宿地点\n");
    G->place[6].index=7;
    strcpy(G->place[6].name,"大礼堂");
    strcpy(G->place[6].intro,"各学院迎新晚会举办地点\n");
    G->place[7].index=8;
    strcpy(G->place[7].name,"南大门");
    strcpy(G->place[7].intro,"九院最繁华的大门\n");
    G->place[8].index=9;
    strcpy(G->place[8].name,"主图");
    strcpy(G->place[8].intro,"九江学院最大的图书馆\n");
    G->place[9].index=10;
    strcpy(G->place[9].name,"十一栋宿舍");
    strcpy(G->place[9].intro,"电子学院女生宿舍\n");
    G->place[10].index=11;
    strcpy(G->place[10].name,"十五栋宿舍");
    strcpy(G->place[10].intro,"电子学院男生宿舍\n");
    G->place[11].index=12;
    strcpy(G->place[11].name,"莲池");
    strcpy(G->place[11].intro,"九江学院最大的水池\n");
    G->place[12].index=13;
    strcpy(G->place[12].name,"三食堂广场");
    strcpy(G->place[12].intro,"分三层，一层实惠，二三层稍微高档些\n");
    G->place[13].index=14;
    strcpy(G->place[13].name,"四食堂");
    strcpy(G->place[13].intro,"食堂旁边还附有一条小吃街\n");
    G->place[14].index=15;
    strcpy(G->place[14].name,"西门");
    strcpy(G->place[14].intro,"升旗仪式地点\n");
    G->place[15].index=16;
    strcpy(G->place[15].name,"校医院");
    strcpy(G->place[15].intro,"暂时还没去过\n");
    G->place[16].index=17;
    strcpy(G->place[16].name,"竞知楼");
    strcpy(G->place[16].intro,"九江学院最高的大楼\n");
    /////////////////////////////////////////
    //具体距离
   G->edge[0][1]=70;
   G->edge[1][0]=70;
   G->edge[0][2]=1200;
   G->edge[2][0]=1200;
   G->edge[1][3]=1300;
   G->edge[3][1]=1300;
   G->edge[2][4]=150;
   G->edge[4][2]=150;
   G->edge[3][4]=200;
   G->edge[4][3]=200;
   G->edge[3][5]=300;
   G->edge[5][3]=300;
   G->edge[5][6]=200;
   G->edge[6][5]=200;
   G->edge[6][4]=200;
   G->edge[4][6]=200;
   G->edge[5][7]=350;
   G->edge[7][5]=350;
   G->edge[7][8]=200;
   G->edge[8][7]=200;
   G->edge[8][6]=150;
   G->edge[6][8]=150;
   G->edge[7][11]=400;
   G->edge[11][7]=400;
   G->edge[11][9]=250;
   G->edge[9][11]=250;
   G->edge[9][8]=100;
   G->edge[8][9]=100;
   G->edge[11][10]=50;
   G->edge[10][11]=50;
   G->edge[10][12]=80;
   G->edge[12][10]=80;
   G->edge[12][13]=30;
   G->edge[13][12]=30;
   G->edge[13][16]=200;
   G->edge[16][13]=200;
   G->edge[15][16]=150;
   G->edge[16][15]=150;
   G->edge[14][15]=700;
   G->edge[15][14]=700;    
}
void show_menu(Graph *G)
{
    int choice;
    int start;
    int end;
    int i;
    int returnmenu;
    int place;
    float minroad;
    int flag=0;
    do
    {
    system("cls");
    printf("----------欢迎来到某大学校园导航系统---------\n");
    printf("----------      以下为简易地图           ----------\n");
    printf("                                1.北门             \n");
    printf("                                2.田径馆           \n");
    printf("                                                   \n");
    printf("         12.莲池                                   \n");
    printf("15.西门                                            \n");
    printf("    11.十五栋   13.三食堂  14.四食堂               \n");
    printf("                                    3.香远楼       \n");
    printf("   10.十一栋         5.一食堂       4.厚德楼       \n");
    printf("              17.竞知楼                            \n");
    printf("                                                   \n");
    printf("       9.主图                                      \n");
    printf("                            6.教工宿舍             \n");
    printf("                                                   \n");
    printf("                             16.校医院             \n");
    printf("                             7.大礼堂              \n");
    printf("                                                   \n");
    printf("                              8南门                \n");
    printf("        北            \n");
    printf("         |            \n");
    printf("   西---------东\n");
    printf("         |      \n");
    printf("        南    \n"); 
    printf("请输入您所选择的功能序号：\n"); 
    printf("1.径\n");
    printf("2.查询景点信息\n");
    printf("3.退出\n");
    scanf("%d",&choice);
    if(choice==1)
    {
    
        printf("请输入起点以及终点序号：\n");
        scanf("%d%d",&start,&end); 
        if(start<0||start>17||end<0||end>17)
        {
            printf("输入有误!\n");
            exit(-1);
        }
        
        shortestdistance(G);
        minroad=G->edge[start-1][end-1];
        display(G,start,end);
        printf("最小路径为：%.2f M\n",minroad);
    }
    else if(choice==2)
    {
    
        printf("请输入您想查询位置的序号\n");
        scanf("%d",&place);
        for(i=0;i<G->vertexnum;i++)
        {
            if(place==i+1)
            {
                printf("该地点为:\n");
                puts(G->place[i].name);
                printf("简介为：\n");
                puts(G->place[i].intro);
            }

        }
        
        
        
        
    }
    else if(choice==3)
    {
        exit(-1);
    }
    else
    {
        printf("输入错误！\n");
    }
    printf("请输入是否返回主菜单(1就是，2就是不是)：\n");
    scanf("%d",&returnmenu);
    if(returnmenu==1)
    {
        flag=0;
    }
    else if(returnmenu==2)
    {
        flag=1;
    }
}
while(flag==0);
} 
void shortestdistance(Graph *G)
{
    
    int k,v,w;
    //k为中间点
    // v为起点
    //w为终点
    for(k=0;k<G->vertexnum;k++)
    {
        for(v=0;v<G->vertexnum;v++)
        {
            for(w=0;w<G->vertexnum;w++)
            {
                if(G->edge[v][w]>(G->edge[v][k]+G->edge[k][w]))
                {
                    G->edge[v][w]=G->edge[v][k]+G->edge[k][w];
                    path[v][w]=k;//v->w要经过 k 
         
                    path[w][v]=k;//w->v要经过 k 
                 } 
            }
        }
     } 
    
     
    
    
}
void display(Graph *G,int start,int end)
{
    int i=start-1;
    int j=end-1;
    printf("您要查询的两景点间最短路径是: ");
    if(G->edge[i][j]!=INF)
    {
        if(i<j)
        {
            printf("%s",G->place[end-1].name);
            while(path[i][j]!=0)
            {/*?把i到j的路径上所有经过的景点按逆序打印出来*/
                printf("<--");
                printf("%s",G->place[path[i][j]].name);
                if(i<j)
                    j=path[i][j];
                else
                    i=path[j][i];
iiii            }
            printf("<--");
            printf("%s",G->place[start-1].name);
            printf(" ");
            
        }
        else
        {
            printf("%s",G->place[start-1].name);
            while(path[i][j]!=0)
            {/*?把i到j的路径上所有经过的景点按顺序打印出来*/
                printf("-->");
                printf("%s",G->place[path[i][j]].name);
                if(i<j)
                    j=path[i][j];
                else
                    i=path[j][i];
            }
            printf("-->");
            printf("%s",G->place[end-1].name);
            printf(" ");
        
        }
    }
    else
        printf("输入错误！不存在此路！\n");
    printf(" ");
 } 

