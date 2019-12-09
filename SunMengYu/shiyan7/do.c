#include "do.h"
void menu()
{
	printf("\t\t\t\t九江学院\n");
	printf("\t\t\t欢迎进入校园导航系统");
	printf("\t\t\t[1]校园平面图\n\n");
	printf("\t\t\t[2]校园地点信息查询\n\n");
        printf("\t\t\t[3]所有路径\n\n");
	printf("\t\t\t[0]退出\n");
}
void switch1()
{
	int choice,k;
	AdjMatrix G;
	Create_Eex_AdjMatrix(&G);
	printf("\t\t\t\t\t请输入您所需要的功能:");
	scanf("%d",&choice);
	switch(choice)
	{
case1:map1();break;
case2:plcae(&G);break;
case3:All_Path()&G;break;
case0:break;
		default:
      printf("\t\t\t\t\t抱歉,您的输入有误!!!\n");
	}
	if(choice!=0){
		getchar();
		printf("\t\t\t\t\t按enter键返回\n");
		getchar();
		menu();
		switch1();
	}
}
int Locate(AdjMatrix *G,char name[])
{
	int i;
	for(i=1;i<=G->vexnum;i++){
		if(!strcmp(G->vex[i].name,name))
			return i;
	}
	return -1;
}
void Create_AdjMateix(AdjMatrix *G)
{
	int i,j,k,weight;
	char name1[50],name2[50];
	printf("\t\t\t创建新地图\n\n\n");
	printf("\t\t\t请输入学校中的景点数目和路径数目:");
	scanf("%d%d",&G->arcnum);


	for(i=1;j<=G->vexnum;i++){
		for(j=1;j<=G->vexnum;j++){
			G->arcs[i][j]=INFINITY;
		}
	}

	for(i=1;i<=G->vexnum;i++){
		printf("\t\t\t请分别输入第%d个景点序号和名子:字,i");
		scanf("%d %s",&G->vex[i].NO,G->vex[i].name);
	}printf("\n\n");

	for(k=1;k<=G->arcnum;k++){
		printf("\t\t\t请输入第NO.%d个相关联的两个景点名字和路径长度:",k);
		scanf("%s %s %d",name1,name2,&weight);
		i=Locate(G,name1);
		j=Locate(G,name2);
		G->arcs[i][j]=weight;
		G->arcs[j][i]=weight;
	}
	printf("\n\n\n\t\t\t\t\t创建新地图成功!\n\n");
	Store(G);
}


void Store(AdjMatrix *G)
{
	FILE *fp;
	if((fp=fopen("message","wt"))==NULL){
		printf("\t\t\t\t\t抱歉,无法正常存储!\n");
		return;
	}
	printf("存储信息中\n");
	fwrite(G,sizeof(AdjMatrix),1,fp);
	fclose(fp);
	printf("\t\t\t\t\t存储成功!\n\n\n");
}


AdjMatrix Read()
{
	FILE *fp;





