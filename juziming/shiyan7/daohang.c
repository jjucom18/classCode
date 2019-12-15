#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define INF 999999
#define M 20
int dist[M] [M] ;///距离
int path[M] [M] ;///路径
int Stack[M] ;///路径栈
int top;///栈顶
int counts;///记录路径数
int visited[M] ;///标记数组
using namespace std;
struct vertex///景点信息结构体
{
        int num;///景点编号
		char name[20] ;///景点名称
		char info[300] ;///景点介绍
} ;
struct maps
{
        int n;///点数
	    int m;///边数
		vertex v[M] ;
		int edgs[M] [M] ;///邻接矩阵
}  g; ///景点图的结构体
void Creat_vertex() 
{
 g.v[0] .num=1;
 strcpy(g.v[0] .name,"教职工家属楼") ;
 strcpy(g.v[0] .info,"这是学校老师职工的家属楼") ;
 g.v[1] .num=2;
 strcpy(g.v[1] .name,"大学生活动中心") ;
 strcpy(g.v[1] .info,"这是举办文艺活动的场所") ;
 g.v[2] .num=3;
 strcpy(g.v[2] .name,"餐饮区") ;
 strcpy(g.v[2] .info,"这里集中着学校的三大餐厅，物美价廉") ;
 g.v[3] .num=4;
 strcpy(g.v[3] .name,"办公实验楼") ;
 strcpy(g.v[3] .info,"8楼一下是学生实验区，以上是领导老师的办公区域") ;
 g.v[4] .num=5;
 strcpy(g.v[4] .name,"四教") ;
 strcpy(g.v[4] .info,"这是学校的第四座教学楼") ;
 g.v[5] .num=6;
 strcpy(g.v[5] .name,"五教") ;
 strcpy(g.v[5] .info,"这是学校的第五座教学楼") ;
 g.v[6] .num=7;
 strcpy(g.v[6] .name,"二教") ;
 strcpy(g.v[6] .info,"这是学校的第二座教学楼，也是计算机科学与技术学院的系楼") ;
 g.v[7] .num=8;
 strcpy(g.v[7] .name,"图书馆") ;
 strcpy(g.v[7] .info,"这是学校的图书馆，藏书丰富，是同学们阅读自习的好去处") ;
 g.v[8] .num=9;
 strcpy(g.v[8] .name,"三教") ;
 strcpy(g.v[8] .info,"这是学校的第三座教学楼") ;
 g.v[9] .num=10;
 strcpy(g.v[9] .name,"体育馆") ;
 strcpy(g.v[9] .info,"这是学生进行室内比赛和体育活动的场所") ;
 g.v[10] .num=11;
 strcpy(g.v[10] .name,"男生宿舍") ;
 strcpy(g.v[10] .info,"这是东校男生休息生活区域，有两座巨大的楼") ;
 g.v[11] .num=12;
 strcpy(g.v[11] .name,"东操场") ;
 strcpy(g.v[11] .info,"这是东校的田径操场，同学们都在这里锻炼身体") ;
 g.v[12] .num=13;
 strcpy(g.v[12] .name,"落雪湖") ;
 strcpy(g.v[12] .info,"这是学校的一座人工湖") ;
}
void Creat_maps() 
{

	    int i,j;
		g.n=13;///13个景点
		g.m=18;///18条双向路径
		for(i=0; i<g.n; i++)  ///初始化邻接矩阵
		{
            for(j=0; j<g.n; j++) 
			{
				g.edgs[i] [j] =INF;
			} 
}
g.edgs[0] [1] =g.edgs[1] [0] =500;///写入边的信息
    g.edgs[0] [2] =g.edgs[2] [0] =1000;
	    g.edgs[0] [7] =g.edgs[7] [0] =500;
		    g.edgs[1] [3] =g.edgs[3] [1] =200;
			    g.edgs[1] [4] =g.edgs[4] [1] =200;
				    g.edgs[2] [7] =g.edgs[7] [2] =400;
					    g.edgs[2] [10] =g.edgs[10] [2] =300;
						    g.edgs[3] [4] =g.edgs[4] [3] =300;
							    g.edgs[4] [5] =g.edgs[5] [4] =300;
								    g.edgs[4] [6] =g.edgs[6] [4] =100;
									    g.edgs[5] [6] =g.edgs[6] [5] =300;
										    g.edgs[5] [8] =g.edgs[8] [5] =200;
											    g.edgs[6] [8] =g.edgs[8] [6] =200;
												    g.edgs[6] [12] =g.edgs[12] [6] =100;
													    g.edgs[6] [7] =g.edgs[7] [6] =200;
														    g.edgs[8] [9] =g.edgs[9] [8] =500;
															    g.edgs[9] [11] =g.edgs[11] [9] =450;
																    g.edgs[10] [11] =g.edgs[11] [10] =300;]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
}
