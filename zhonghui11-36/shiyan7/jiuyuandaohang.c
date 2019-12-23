#include "jiuyuandaohang.h"
     void view()                                //ditu
	 {
	  printf("\t|--------------------|         |----------------------------------|\n");          
	  printf("\t|--------------------|  南门   |----------------------------------|\n");
      printf("\t|..|大礼堂|.......................................................|\n");
      printf("\t|..|教工食堂|.....................................................|\n");
      printf("\t|.................................................................|\n");
      printf("\t|...............................|主图|............................|\n");
	  printf("\t|.................................................................|\n");
	  printf("\t|.................................................................|\n");
	  printf("\t|...........|竞知楼|..............................................|\n");
	  printf("\t|...|女生宿舍|........|一食堂|...|快递|.......男生宿舍|...........|\n");
      printf("\t|.................................................|五食堂|........|\n");
	  printf("\t|...........................|四服楼|..............................|\n");
	  printf("\t|...................................|厚德楼|..........|教学楼|....|\n");
	  printf("\t|...............................|公共机房|   |逸夫图书馆|.........|\n");
	  printf("\t|...............................................|北区田径馆|......|\n");
	  printf("\t|........................................|    |..... .............|\n");
	  printf("\t|----------------------------------------|北门|-------------------|\n");
	  }
																	
																	
void huanyingjiemian()	   //欢迎界面
{
	printf("\n\n\n");
	printf("\t\t\t\t		,'''╭⌒╮⌒╮.',''',,',.'',,','',.  \n");
	printf("\t\t\t\t	 ╱◥██◣''o',''',,',.''.'',,',.  \n");
	printf("\t\t\t\t	｜田｜田田│ '',,',.',''',,',.''  \n");
	printf("\t\t\t\t	╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬  \n\n\n");
	printf("\t\t\t\t☆☆☆☆☆☆欢迎来到九江学院导游系统☆☆☆☆☆☆");
	printf("\n\n\n");
	printf("\t\t\t\t\t\t1.校园全景查询查询");
	printf("\n\n");
	printf("\t\t\t\t\t\t2.景点最短路径查询");
	printf("\n\n");
	printf("\t\t\t\t\t\t3.查看景点信息");
	printf("\n\n");
	printf("\t\t\t\t\t\t4.查看推荐路线");
	printf("\n\n");
	printf("\t\t\t\t\t\t5.退出系统");
	printf("\n\n");
}
void jiesujiemian()
{
	/*printf("\t\t\t  ▅▅▅▅▅▅▅　　　▅▅▅▅▅　　　　▅ \n");
	printf("\t\t\t　　▅▅█▅▅　　　　█　▅　█　　　　█ \n");
	printf("\t\t\t　　█▅█▅█　　　　█　█　█　　　　█ \n");
	printf("\t\t\t　▅█▅█▅█▅　　　　◢◤▋　▅　　　▼ \n");
	printf("\t\t\t　　█　　▅█　　　██◤　███　　　● \n");
	*/
	printf("\t\t\t再见\n");
}
void Init()
{
	int i,j;
	g.vexnum=n;
	g.adjnum=17;
	for(i=0;i<n;i++)
		g.vex[i].num=i;
	strcpy(g.vex[0].name,"学院南门");strcpy(g.vex[0].inform,"学校人流量最大的一个门");
	strcpy(g.vex[1].name,"大礼堂");strcpy(g.vex[1].inform,"学校的比较大的活动都在这里举办，里面比较豪华");
	strcpy(g.vex[2].name,"主图书馆");strcpy(g.vex[2].inform,"学校的主图书馆，里面主要是文学类的书籍");
	strcpy(g.vex[3].name,"教工食堂");strcpy(g.vex[3].inform,"老师食堂，当然学生也可以去，物美价廉");
	strcpy(g.vex[4].name,"竞知楼");strcpy(g.vex[4].inform,"学校最大的一栋教学楼，我们电子最主要的活动地点");
	strcpy(g.vex[5].name,"女生宿舍");strcpy(g.vex[5].inform,"各个年级女生宿舍");
	strcpy(g.vex[6].name,"学生一食堂");strcpy(g.vex[6].inform,"一食堂，提供学生吃饭的地方");
	strcpy(g.vex[7].name,"快递");strcpy(g.vex[7].inform,"各个快递集中地方");
	strcpy(g.vex[8].name,"男生15栋");strcpy(g.vex[8].inform,"电子学院男生宿舍，旁边也是男生宿舍，周围看不到小姐姐");
	strcpy(g.vex[9].name,"五食堂");strcpy(g.vex[9].inform,"这里的饭菜感觉比较好吃");
	strcpy(g.vex[10].name,"四服楼");strcpy(g.vex[10].inform,"这里有超市，文具店等，很方便");
	strcpy(g.vex[11].name,"厚德楼");strcpy(g.vex[11].inform,"比较大的一个教学楼");
	strcpy(g.vex[12].name,"教学楼");strcpy(g.vex[12].inform,"聚集了各个二级学院的教学楼");
	strcpy(g.vex[13].name,"公共机房");strcpy(g.vex[13].inform,"给学生上机的地方");
	strcpy(g.vex[14].name,"逸夫图书馆");strcpy(g.vex[14].inform,"理工类的一个图书馆，我经常去这里学习");
	strcpy(g.vex[15].name,"室内田径馆");strcpy(g.vex[15].inform,"除了田径场还有羽毛球乒乓球场还有拉丁舞教学也在这里");
	strcpy(g.vex[16].name,"学院北门");strcpy(g.vex[16].inform,"学校的一个比较小的校门，我第一次来这个学校走的是这个门");
	
	
	for(i=0;i<g.vexnum;i++)
		for(j=0;j<g.vexnum;j++)
			g.adj[i][j].a=max;
	g.adj[0][1].a=g.adj[1][0].a=1;
	g.adj[1][2].a=g.adj[2][1].a=3;
	g.adj[1][3].a=g.adj[3][1].a=4;
	g.adj[3][4].a=g.adj[4][3].a=3;//主图与竞知楼
	g.adj[4][5].a=g.adj[5][4].a=1;
	g.adj[4][6].a=g.adj[6][4].a=2;
	g.adj[4][7].a=g.adj[7][4].a=2;
	g.adj[3][8].a=g.adj[8][3].a=8;
	g.adj[8][9].a=g.adj[9][8].a=2;
	g.adj[9][10].a=g.adj[10][9].a=2;
	g.adj[10][11].a=g.adj[11][10].a=2;
	g.adj[10][12].a=g.adj[12][10].a=2;
	g.adj[12][13].a=g.adj[13][12].a=3;
	g.adj[13][14].a=g.adj[14][13].a=4;
	g.adj[14][15].a=g.adj[15][14].a=5;
	g.adj[15][16].a=g.adj[16][15].a=6;
	g.adj[0][0].a=g.adj[1][1].a=g.adj[2][2].a=g.adj[3][3].a=g.adj[4][4].a=0;
	g.adj[5][5].a=g.adj[6][6].a=g.adj[7][7].a=g.adj[8][8].a=g.adj[9][9].a=0;
	g.adj[10][10].a=g.adj[11][11].a=g.adj[12][12].a=g.adj[13][13].a=g.adj[14][14].a=0;
	g.adj[15][15].a=g.adj[16][16].a=0;
}


