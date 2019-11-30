#include"map.h"
void init()
{
    int i,j;
    MGr.view[1].num=1;
    strcpy(MGr.view[1].date.name,"学校南门");
    strcpy(MGr.view[1].date.number,"001");
    strcpy(MGr.view[1].date.introduce,"位于前进东路，旁边有新天地广场、小吃街，购物方便，交通便利");
	
    MGr.view[2].num=2;
    strcpy(MGr.view[2].date.name,"教工食堂");
    strcpy(MGr.view[2].date.number,"002");
    strcpy(MGr.view[2].date.introduce,"教职工人员就餐的地方");
	
    MGr.view[3].num=3;
    strcpy(MGr.view[3].date.name,"校医院");
    strcpy(MGr.view[3].date.number,"003");
    strcpy(MGr.view[3].date.introduce,"校内学生体检、看病的地方");
	
    MGr.view[4].num=4;
    strcpy(MGr.view[4].date.name,"莲池");
    strcpy(MGr.view[4].date.number,"004");
    strcpy(MGr.view[4].date.introduce,"风景优美，提供安静的学习环境");
	
    MGr.view[5].num=5;
    strcpy(MGr.view[5].date.name,"图书馆");
    strcpy(MGr.view[5].date.number,"005");
    strcpy(MGr.view[5].date.introduce,"学习氛围浓厚，补充知识的地方");
	
    MGr.view[6].num=6;
    strcpy(MGr.view[6].date.name,"竞知楼");
    strcpy(MGr.view[6].date.number,"006");
    strcpy(MGr.view[6].date.introduce,"电子工程学院学生上课的地方");
	
    MGr.view[7].num=7;
    strcpy(MGr.view[7].date.name,"女生宿舍");
    strcpy(MGr.view[7].date.number,"007");
    strcpy(MGr.view[7].date.introduce,"电子工程学院女生宿舍");
	
    MGr.view[8].num=8;
    strcpy(MGr.view[8].date.name,"男生宿舍");
    strcpy(MGr.view[8].date.number,"008");
    strcpy(MGr.view[8].date.introduce,"电子工程学院男生宿舍");
	
    MGr.view[9].num=9;
    strcpy(MGr.view[9].date.name,"南区田径场");
    strcpy(MGr.view[9].date.number,"009");
    strcpy(MGr.view[9].date.introduce,"场地大，跑步，踢足球的好去处");
	
    MGr.view[10].num=10;
    strcpy(MGr.view[10].date.name,"学校西门");
    strcpy(MGr.view[10].date.number,"010");
    strcpy(MGr.view[10].date.introduce,"毗邻蝶湖，风景好");
	
    MGr.view[11].num=11;
    strcpy(MGr.view[11].date.name,"蝶湖");
    strcpy(MGr.view[11].date.number,"011");
    strcpy(MGr.view[11].date.introduce,"风景优美，安静清幽，适合晨练，散步");
	
    MGr.view[12].num=12;
    strcpy(MGr.view[12].date.name,"五食堂");
    strcpy(MGr.view[12].date.number,"012");
    strcpy(MGr.view[12].date.introduce,"各种快餐");
	
    MGr.view[13].num=13;
    strcpy(MGr.view[13].date.name,"三食堂");
    strcpy(MGr.view[13].date.number,"013");
    strcpy(MGr.view[13].date.introduce,"菜色丰富");
	
    MGr.view[14].num=14;
    strcpy(MGr.view[14].date.name,"四服楼");
    strcpy(MGr.view[14].date.number,"014");
    strcpy(MGr.view[14].date.introduce,"一楼餐饮，二楼快递，三楼超市");
	
    MGr.view[15].num=15;
    strcpy(MGr.view[15].date.name,"红楼");
    strcpy(MGr.view[15].date.number,"015");
    strcpy(MGr.view[15].date.introduce,"历史悠久");
	
    MGr.view[16].num=16;
    strcpy(MGr.view[16].date.name,"香远楼");
    strcpy(MGr.view[16].date.number,"016");
    strcpy(MGr.view[16].date.introduce,"外语学院，听听力的地方");
    MGr.view[17].num=17;
    strcpy(MGr.view[17].date.name,"宿舍楼");
    strcpy(MGr.view[17].date.number,"017");
    strcpy(MGr.view[17].date.introduce,"学生宿舍"); 
    MGr.view[18].num=18;
    strcpy(MGr.view[18].date.name,"北区田径场");
    strcpy(MGr.view[18].date.number,"018");
    strcpy(MGr.view[18].date.introduce,"跑步，锻炼的地方");
    MGr.view[19].num=19;
    strcpy(MGr.view[19].date.name,"公共机房");
    strcpy(MGr.view[19].date.number,"019");
    strcpy(MGr.view[19].date.introduce,"上与计算机有关课程的地方");
    MGr.view[20].num=20;
    strcpy(MGr.view[20].date.name,"室内田径馆");
    strcpy(MGr.view[20].date.number,"020");
    strcpy(MGr.view[20].date.introduce,"室内运动，上课的地方");
    MGr.view[21].num=21;
    strcpy(MGr.view[21].date.name,"21");
    strcpy(MGr.view[21].date.number,"021");
    strcpy(MGr.view[21].date.introduce,"邵逸夫图书馆");
    MGr.view[22].num=22;
    strcpy(MGr.view[22].date.name,"22");
    strcpy(MGr.view[22].date.number,"022");
    strcpy(MGr.view[22].date.introduce,"学校北门");

    for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
        {
			MGr.length[i][j]=MaxRoad;
        }
    }
    for(i=1;i<=N;i++)
    {
		shortest[i][j]=0;
    }
    MGr.length[1][2]=MGr.length[2][1]=200;
    MGr.length[2][3]=MGr.length[3][2]=25;
    MGr.length[3][4]=MGr.length[4][3]=50;
    MGr.length[4][5]=MGr.length[5][4]=100;
    MGr.length[4][6]=MGr.length[6][4]=50;
    MGr.length[5][7]=MGr.length[7][5]=75;
	MGr.length[6][7]=MGr.length[7][6]=50;
    MGr.length[7][8]=MGr.length[8][7]=150;
    MGr.length[7][9]=MGr.length[9][7]=150;
	MGr.length[8][10]=MGr.length[10][8]=200;
    MGr.length[8][11]=MGr.length[11][8]=50;
    MGr.length[8][9]=MGr.length[9][8]=200;
    MGr.length[8][12]=MGr.length[12][8]=50;
    MGr.length[8][13]=MGr.length[13][8]=75;
	MGr.length[13][14]=MGr.length[14][13]=25;
    MGr.length[13][15]=MGr.length[15][13]=200;
	MGr.length[17][14]=MGr.length[14][17]=75;
	MGr.length[14][16]=MGr.length[14][16]=50;
	MGr.length[16][19]=MGr.length[19][16]=50;
    MGr.length[17][18]=MGr.length[18][17]=50;
    MGr.length[18][20]=MGr.length[20][18]=50;
    MGr.length[20][22]=MGr.length[20][22]=100;
    MGr.length[19][21]=MGr.length[21][19]=50;
    MGr.length[21][22]=MGr.length[22][21]=150;
   
    MGr.length[1][1]=MGr.length[2][2]=MGr.length[3][3]=MGr.length[4][4]=0;
    MGr.length[5][5]=MGr.length[6][6]=MGr.length[7][7]=MGr.length[8][8]=0;
    MGr.length[9][9]=MGr.length[10][10]=MGr.length[11][11]=MGr.length[12][12]=0;
    MGr.length[13][13]=MGr.length[14][14]=MGr.length[15][15]=MGr.length[16][16]=0;
    MGr.length[17][17]=MGr.length[18][18]=MGr.length[19][19]=MGr.length[20][20]=0;
    MGr.length[21][21]=MGr.length[22][22]=0;

}
void introduce()
{
    int m;
    printf("请输入查询景点编号:\n");
    scanf("%d",&m); fflush(stdin);
    switch(m)
    {
	case 1:
		printf("景点编号:%s\t",MGr.view[1].date.number);
		printf("景点名称:%s\n",MGr.view[1].date.name);
		printf("景点简介:%s\n",MGr.view[1].date.introduce);
		break;
	case 2:
		printf("景点编号：%s\t",MGr.view[2].date.number);
		printf("景点名称：%s\n",MGr.view[2].date.name);
		printf("景点简介：%s\n",MGr.view[2].date.introduce);
		break;
	case 3:
		printf("景点编号：%s\t",MGr.view[3].date.number);
		printf("景点名称：%s\n",MGr.view[3].date.name);
		printf("景点简介：%s\n",MGr.view[3].date.introduce);
		break;
	case 4:
		printf("景点编号：%s\t",MGr.view[4].date.number);
		printf("景点名称：%s\n",MGr.view[4].date.name);
		printf("景点简介：%s\n",MGr.view[4].date.introduce);
		break;
	case 5:
		printf("景点编号：%s\t",MGr.view[5].date.number);
		printf("景点名称：%s\n",MGr.view[5].date.name);
		printf("景点简介：%s\n",MGr.view[5].date.introduce);
		break;
	case 6:
		printf("景点编号：%s\t",MGr.view[6].date.number);
		printf("景点名称：%s\n",MGr.view[6].date.name);
		printf("景点简介：%s\n",MGr.view[6].date.introduce);
		break;
	case 7:
		printf("景点编号：%s\t",MGr.view[7].date.number);
		printf("景点名称：%s\n",MGr.view[7].date.name);
		printf("景点简介：%s\n",MGr.view[7].date.introduce);
		break;
	case 8:
		printf("景点编号：%s\t",MGr.view[8].date.number);
		printf("景点名称：%s\n",MGr.view[8].date.name);
		printf("景点简介：%s\n",MGr.view[8].date.introduce);
		break;
	case 9:
		printf("景点编号：%s\t",MGr.view[9].date.number);
		printf("景点名称：%s\n",MGr.view[9].date.name);
		printf("景点简介：%s\n",MGr.view[9].date.introduce);
		break;
	case 10:
		printf("景点编号：%s\t",MGr.view[10].date.number);
		printf("景点名称：%s\n",MGr.view[10].date.name);
		printf("景点简介：%s\n",MGr.view[10].date.introduce);
		break;
	case 11:
		printf("景点编号：%s\t",MGr.view[11].date.number);
		printf("景点名称：%s\n",MGr.view[11].date.name);
		printf("景点简介：%s\n",MGr.view[11].date.introduce);
		break;
	case 12:
		printf("景点编号：%s\t",MGr.view[12].date.number);
		printf("景点名称：%s\n",MGr.view[12].date.name);
		printf("景点简介：%s\n",MGr.view[12].date.introduce);
		break;
	case 13:
		printf("景点编号：%s\t",MGr.view[13].date.number);
		printf("景点名称：%s\n",MGr.view[13].date.name);
		printf("景点简介：%s\n",MGr.view[13].date.introduce);
		break;
	case 14:
		printf("景点编号：%s\t",MGr.view[14].date.number);
		printf("景点名称：%s\n",MGr.view[14].date.name);
		printf("景点简介：%s\n",MGr.view[14].date.introduce);
		break;
	case 15:
		printf("景点编号：%s\t",MGr.view[15].date.number);
		printf("景点名称：%s\n",MGr.view[15].date.name);
		printf("景点简介：%s\n",MGr.view[15].date.introduce);
		break;
	case 16:
		printf("景点编号：%s\t",MGr.view[16].date.number);
		printf("景点名称：%s\n",MGr.view[16].date.name);
		printf("景点简介：%s\n",MGr.view[16].date.introduce);
	    break;
    case 17:
		printf("景点编号：%s\t",MGr.view[18] .date.number) ;
		printf("景点名称：%s\n",MGr.view[18] .date.name) ;	
		printf("景点简介：%s\n",MGr.view[18] .date.introduce) ;
		break;
    case 19:
		printf("景点编号：%s\t",MGr.view[19].date.number);
		printf("景点名称：%s\n",MGr.view[19].date.name);
		printf("景点简介：%s\n",MGr.view[19].date.introduce);
		break;
	case 20:
		printf("景点编号：%s\t",MGr.view[20].date.number);
		printf("景点名称：%s\n",MGr.view[20].date.name);
		printf("景点简介：%s\n",MGr.view[20].date.introduce);
		break;
    case 21:
		printf("景点编号：%s\t",MGr.view[21].date.number);
		printf("景点名称：%s\n",MGr.view[21].date.name);
		printf("景点简介：%s\n",MGr.view[21].date.introduce);
		break;
    case 22:
		printf("景点编号：%s\t",MGr.view[22].date.number);
		printf("景点名称：%s\n",MGr.view[22].date.name);
		printf("景点简介：%s\n",MGr.view[22].date.introduce);
		break;
	default:
		printf("输入序号错误。\n");
		break;
    }
    printf("\n");
}
void floyd()                 /*佛洛依德算法*/
{
    int i,j,k;
    for(i=1;i<=N;i++)
    {
		for(j=1;j<=N;j++)
		{
			shortest[i][j]=MGr.length[i][j];
			path[i][j]=0;
		}
    }   /*初始化数组*/
    for(k=1;k<=N;k++)
    {
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
			{
				if(shortest[i][j]>(shortest[i][k]+shortest[k][j]))
				{
					shortest[i][j]=shortest[i][k]+shortest[k][j];
					path[i][j]=k;
					path[j][i]=k;   /*记录经过的路径*/
				}
			}			
		}
    }
}
 
