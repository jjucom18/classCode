#include "graph.h"
MGraph InitGraph(MGraph G){
	for(int i = 0;i < G.vexNum;i++)
		G.vex[i].num = i;//初始化每个景点的编号
	strcpy(G.vex[0].number,"南门");
	strcpy(G.vex[1].number,"教工食堂");
	strcpy(G.vex[2].number,"主图书馆");
	strcpy(G.vex[3].number,"竟知楼");
	strcpy(G.vex[4].number,"虹楼");
	strcpy(G.vex[5].number,"人工湖");
	strcpy(G.vex[6].number,"南区操场");
	strcpy(G.vex[7].number,"学生服务中心");
	strcpy(G.vex[8].number,"二食堂");
	strcpy(G.vex[9].number,"一食堂");
	strcpy(G.vex[10].number,"快递点");
	strcpy(G.vex[11].number,"三食堂");
	strcpy(G.vex[12].number,"四食堂服务中心");
	strcpy(G.vex[13].number,"蝶湖");
	strcpy(G.vex[14].number,"西门");
	strcpy(G.vex[15].number,"公共机房");
	strcpy(G.vex[16].number,"逸夫图书馆");
	strcpy(G.vex[17].number,"北区体育馆");
	strcpy(G.vex[18].number,"北门");
	strcpy(G.vex[19].number,"北门公交站");
	for(int i = 0;i < G.vexNum;i++){
		for(int j= 0;j < G.vexNum;j++)
			G.arcs[i][j] = INT_MAX;
	} //不存在的路线定义为无穷大
			G.arcs[0][1] = 200;
			G.arcs[0][2] = 400;
			G.arcs[1][3] = 300;
			G.arcs[2][3] = 100;
			G.arcs[2][4] = 100;
			G.arcs[2][5] = 100;
			G.arcs[3][9] = 700;
			G.arcs[3][6] = 300;
			G.arcs[3][7] = 300;
			G.arcs[4][8] = 600;
			G.arcs[5][8] = 400;
			G.arcs[9][10] = 100;
			G.arcs[9][11] = 400;
			G.arcs[10][11] = 200;
			G.arcs[11][12] = 200;
			G.arcs[11][13] = 200;
			G.arcs[12][15] = 200;
			G.arcs[13][14] = 200;
			G.arcs[15][16] = 200;
			G.arcs[15][17] = 200;
			G.arcs[17][18] = 200;
			G.arcs[18][19] = 200;
	//}
	for(int i = 0;i < G.vexNum;i++){//关于对角线对称
		for(int j = 0;j < G.vexNum;j++){
			G.arcs[j][i] = G.arcs[i][j];
		}
	}
	return G;
}//构造校园图
void Menu(MGraph G){
	printf("\n\n**********九江学院校园导航***********\n");
	printf("             |编号|      |功能|          \n");
	printf("               1          学校平面图\n");
	printf("               2          查看地点信息\n");
	printf("               3          两点之间的最短距离\n");
	printf("               4          退出\n");
	printf("请输入你的选择：\n");
}//主菜单
void Query(MGraph G){
	int k,flag=1;
 while(flag)
 {
  printf("请输入要查询的景点编号:");
  scanf("%d",&k);
  if(k<0||k>G.vexNum)
  {
     printf("景点编号不存在!请重新输入景点编号:");
     scanf("%d",&k);
  }
  if(k>=0&&k<G.vexNum)
   flag=0;  //跳出while结构,执行下面的输出
 }
 printf("***********************************************************************************\n");
 printf("* 编号 * 景点名称                                                           *  \n");
 printf("* %-4d * %-16s\n",G.vex[k].num,G.vex[k].number);
 printf("***********************************************************************************\n");
}//查找函数
void floyd(MGraph G){
	int D[max][max];
	int Path[max][max];
	int i,j,k;
	for(i = 0;i < G.vexNum;i++){//先进行初始化
		for(j = 0;j < G.vexNum;j++){
			D[i][j] = G.arcs[i][j];
			Path[i][j] = j;
		}
	}
	//计算最短路径
	for( k = 0;k < G.vexNum;k++){
		for(i = 0;i < G.vexNum;i++){
			for(j = 0;j < G.vexNum;j++){
				if(D[i][k] + D[k][j] < D[i][j]){
					D[i][j] = D[i][k] + D[k][i];
					Path[i][j] = Path[k][j];
				}
			}
		}
	}
	
}//floyd算法
void shortestPATH_Floyd(MGraph G){
	int i,j,p,m,k;
	int Path[max][max];
	int b[100];
	floyd(G);
	Number(G);
	do{
		printf("请输入起点编号：\n");
		scanf("%d",&i);
		printf("请输入终点编号：\n");
		scanf("%d",&j);
		if(i == j)
			printf("起点和终点一样，请重新输入！\n");
		else{
			if(i > 19 || i < 0 || k > 19 || k < 0)
				printf("输入有误请重新输入！\n");
		}
	}
	while(i == j || i > 19 || i < 0 || j > 19 || j < 0);
	//i = i - 1;
	//j = j - 1;
	if(i != j){
		printf("起点：%s,终点：%s\n最短路径：",G.vex[i+1].number,G.vex[j+i].number);
		p = Path[i][j];
		m = 0;
		b[m++] = p;
		p = Path[i][j];
	}
	b[m] = i;
	for(k = m;k > 0;k--){
		printf("%s->",G.vex[b[k] + 1].number);
	}
	printf("\n\n按任意键继续\n\n");
	getchar();
}//求最短路径



