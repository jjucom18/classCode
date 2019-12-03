#include <stdio.h>
#include <stdlib.h>

#define M 5000              //假设两顶点之间没有路径,用5000来表示

typedef struct vexsinfo     //存放顶点信息的结构体

{

    int park;               //访问的标志

    int num;                //景点的编号

    char name[32];          //景点的名称

    char introduction[256]; //景点的介绍

}vexsinfo;

 

typedef struct MGraph       

{

    int r;                  //记录最短路径访问过的景点数目

    int minrude;            //记录最短路径的长度

    int min[50];            //记录最短路径经过的顶点信息

    int a[50];              //记录路线的数组

    vexsinfo vexs[50];      //存放顶点编号的数组，用vexsinfo结构体的变量vexsinfo定义，可以用

                            //该数组存放顶点信息            

    int arc[50][50];        //存放两点之间权值的邻接矩阵

    int v,e;                //顶点数和边数

} MGraph;

MGraph* CreateGraph()

{

    MGraph *G;

	int i,j,k;

	G=(MGraph*)malloc(sizeof(MGraph));

  //初始化访问标志

	for(i=0;i<10;i++){

    G->vexs[i].park=0;

    }


	//初始化顶点数目和路线数目

	G->v=10;

	G->e=13;

	//给景点数组编号

	for(i=1;i<=G->v;i++)

		G->vexs[i].num=i;

	for(j=1;j<=10;j++)

		for(k=1;k<=10;k++)

		{

			G->arc[j][k]=M;

		}

		//初始化矩阵,赋予每条边权值

			G->arc[1][2]=G->arc[2][1]=1;

			G->arc[1][3]=G->arc[3][1]=3;
			
			G->arc[1][4]=G->arc[4][1]=3;

			G->arc[1][10]=G->arc[10][1]=8;

			G->arc[2][6]=G->arc[6][2]=3;

			G->arc[4][3]=G->arc[3][4]=1;

			G->arc[4][5]=G->arc[5][4]=1;

			G->arc[9][5]=G->arc[5][9]=6;

			G->arc[6][7]=G->arc[7][6]=2;

			G->arc[7][8]=G->arc[8][7]=1;

			G->arc[10][7]=G->arc[7][10]=3;

			G->arc[8][9]=G->arc[9][8]=1;

			G->arc[8][10]=G->arc[10][8]=2;

			G->arc[9][10]=G->arc[10][9]=1;

      //初始化顶点信息

    strcpy(G->vexs[1].name ,"九江学院南门");
		strcpy(G->vexs[1].introduction ,"靠近最繁华的街道");
		strcpy(G->vexs[2].name ,"大礼堂");
		strcpy(G->vexs[2].introduction ,"庆典演出等活动");
    strcpy(G->vexs[3].name ,"主图书馆");
		strcpy(G->vexs[3].introduction ,"九江学院最大的图书馆");
		strcpy(G->vexs[4].name ,"蝶湖");
		strcpy(G->vexs[4].introduction ,"因其形状像蝴蝶被命名为'蝶湖'");
    strcpy(G->vexs[5].name ,"竞知楼");
    strcpy(G->vexs[5].introduction ,"九江学院最大的教学楼");
    strcpy(G->vexs[6].name ,"南区操场");
		strcpy(G->vexs[6].introduction ,"运动会、军训动员大会召开的地方");
    strcpy(G->vexs[7].name ,"三食堂");
    strcpy(G->vexs[7].introduction ,"九江学院最大的食堂");
    strcpy(G->vexs[8].name ,"男生14栋、15栋");
    strcpy(G->vexs[8].introduction ,"电子学院男生宿舍");
    strcpy(G->vexs[9].name ,"莲池");
    strcpy(G->vexs[9].introduction ,"莲池里面曾经有很多睡莲，很多人在此散心散步，是九江学院环境最好的地方");
    strcpy(G->vexs[10].name ,"九江学院西门");
		strcpy(G->vexs[10].introduction ,"九江学院正大门，是升国旗的地方");
    
    return G;

 

}

void RudeGraph(MGraph *G,int b,int w,int k,int sum){

        int p,j,n;

     

        if(b==w) {

                    for(p=0;p<k;p++){
                        printf("%d->",G->a[p]);
                    }
                    printf("%d  ",G->a[k]);
                    printf("路线总长：%dkm\n",sum);
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
        for(j=1;j<=10;j++){

           if(G->arc[b][j]<5000&&G->vexs[j].park==0){

                    k++;

                    G->a[k]=j;

                    sum+=G->arc[b][j];             

                    G->vexs[j].park=1;

                    RudeGraph(G,j,w,k,sum);    //用递归对所有路径进行深度搜索

                    k--;                       //递归返回这一层后对顶点信息进行重新初始化

                    G->vexs[j].park=0; 

                    sum-=G->arc[b][j];

            }

 

        }

   }

 

    return ;

}

 

int main(void)

{

    int c,i,p,k;

    MGraph *T;

    T=CreateGraph();

    while(1){

    printf("**********************************\n");

    printf("\t\t\t|  欢迎使用校园导游程序   |\n");

    printf("\t\t\t|  1.景点信息查询        |\n");

    printf("\t\t\t|  2.路线查询           |\n");

    printf("\t\t\t|  3.退出               |\n");

    printf("**********************************\n");

    printf("请输入您的选择：\n");


    scanf("%d",&c);

    if(c==1){

            printf("**********************************\n");

            printf("九江学院最美景点共有如下十处：\n");

            for(i=1;i<=10;i++){

                printf("%d.",T->vexs[i].num);

                printf("%s:    ",T->vexs[i].name);

                printf("%s\n",T->vexs[i].introduction);

            }

    }

 

    else if(c==2){

            printf("**********************************\n");

            printf("输入当前景点编号及目的地景点编号：\n");

            printf("（注：景点编号可在功能1内查询）\n");

            int b,w;

            //初始化访问标志

                    for(i=0;i<10;i++){

                    T->vexs[i].park=0;

                    }

            scanf("%d %d",&b,&w);

            while(b<1||b>10||w<1||w>10){

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

                for(p=0;p<T->r;p++){

                printf("%d->",T->min[p]);

                }

                printf("%d  ",T->min[T->r]);

                printf("路线总长：%dkm\n",T->minrude);

                T->minrude=100;                        //重新初始化最短路径长度

 

                        }

 

           }

    else if(c==3) break;

    else printf("输入错误，请重新输入：\n");

  }

  printf("祝参观旅游愉快，谢谢！");

 return 0;
} 
