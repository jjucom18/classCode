#include"guide.h"

int main(int argc, char **argv){
	int i,j;
	int start,end;
	int edgeData[MaxVerNum][MaxVerNum];
	VertexType data[MaxVerNum];
	int path[MaxVerNum][MaxVerNum];
	int dist[MaxVerNum][MaxVerNum];

	MGraph *graph = (MGraph *)malloc(sizeof(MGraph));
	initEdge(edgeData);
	initVnum(data);
	CreateMGraph(graph,data,edgeData);
	printf("请选择起始地址\n");
	start = SelectAddress();
	printf("请选择目的地\n");
	end = SelectAddress();
	floyd(graph,path,dist,start,end);
	return 0;
}
