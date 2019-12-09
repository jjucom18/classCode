#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#define M 10000              //假设两顶点之间没有路径,用10000来表示
typedef struct vexsinfo     //存放顶点信息的结构体
{
	    int park;               //访问的标志,park=0是未被访问过
	        int num;                //景点的编号
		    char name[32];          //景点的名称
		        char introduction[256]; //景点的介绍
}vexsinfo;
typedef struct MGraph       
{  
	int r;                  //记录最短路径访问过的景点数目   
	int minrude;            //记录最短路径的长度 
	int min[50];            //记录最短路径经过的顶点信息    
	int a[50];              //记录路线的数目    
	vexsinfo vexs[50];      //存放顶点编号的数组，用vexsinfo结构体的变量vexsinfo定义
	int arc[50][50];        //存放两点之间权值的邻接矩阵
	int v,e;                //定点数和边数
} MGraph;
MGraph* CreateGraph()
{    

	MGraph *G;

	
	int i,j,k;
	G=(MGraph*)malloc(sizeof(MGraph));//初始化访问标志
	for(i=0;i<20;i++){
	G->vexs[i].park=0;
	}     //初始化顶点数目和路线数目
	G->v=20;
	G->e=20;
	//给景点数组编号
	for(i=1;i<=G->v;i++)
	G->vexs[i].num=i;
	for(j=1;j<=20;j++)
	for(k=1;k<=20;k++)
	{
	G->arc[j][k]=M;
	} //初始化矩阵,赋予每条边权值
	 G->arc[1][2]=G->arc[2][1]=300;
	 G->arc[2][3]=G->arc[3][2]=300;
	 G->arc[2][4]=G->arc[4][2]=300;
	 G->arc[3][4]=G->arc[4][3]=50;		
	 G->arc[3][5]=G->arc[5][3]=100;
	 G->arc[3][6]=G->arc[6][3]=70;			
	 G->arc[4][5]=G->arc[5][4]=100;		
	 G->arc[4][15]=G->arc[15][4]=200;		
	 G->arc[5][6]=G->arc[6][5]=90;		
	 G->arc[5][9]=G->arc[9][5]=120;		
	 G->arc[5][15]=G->arc[15][5]=150;			
	 G->arc[6][7]=G->arc[7][6]=400;		
	 G->arc[6][8]=G->arc[8][6]=330;
	 G->arc[7][8]=G->arc[8][7]=100;
	 G->arc[7][10]=G->arc[10][7]=150;
	 G->arc[8][9]=G->arc[9][8]=120;
	 G->arc[9][14]=G->arc[14][9]=210;
	 G->arc[10][11]=G->arc[11][10]=130;
	 G->arc[11][12]=G->arc[12][11]=100;
	 G->arc[11][20]=G->arc[20][11]=420;
	 G->arc[12][17]=G->arc[17][12]=110;
	 G->arc[12][20]=G->arc[20][12]=350;
	 G->arc[13][14]=G->arc[14][13]=200;
	 G->arc[13][18]=G->arc[18][13]=180;
	 G->arc[14][20]=G->arc[20][14]=500;
	 G->arc[16][17]=G->arc[17][16]=400;
	 G->arc[16][18]=G->arc[18][16]=800;
	 G->arc[18][19]=G->arc[19][18]=600;
	 //初始化顶点信息
	 strcpy(G->vexs[1].name ,"南  门");
	 strcpy(G->vexs[2].name ,"校医院");
	 strcpy(G->vexs[3].name ,"蝶湖");
	 strcpy(G->vexs[4].name ,"主图书馆");
	 strcpy(G->vexs[5].name ,"竞知楼");
	 strcpy(G->vexs[6].name ,"南区操场");
	 strcpy(G->vexs[7].name ,"红楼");
	 strcpy(G->vexs[8].name ,"教工食堂");
	 strcpy(G->vexs[9].name ,"取快递点");
	 strcpy(G->vexs[10].name ,"厚德楼");
	 strcpy(G->vexs[11].name ,"香远楼");
	 strcpy(G->vexs[12].name ,"公共机房");
	 strcpy(G->vexs[13].name ,"学生宿舍15#");
	 strcpy(G->vexs[14].name ,"学生三食堂");
	 strcpy(G->vexs[15].name ,"学生宿舍11#");
	 strcpy(G->vexs[16].name ,"北门");
	 strcpy(G->vexs[17].name ,"逸夫图书馆");
	 strcpy(G->vexs[18].name ,"莲池") ;
	 strcpy(G->vexs[19].name ,"西门");
	 strcpy(G->vexs[20].name ,"北区田径馆");
	 strcpy(G->vexs[1].introduction ,"是九江学院最繁华的门，周边是商业区");
	 strcpy(G->vexs[2].introduction ,"校医院负责全校师生的身体健康");
	 strcpy(G->vexs[3].introduction ,"蝶湖位于主图书馆前面，环境优美") ;
	 strcpy(G->vexs[4].introduction ,"主图书馆靠近学校南门，主要收藏着文学类书籍");
	 strcpy(G->vexs[5].introduction ,"是学校的标志性建筑，也是电子工程学院的教学楼");
	 strcpy(G->vexs[6].introduction ,"这个操场是学校举行运动会的地方");
	 strcpy(G->vexs[7].introduction ,"学校早期知名建筑，旁边靠着学校游泳池和篮球场");
	 strcpy(G->vexs[8].introduction ,"供学校教职工吃饭和休息的地方");
	 strcpy(G->vexs[9].introduction ,"学校中通快递代收点");
	 strcpy(G->vexs[10].introduction ,"是江西省第一个大学生产业孵化基地");
	 strcpy(G->vexs[11].introduction ,"外国语学院教学楼，CTE4和CTE6考点");
	 strcpy(G->vexs[12].introduction ,"学校计算机有关课程的教学地点");
	 strcpy(G->vexs[13].introduction ,"电子工程学院的男生宿舍楼");
	 strcpy(G->vexs[14].introduction ,"学生三食堂处于学校中心位置，是学校最大的食堂");
	 strcpy(G->vexs[15].introduction ,"电子工程学院的女生宿舍楼");
	 strcpy(G->vexs[16].introduction ,"北门是平常车辆通行最多的一个门");
	 strcpy(G->vexs[17].introduction ,"学校最大的图书馆，主要存放理工类书籍");
	 strcpy(G->vexs[18].introduction ,"蝶湖是学校主图书馆旁的");
	 strcpy(G->vexs[19].introduction ,"学校最大的一个门，国旗台就为于此处");
	 strcpy(G->vexs[20].introduction ,"往年学校新生报到处，学生体育测试点");
	 return G;
	 }
