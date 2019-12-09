nclude<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 40
#define Max_num 50
#define INFINITY 32768
#define LENGTH(a)  (sizeof(a)/sizeof(a[0]))


顶点结构体
typedef struct
{
    int NO;  //地点序号
        char name[50]; //地点名
        }Vextype;

        //邻接矩阵结构体
        typedef struct
        {
            int arcs[Max_num+1][Max_num+1];  //边集
                Vextype vex[Max_num+1];   //顶点集
                    int vexnum;    //顶点数目
                        int arcnum;    //边数目
                       }AdjMatrix;//
                        void switch1();
                        //主页面
                        void menu();
                        //打印平面图
                        void map1();
                        //根据地点名确定地点序号
                        int Locate(AdjMatrix *G, char name[]);
                        //采用邻接矩阵创建无向网
                        void Create_AdjMatrix(AdjMatrix *G);
                        //使用信息生成矩阵
                        void Create_Eex_AdjMatrix(AdjMatrix *G);
                        //输出无向网矩阵
                        void Print_AdjMatrix(AdjMatrix *G);
                        //深度优先遍历所有景点
                        void DFSTrave(AdjMatrix G );
                        void DFS(AdjMatrix G, int i);
                        //采用prim算法求最短连通图
                        void Prim(AdjMatrix *G, int start);
                        //查询从某个景点出发的最短连通图
                        void Prim_MiniSpanTree(AdjMatrix *G);
                        //采用Dijkstra算法求单元点的最短路径
                       void Dijkstra(AdjMatrix *G, int start, int end, int dist[], int path[][Max_num+1]);
                        //查询任意两景点间的最短路径
                        void Dij_Short_Path();
                        //查询任意两景点间的所有路径
                        void All_Path(AdjMatrix *G);
                        //查询地点信息
                        void plcae(AdjMatrix *G);

                        //存储信息
                        void Store(AdjMatrix *G);
                        //读取信息
                        AdjMatrix Read();

                        //添加新地点
                        void Add_Place();
                        //添加新路线
                        void Add_Route();                        //撤销旧路线
                    void Del_Route();
                        //撤销旧地点
      		    void Del_Place()；





