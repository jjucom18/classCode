#include "schoolmap.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argc[])
{GraphMatrix graph;
	Path path[MAXVEX];
	int tmp,cnt=0,pre=-1;
	int temppath[MAXVEX];
	int m,n;
	VexType va,vb;
	long totallen = 0;
	long curlen = 0;
	Init(&graph);
	printf("请输入您要查询的起点及终点\n");
	scanf("%s%s",&va,&vb);
	m = LocateVex(&graph,va);
	n = LocateVex(&graph,vb);
	if (m!=-1 &&n !=-1)
		Dijkstra(&graph,path,m);
	for (tmp=0;tmp<MAXVEX;tmp++)
		temppath[tmp] = -1;
	pre = n;
	while(path[pre].pre != -1
			{temppath[cnt] = pre;
			pre = path[pre].pre;
			cnt++;}
			temppath[cnt] = m;
			if (cnt <= 0)
			if(m != n)
			printf("%s->%s没有直通的路!\n",graph.vexs[m],graph.vexs[n]);
		else
			printf("您输入的是同一个地点！\n");
			else{
			tmp = cnt;
			printf("%s->",graph.vexs[temppath[tmp]]);
			for (; tmp>0;tmp--){
	printf("%s(%d)->",graph.vexs[temppath[tmp-1]],graph.arcs[temppath[tmp][temppath[tmp-1]]);
totallen += graph.arcs[temppath[tmp]][temppath[tmp-1]];}
printf("共：%d\n",totallen);
}
  }
  else {printf("(%s<->%s)有不存在的校园景点，请您修改！",va,vb);
  }}
