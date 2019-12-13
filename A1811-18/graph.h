#include <stdio.h>
#include <stdlib.h>

#define maxsize 20
typedef char VerType;
typedef int EdgeType;

typedef struct{
	VerType vexs[maxsize];//顶点表
	EdgeType Edge[maxsize][maxsize]; 
	int Ver,Edge;//定义顶点数和边数
}Graph;
Vertype getvalue(Graph *g,int i){
	if(i < 0 || i >=g->n)
		printf("Error!\n");
	return vexs[i];
}
void create(Graph *g){
	int i,j,k;
	printf("请输入顶点数和边数：\n");
	scanf("%d%d",g->Ver,g->Edge);
	printf("请输入%d个顶点的值：\n",g->Ver);
	getchar();
	for(i = 0;)
}


