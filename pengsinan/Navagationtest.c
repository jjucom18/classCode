#include"Navagayion.c"
#include<stdio.h>

int main()
{
	int i,n;
	int start,ends;
	Creat_vertex();
	Creat_maps();
	while(1)
	{Dis_menu();
	printf("请输入需要操作的命令：\n");
	scanf("%d",&n);
	getchar();
	if(n<1||n>5)
	{
		printf("输入有误，请重新输入！！！\n");
		continue;
	}
	else
	{
		if(n==1)
		{
			Search_info();
		}
		else if(n==2)
		{
			Dis_menu();
			printf("请输入起点的景点：\n");
			scanf("%d",&start);
			printf("请输入终点的景点：\n");
			scanf("%d",&ends);
			Floyd();
			printf("从%s到%s最短距离是：%d\n",g.v[start-1].name,g.v[ends-1].name,dist[start-1][ends-1]);
			printf("%s->",g.v[start-1].name);
			Floyd_print(start-1,ends-1);
			printf("%s\n",g.v[ends-1].name);
		}
		else if(n==3)
		{
			Dis_menu();
			counts=1;
			printf("请输入起点的景点：\n");
			scanf("%d",&start);
			printf("请输入终点的景点：\n");
			scanf("%d",&ends);
			Dfs_allpath(start-1,ends-1);
		}
		else if(n==4)
		{
			Dis_menu();
			Floyd();
			Bestpath_Multispot();
		}
		else if(n==5)
		{
			return 0;
		}
	}

	}
	return 0;
}
