include "graph_h"
int LocateVex(GraphMatrix *g,VexType u){
	/*在图g中查找顶点d的编号*/
	int i;
	for (i=0;i<g->n;++i)
		if(strcmp(u,g->vexs[i])==0)
			return i;
	return -1;
}
void Init(GraphMatrix *g){
	/*初始化有向网，读入校园文件*/
	int i,j,k,w;
	int edgeNums;
	VexType va,vb;
	FILE *graphlist;
	graphlist=fopen("campusnav.txt","r");
	fscanf(graphlist,"%d",&g->n);
	fscanf(graphlist,"%d",&edgeNums);
	for(i=0;i<g->n;++i)
		fscanf(graphlist,"%s",g->vexs[i]);
	for(i=0;i<g->n;++i)
		for(j=0;j<->n;++j)
			g->arcs[i][j]=INT_MAX;
	for(k=0;k<edgeNums;++k){
		fscanf(graphlist,"%s%s%d",va,va,&w);
		i=LocateVex(g,va);
		j=LocateVex(g,vb);
		if(i!=-1&&j!=-1){
			g->arcs[i][j]=w;

		}else {
			printf("%s<->%s读取错误，请您仔细检查",va,vb);
		}
	}
	for(i=0;i<g->n;i++)
		g->arcs[i][i]=0;
	fclose(graphlist);
}
void Dijkstra(GraphMatrix *pgraph,Path dist[],int start){
	int i,j,min;
	AdjType minw;
	dist[start].len=0;
	dist[start].pre=0;
	pgraph->arcs[start][srart]=1;
	for(i=0;i<pgraph->n;i++){
		dist[i].len=pgraph->arcs[start][i];
		if(dist[i].len!=TNT_MAX)
			dist[i].pre=start;
		else
			dist[i].pre=-1;
	}
	dist[start].pre=-1;
	for(i=0;i<pgraph->n;i++){
		minw=TNT_MAX;
		min=start;
		for(j=0;j<pgraph->n;j++)
			if((pgraph->arcs[j][j]==0)&&(dist[j].len<minw)){
				minw=dist[j].len;
				min=j;
			}
		if(min==0)
			break;
		pgraph->arcs[min][min]=1;
		for(j=0;j<pgraph->n;j++){
			if(pgraph->arcs[j][j]==1)
				continue;
			if(dist[j].len>dist[min].len+pgraph->arcs[min][j]>&&dist[min].len+pgraph->arcs[min][j]>0){
				dist[j].len=dist[min].len+pgraph->arcs[min][j];
				dist[j].pre=min;
			}
		}
	}
}
