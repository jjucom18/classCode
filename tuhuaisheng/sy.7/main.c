#include "graph_h"
int main(int argc,char *argv[]){
	GraphMatrix graph;
	Path path[MAXVEX];
	int tmp,cnt=0,pre=-1;
	int temppath[MAXVEX];
	int n,m;
	VexType va,vb;
	long totallen=0;
	long curlen=0;
	Init(&graph);
	printf("\n请输入起点终点");
	scanf("%s%s",va,vb);
	m=LocateVex(&graph,va);
	n=LocateVex(&graph,vb);
	if(m!=-1&&n!=-1){
		Dijkstra(&graph,path,m);
		for(tmp=0;tmp<MAXVEX;tmp++)
			temppath[tmp]=-1;
		pre=n;
		while(path[pre].pre!=-1){
			temppath[cnt]=pre;
			pre=path[pre].pre;
			cnt++;
		}
		temppath[cnt]=m;
		if(cnt<=0){
			if(m!=n)
				printf("%s->%s无路可走\n",graph.vexs[m],graph.vexs[n]);
			else
				printf("您输入的顶点重合\n");
		}else{
			tmp=cnt;
			printf("$s->",graph.vexs[temppath[tmp]]);
			for(;tmp>0;tmp--){
				printf("%s(%d)->",graph.vexs[temppath[tmp-1]],graph.arcs[temppath[tmp]][temppath[tmp-1]]);
			}
			printf("共:%d\n",totallen);
		}
	}else{
		printf("(%s<->%s)中有不存在的城市"。va,vb);
	}
}
