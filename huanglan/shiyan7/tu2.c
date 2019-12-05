#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//校园导航系统
#define Max 100
#define INF 10000
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
    strcpy(G->place[0].name,"南门");
    strcpy(G->place[0].intro,"三大门之一的南门\n");
    G->place[1].index=2;
    strcpy(G->place[1].name ,"红楼");
    strcpy(G->place[1].intro,"外面刷了红色漆的建筑\n");
    G->place[2].index=3;
    strcpy(G->place[2].name,"女生宿舍");
    strcpy(G->place[2].intro,"女生的秘密基地\n");
    G->place[3].index=4;
    strcpy(G->place[3].name,"竞知楼");
    strcpy(G->place[3].intro,"江西省最大的教学楼。\n");
    G->place[4].index=5;
    strcpy(G->place[4].name,"厚德楼");
    strcpy(G->place[4].intro,"著名人才培养楼\n");
    G->place[5].index=6;
    strcpy(G->place[5].name,"男生宿舍");
    strcpy(G->place[5].intro,"男生的秘密天堂\n");
    G->place[6].index=7;
    strcpy(G->place[6].name,"香远楼");
    strcpy(G->place[6].intro,"外院妹子多又多\n");
    G->place[7].index=8;
    strcpy(G->place[7].name,"五食堂");
    strcpy(G->place[7].intro,"外国人的餐厅\n");
    G->place[8].index=9;
    strcpy(G->place[8].name,"三食堂");
    strcpy(G->place[8].intro,"人流量最大的食堂\n");
    G->place[9].index=10;
    strcpy(G->place[9].name,"四服楼");
    strcpy(G->place[9].intro,"美食奶茶天堂\n");
    G->place[10].index=11;
    strcpy(G->place[10].name,"逸夫图书馆");
    strcpy(G->place[10].intro,"最大图书馆\n");
    G->place[11].index=12;
    strcpy(G->place[11].name,"莲池");
    strcpy(G->place[11].intro,"爱心莲池\n");
    G->place[12].index=13;
    strcpy(G->place[12].name,"北门");
    strcpy(G->place[12].intro,"荒凉大门\n");
    G->place[13].index=14;
    strcpy(G->place[13].name,"义丰楼");
    strcpy(G->place[13].intro,"经管学院的上课之地\n");
    G->place[14].index=15;
    strcpy(G->place[14].name,"文友楼");
    strcpy(G->place[14].intro,"理学院的上课之地\n");
    G->place[15].index=16;
    strcpy(G->place[15].name,"立信楼");
    strcpy(G->place[15].intro,"会计学院的上课之地\n");
    G->place[16].index=17;
    strcpy(G->place[16].name,"西门");
    strcpy(G->place[16].intro,"比较荒凉\n");
    ////////////////////////////////////////
    //具体距离
   G->edge[0][1]=880;
   G->edge[1][0]=880;
   G->edge[0][2]=910;
   G->edge[2][0]=910;
   G->edge[1][3]=540;
   G->edge[3][1]=540;
   G->edge[1][9]=1200;
   G->edge[9][1]=1200;
   G->edge[1][4]=360;
   G->edge[4][1]=360;
   G->edge[2][5]=180;
   G->edge[5][2]=180;
   G->edge[2][3]=450;
   G->edge[3][2]=450;
   G->edge[8][3]=400;
   G->edge[3][8]=400;
   G->edge[3][4]=900;
   G->edge[4][3]=900;
   G->edge[4][6]=90;
   G->edge[6][4]=90;
   G->edge[5][7]=240;
   G->edge[7][5]=240;
   G->edge[7][8]=160;
   G->edge[8][7]=160;
   G->edge[8][9]=210;
   G->edge[9][8]=210;
   G->edge[9][6]=370;
   G->edge[6][9]=370;
   G->edge[6][10]=510;
   G->edge[10][6]=510;
   G->edge[10][1]=780;
   G->edge[1][10]=780;
   G->edge[7][11]=100;
   G->edge[11][7]=100;
   G->edge[10][11]=780;
   G->edge[11][10]=780;
   G->edge[10][12]=960;
   G->edge[10][12]=960;
   G->edge[11][12]=690;
   G->edge[12][11]=690;    
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
      printf("\n                          *九江学院校园景点地图一览*\n\n");
    printf("                                                         13.北门       \n");
    printf("                                                            ◎-----------|    \n");
    printf("                                    ------------------- ----|            |    \n");
    printf("                                    |  12.莲池              |            |    \n");
    printf("                       --------------                       |----------◎     \n");
    printf("                       |8.五食堂      9.三食堂  10.四服楼   |     11.逸夫图书馆       \n");
    printf("                       |◎                   ◎    ◎       |            |    \n");
    printf("      6.男生宿舍◎----|-------------------—-|------|-------------  7.香远楼    |    \n");
    printf("                |                            |              |            |     \n");
    printf("                |                            |              |            |     \n");
    printf("                |                            |           5.厚德楼  ------|     \n");
    printf("            3.◎女生宿舍  4.竞知楼           |              |            |     \n");
    printf("                |-----------|---------------------------------           |     \n");
    printf("                |                      |                           |     \n");
    printf("                |                      |                           |     \n");
    printf("     1.南门-- ◎主图------------------2.红楼-------------------------     \n");
	printf("        北            \n");
    printf("         |            \n");
    printf("   西---------东\n");
    printf("         |      \n");
    printf("        南    \n"); 
    printf("请输入您所选择的功能序号：\n"); 
    printf("1.查询最短路径\n");
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
            }
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


