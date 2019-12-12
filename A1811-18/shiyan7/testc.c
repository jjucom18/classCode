#include "graph.h"

int main(int argc,char **argv)
{
	MGraph G;
	G.vexNum = 20;
	G.arcNum = 20;
	InitGraph(G);
	int i;
	Menu(G);
	scanf("%d",&i);
	while(i != 4){
		switch(i){
			case 1 :Menu(G);
					break;
			case 2://system("CLS");
				   Query(G);
				   //Menu(G);
				   break;
			case 3://system("CLS");
				   shortestPATH_Floyd(G);
				   break;
			case 4:
				   break;
			default:
				   printf("输入错误，请重新输入！\n");
		}
		scanf("%d",&i);
	}


	return 0;
}
