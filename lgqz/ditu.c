#include<stdio.h>

#define MAX_INT 9999
#define N 15

int map[N][N] =
{
	{ 0, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ 1, 0, 1, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, 1, 0, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, 1, 1, 0, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, 1, 0, MAX_INT, MAX_INT, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 0, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, 0, MAX_INT, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, MAX_INT, MAX_INT, 0, MAX_INT, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, MAX_INT, 0, 1, MAX_INT, 1, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, 1, 0, MAX_INT, MAX_INT, 1, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 0, 1, MAX_INT, 1, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, MAX_INT, 1, 0, 1, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, MAX_INT, 1, 0, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, 0, 1 },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, 0 },
};

int mapClose[N][N] = 
{
	{ 0, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ 1, 0, 1, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, 1, 0, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, 1, 1, 0, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, 1, 0, MAX_INT, MAX_INT, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 0, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, 0, MAX_INT, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, MAX_INT, MAX_INT, 0, MAX_INT, 1, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, MAX_INT, 0, 1, MAX_INT, 1, MAX_INT, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, 1, 0, MAX_INT, MAX_INT, 1, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 0, 1, MAX_INT, 1, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, MAX_INT, 1, 0, 1, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, MAX_INT, 1, 0, MAX_INT, MAX_INT },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, 0, 1 },
	{ MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, MAX_INT, 1, 0 },
};

int road[N][N] = 
{
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 },
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 }
};

char * placeName[15] =
{
	"北门", "田径馆", "逸夫图书馆", "公共机房", "厚德楼",
	"西门", "升旗点", "四服楼", "15栋男生宿舍", "三食堂",
	"竞知楼", "学生食堂", "女生宿舍", "图书馆", "南门"
};

//输出地图
void printMap()
{
	printf("                          北门\n");
	printf("                           |  \n");
	printf("                           |  \n");
	printf("                         田径馆——逸夫图书馆\n");
	printf("                             \\        |\n");
	printf("                               \\      |\n");
	printf("                                公共机房\n");
	printf("                                    \\\n");
	printf("                                      \\\n");
	printf("                                      厚德楼\n");
	printf("                                     /\n");
	printf("                                   /\n");
	printf("     西门——升旗点            四服楼\n");
	printf("                  \\             |\n");
	printf("                    \\           |\n");
	printf("               15栋男生宿舍——三食堂\n");
	printf("                    |            |\n");
	printf("                    |            |\n");
	printf("     竞知楼——学生食堂——女生宿舍\n");
	printf("       |\n");
	printf("       |\n");
	printf("      图书馆\n");
	printf("       |\n");
	printf("       |\n");
	printf("      南门\n");

}

//输出所有最近的路
void printAllRoad()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				continue;
			}
			printf("%s--->%s最短距离：%d      最短路径：%s", placeName[i], placeName[j], mapClose[i][j], placeName[i]);
			for (int temp = road[i][j]; temp != road[temp][j]; temp = road[temp][j])
			{
				printf("-->%s", placeName[temp]);
			}
			printf("-->%s\n", placeName[j]);
		}
	}
}

//找最近的路
void searchCloseRoad()
{
	int startPlace, endPlace;
	for (int i = 0; i < N; i++)
	{
		printf("%d、%s\n", i + 1, placeName[i]);
	}
	printf("请输入起点：");
	scanf_s("%d", &startPlace);
	printf("请输入终点：");
	scanf_s("%d", &endPlace);
	startPlace--;
	endPlace--;
	printf("地图：\n");
	printMap();
	printf("%s--->%s最短距离：%d      最短路径：%s", placeName[startPlace], placeName[endPlace], mapClose[startPlace][endPlace], placeName[startPlace]);
	for (int temp = road[startPlace][endPlace]; temp != road[temp][endPlace]; temp = road[temp][endPlace])
	{
		printf("-->%s", placeName[temp]);
	}
	printf("-->%s\n", placeName[endPlace]);
}

int main()
{
	//弗洛伊德算法
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (mapClose[i][k] + mapClose[k][j] < mapClose[i][j])
				{
					mapClose[i][j] = mapClose[i][k] + mapClose[k][j];
					road[i][j] = road[i][k];
				}
			}
		}
	}
	//界面
	for (int num;;)
	{
		printf("请输入你的选项：\n");
		printf("1、查看地图\n");
		printf("2、查看所有最短路径\n");
		printf("3、查找最短路径\n");
		printf("0、退出\n");
		scanf_s("%d", &num);
		if (num == 1)
		{
			printMap();
		}
		else if (num == 2)
		{
			printAllRoad();
		}
		else if (num == 3)
		{
			searchCloseRoad();
		}
		else if (num == 0)
		{
			break;
		}
		else
		{
			printf("输入错误！");
		}



	}


	getchar();
	return 0;
}