void jingdianliebiao()	   //景点列表
{
	int i;
	printf("学院景点列表:\n\n");
	for(i=0;i<n;i++)                        
	{
		printf("%-4d%-16s%-56s\n\n",g.vex[i].num,g.vex[i].name,g.vex[i].inform);
	}
	
}
void jingdianjieshao()	   //景点介绍
{
	int choice,a,i;
	printf("学院景点:\n\n");
	for(i=0;i<n;i++)
	{
		printf("\t%-4d%-16s%\n",g.vex[i].num,g.vex[i].name);
	}
	do{
	printf("\n请输入你想查询的景点编号:\n");
	scanf("%d",&choice);
	if(choice>=0&&choice<n)
		printf("\n\n%-4d%-16s%-56s\n",g.vex[choice].num,g.vex[choice].name,g.vex[choice].inform);
	else
		printf("输入的景点错误,请输入0--16");
	printf("\n需要继续查询吗? 'y' or 'n'\n");
	getchar();
	a=getchar();
	system("cls");
	}while(a=='y');
	system("cls");
}
void zuiduanlujing()  //查找最短路径
{
	int i,j,flag;
	jingdianliebiao();
	printf("\n\n\n");
	do{
		flag=0;
	printf("请输入要查询的起始景点和目的景点的编号(输入完起始地点后回车输入目的地编号):\n");
	scanf("%d%d",&i,&j);
	if(i>=n||i<0||j>=n||j<0)flag=1;
	if(flag==1){
		printf("输入信息错误!\n\n");}
	}while(flag==1);
		floyed();
		printf("\n(%5s-->%5s)最短路径是:",g.vex[i].name,g.vex[j].name);
		juli(i,j);
}
void floyed()	//Floyed算法求两个景点最短路径
{
	
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			shortest[i][j]=g.adj[i][j].a;
			path[i][j]=0;
		}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(shortest[i][j]>shortest[i][k]+shortest[k][j])
					{
						shortest[i][j]=shortest[i][k]+shortest[k][j];
						path[i][j]=k;
						path[j][i]=k;
					}	//用path[][]记录从i到j最短路径上点j的前驱景点的编号
				
}	
void juli(int i,int j)	//打印两个景点的路径及最短距离
{
	int a,b;
	int p[20],count=0;		//p[]存储最短距离上的点，count来计数
	a=i;
	b=j;
	if(shortest[i][j]!=max)
	{
		if(i<j)
		{
			p[0]=b;
			count++;
			while(path[i][j]!=0)
			{
				p[count]=path[i][j];
				count++;
				if(i<j)
					j=path[i][j];
				else
					i=path[j][i];
			}
			p[count]=a;
			for(;count>=1;count--){
				printf("%5s-->",g.vex[p[count]].name);}
				printf("%5s",g.vex[p[count]].name);
				printf("\t\t最短路程是%d \n\n",shortest[a][b]);
		}
		else
		{
			printf("%5s-->",g.vex[a].name);
			while(path[i][j]!=0)
			{
				printf("%5s-->",g.vex[path[i][j]].name);
				if(i<j)
					j=path[i][j];
				else
					i=path[j][i];
			}
			printf("%5s",g.vex[b].name);
			printf("\t\t最短路程是%d \n\n",shortest[a][b]);
		}
		
	}
	else
		printf("输入错误\n");
}
void tuijianlujing()		//从某一点开始，打印出到其它各点的推荐路径
{
	int a,i;
	int flag;
	do{
	flag=0;
	printf("请输入起始点位子的编号:");
	scanf("%d",&a);	
	if(a<0||a>=n)flag=1;
	if(flag==1){
		printf("输入信息错误!\n\n");}}while(flag==1);
	floyed();
	printf("\n\n");
	for(i=0;i<n;i++)
	{	
		if(a==i)continue;
		juli(a,i);
	}