void display(int i,int j)
{         /*打印两个景点的路径及最短路径*/
    int a,b;
    a=i;
    b=j;
    printf("您要查询的两景点间最短路径是： \n\n");
    fflush(stdin);
	if(i<j)
	{
		printf("%d",b);
		while(path[i][j]!=0)
		{
			printf("<--%d",path[i][j]);
			if(i<j)
				j=path[i][j];
			else
				i=path[j][i];
		}
		printf("<-%d\n\n",a);
		printf("%d->%d的最短路径是： %d 米。\n\n",a,b,shortest[a][b]);
	}
	else
	{
		printf("%d",a);
		while(path[i][j]!=0)
		{      /*把i到j的路径上所有经过的景点按顺序打印出来*/
			printf("-->%d",path[i][j]);
			if(i<j)
				j=path[i][j];
			else
				i=path[j][i];
		}
		printf("->%d\n\n",b);
		printf("%d->%d的最短路径是： %d 米。\n\n",a,b,shortest[a][b]);
	}
}
 
int shortdistance()
{    /*要查找的两景点的最短路径*/
    int i,j;
    printf("请输入要查询的两个景点的数字编号(1->22)中间用空格间隔开。\n");
    scanf("%d %d",&i,&j);
    if(i>N||i<0||j>N||j<0)
    {
		printf("输入信息错误！\n\n");
		printf("请输入要查询的两个景点的数字编号（1->22）中间用空格间隔开。\n");
		scanf("%d %d",&i,&j);
    }
    else
    {
		floyd();
		display(i,j);
    }
    return 1;
    fflush(stdin);
}
void map()
{
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                     22.校园北门                            ┃\n");
    printf("┃                                                                            ┃\n");
	printf("┃                     20 .室内田径馆                              21 .逸夫楼 ┃\n");
	printf("┃                                                                            ┃\n");
	printf("┃                    18 .北区田径场                          19 .公共机房    ┃\n");
	printf("┃                                                                            ┃\n");
	printf("┃                             17 .宿舍楼                      16 .香远楼     ┃\n");
	printf("┃                                                                            ┃\n");
	printf("┃                                              14 .四服楼          15 .红楼  ┃\n");
	printf("┃                        12 .五食堂             13 .三食堂                   ┃\n");
	printf("┃10 .学校西门 11 .蝶湖                                                       ┃\n");
	printf("┃                   8 .男生宿舍                             9 .南区田径场    ┃\n");
	printf("┃                                                                            ┃\n");
	printf("┃                                                                            ┃\n");
	printf("┃                                         7 .女生宿舍                        ┃\n");
	printf("┃                     5 .图书馆                         6 .竞知楼            ┃\n");
	printf("┃                                                                            ┃\n");
	printf("┃                                               4 .莲池                      ┃\n");
	printf("┃                                                                            ┃\n");
	printf("┃                                                   3 .校医院                ┃\n");
    printf("┃                                                   2 .教工食堂              ┃\n");
	printf("┃                                                                            ┃\n");
	printf("┃                                 1 .学校南门                                ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n");
    fflush(stdin);
}
 
