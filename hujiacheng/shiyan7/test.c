#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <conio.h> 
#define NUM 20 
#define MAX 1000000 
int visited[NUM+1];
int minshort[NUM+1];
int head[1005];typedef struct
{
    int dis;
}Distance;typedef struct
{
    char name[100];
}Scenic;typedef struct
{
    Scenic Scen[NUM];
    Distance distance[NUM][NUM];
}Campus;Campus G;void init(int num)
{    printf("请输入学校各地点名称：\n");
   for(int i=1;i<=num;i++){
        printf("请输入第%d个地点的名称：\n",i);
        scanf("%s",&G.Scen[i].name);
   }   for(int i=1;i<=num;i++){
        for(int j=1;j<=num;j++){
            G.distance[i][j].dis = MAX;
        }
   }
   printf("输入完成，按任意键回到主菜单~");
}//菜单
int  mune(){                 //菜单函数
    int i;
    printf("           *************主菜单***************\n");
    printf("           *        1.初始化校园地点        * \n");
    printf("           *        2.查看校园地点          * \n");
    printf("           *        3.创建校园路径          * \n");
    printf("           *        4.查看校园路径          * \n");
    printf("           *        5.查看景点间的最短路径  * \n");
    printf("           *        6.退出系统              * \n");
    printf("           ********************************** \n");
    printf("请选择：");
    scanf("%d",&i);
    return i;
}
//查看输入地点概况
void ShowSchool(int num)
{
    for(int i=1;i<=num;i++){
        printf("        %d--->   %s\n",i,G.Scen[i].name);
    }
}//创建地图
void CreatCampus(int num)
{
    int start,endd,distance;
    printf("创建路径：起点和终点均在1~%d之间，起点为0退出创建路径\n",num);
    for(int i=0;i<num*(num-1);i++){
        printf("请输入第%d条路径：\n",i+1);
        printf("起点：");
        scanf("%d",&start);
        if(start==0){
            break;
        }
        printf("终点：");
        scanf("%d",&endd);
        printf("距离：");
        scanf("%d",&distance);
        G.distance[start][endd].dis = G.distance[endd][start].dis = distance;
    }}//迪杰斯特拉算法，算出一个点到其他点的最短路径
void dijiesite(int now,int num)
{
    for(int i=1;i<=num;i++){
        head[i]=i;
        minshort[i]=MAX;
    }
    int i,j,minn;
    for(i=1;i<=num;i++){
        visited[i]=0;
    }
    minshort[now]=0;
    for(i=1;i<=num;i++){
        int pos;
        minn=MAX;
        for(j=1;j<=num;j++){
            if(!visited[j]&&minshort[j]<minn){
                minn=minshort[j];
                pos=j;
            }
        }
        visited[pos]=1;
        for(j=1;j<=num;j++){
            if(!visited[j]&&minshort[j]>minshort[pos]+G.distance[pos][j].dis){
                minshort[j]=minshort[pos]+G.distance[pos][j].dis;
                head[j]=pos;
            }
        }
    }
}//显示创建的地图
void Show(int num)
{
    printf("校园图如下：\n");
    for(int i=1;i<=num;i++){
        for(int j=1;j<=num;j++){
            if(G.distance[i][j].dis==MAX){
                    printf("∞   ");
                }else{
                    printf("%d   ",G.distance[i][j].dis);
                }
        }
        printf("\n");
    }
}//输出最短路径及其路径走向
void ShortPath(int all)
{
    int shor[11],i,j,num;
    int start,endd;
    printf("请输入起点：");
    scanf("%d",&start);
    printf("请输入终点：");
    scanf("%d",&endd);
    dijiesite(start,all);
    if(minshort[endd]>=MAX){
        printf("抱歉，这里无法无法到达目的地~\n。");
    }else{
        printf("最短距离是：%d\n",minshort[endd]);
        printf("路径为：");
        for(j=endd,i=1;j!=start;j=head[j],i++){
            shor[i]=j;
        }
        shor[i]=start;
        for( num=i;num>1;num--){
            printf("%s->",G.Scen[shor[num]].name);
        }
        printf("%s\n",G.Scen[shor[num]].name);
    }
}void tShow()
{
    printf("\n点击任意键回到主菜单~~~");
}//程序开始
void SStart()
{
    int num;
    printf("请输入学校地点数目：\n");
      scanf("%d",&num);
      tShow();getch();system("cls");
    while(1){
  int i;
  i=mune();
  switch(i) {
      case 1:init(num);getch();system("cls"); break;
   case 2:ShowSchool(num);tShow();getch();system("cls"); break;
   case 3:CreatCampus(num);tShow();getch();system("cls"); break;
   case 4:Show(num);tShow();getch();system("cls"); break;
      case 5:ShortPath(num);tShow();getch();system("cls");break;
   case 6:printf("*~再见~*");exit(0);
   default: printf("输入不正确~\n");getch();system("cls"); break;
  }
 }
}int main()
{
    SStart();
    return 0;
}