void RudeGraph(MGraph *G,int b,int w,int k,int sum)
{
	int p,j,n;
	if(b==w) {
	for(p=0;p<k;p++){
	printf("%d->",G->a[p]);
	}
	printf("%d  ",G->a[k]);
	printf("路线长度为：%dm\n",sum);
	if(sum<G->minrude){
	G->r=k;
	G->minrude=sum;
	for(p=0;p<=k;p++){
	G->min[p]=G->a[p];
	 }
	 }
	return ;
	}
	else{
	for(j=1;j<=20;j++){
	if(G->arc[b][j]<10000&&G->vexs[j].park==0)
	{
	k++;
	G->a[k]=j;
	sum+=G->arc[b][j];             
	G->vexs[j].park=1;
	RudeGraph(G,j,w,k,sum);    //通过递归对所有路径进行深度搜索
	k--;                       //递归返回这一层后对顶点信息进行重新初始化
	G->vexs[j].park=0; 
	sum-=G->arc[b][j];
	}
       	}
       	}
       	return; 
}
int main(int argc, char **argv)
{
	int c,i,p,k;
	MGraph *T;
	T=CreateGraph();
	while(1){
	printf("————————————————\n");
	printf("   欢迎使用九江学院导航系通  \n");
	printf("————————————————\n");
	printf("1.地点查询\n");
	printf("2.路线查询\n");
	printf("3.退出\n");
	printf("请选择你需要的功能：\n");
	scanf("%d",&c);
	if(c==1){
	printf("  —————————— \n");
	printf("九江学院共有如下二十处景点：\n");
	for(i=1;i<=20;i++){
	printf("%d.",T->vexs[i].num);
	printf("%s:    ",T->vexs[i].name);
	printf("%s\n",T->vexs[i].introduction);
	}
	}
	else if(c==2){
	printf("                   —————————————————————————   \n");
	printf("               分别输入你的当前地点编号和你想要去的地点编号并以空格为间隔:\n");
    printf("     1.南门 2.校医院 3.蝶湖 4.主图书馆 5.竟知楼 6.南区操场 7.红楼  \n"); 
	printf("   8.教工食堂 9.取快递点 10.厚德楼 11.香远楼 12.公共机房 13.学生宿舍15# \n");
	printf("14.学生三食堂 15.学生宿舍11# 16.北门 17.逸夫图书馆 18.莲池 19.西门 20北区田径馆\n ");
	//初始化访问标志
	int b,w;
	for(i=0;i<20;i++)
	{
	T->vexs[i].park=0;
	}
	scanf("%d %d",&b,&w);
       	while(b<1||b>20||w<1||w>20){			 
	       	printf("输入错误，请重新输入:\n");
      		scanf("%d %d",&b,&w);
	}
	if(b==w){
		printf("您已经在此景点,请重新输入：\n");
		scanf("%d %d",&b,&w);
	}
	else{
		T->a[0]=b;
		T->vexs[b].park=1;
		printf("从景点%d到景点%d共有如下路径：\n",b,w);
		RudeGraph(T,b,w,0,0);
		printf("最短路径为：\n");
		for(p=0;p<T->r;p++)
		{         
     		printf("%d->",T->min[p]);
		}
		printf("%d  ",T->min[T->r]);
		printf("路线总长：%dm\n",T->minrude);
		T->minrude=10000;     //重新初始化最短路径长度
	}
	}
	else if(c==3) break;
	else printf("输入错误，请重新输入：\n");
	}
	printf("感谢您的使用！\n");
	return 0;
}
