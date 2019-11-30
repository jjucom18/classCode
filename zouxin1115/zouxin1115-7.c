#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Max 20
#define Init_Length  10000
void shortestdistance();
void print(){ printf("      九江学院\n"); 
	printf("      祝您旅途愉快\n"); 
	printf("以下是您可能要前往的地方\n");
	printf("1  教工食堂  \n"); 
	printf("2  蝶湖  \n");
	printf("3  主图书馆  \n"); 
	printf("4  竞知楼  \n");   
	printf("5 一食堂  \n"); 
	printf("6 快递代理点  \n");   
	printf("7  万福超市  \n");
	printf("8  女生宿舍  \n"); 
	printf("9 男生宿舍15栋  \n");
	printf("10 莲池  \n"); 
	printf("11 五食堂  \n");   
	printf("12三食堂  \n");   
	printf("13 四服楼  \n");
	printf("14 学生宿舍27-30栋  \n");
	printf("15 厚德楼 \n");
	printf("16 逸夫图书馆 \n");
	printf("17 北区篮球场 \n");
	printf("18 北区室内田径馆 \n");   
	printf("功能1.景点查询请输入 i\n");   
	printf("功能2.查询最短路径请输入 s\n"); 
	printf("功能3.退出系统请输入 e\n");         
	printf("请输入您的选择:");}
	void introduce()               
{ int a;                         
	printf("请输入景点编号:");
	scanf("%d",&a);
	getchar();                       
	printf("\n"); while(a<1||a>18)
	{  printf("ERROR ! 请输入数字 1 到  18:\n\n");
		scanf("%d",&a);  }

	printf("/n");}
	void main() { char k; 
		print(); 
		scanf("%c",&k);   
		while((k!='i')&&(k!='e')&&(k!='s'))
		{  getchar(); 
			printf("ERROR 请输入 i 或 s 或 e\n");
			scanf("%c",&k); }
		switch(k)   
		{  case 'i': printf("进入景点查询:\n");
			introduce();
			break;
			case 's': printf("进入最短路径查询:\n");
				  shortestdistance();
				  break; 
			case 'e': exit(0); }
	}
void shortestdistance()
{ int i,v,w,v0,j;
	int min;   
	int top[19]={0}; 
	int cost[19][19];   
	int path[19][19]; 
	int final[19]={0}; 
	int D[19];         
	for(i=0;i<19;i++) 
	for(j=0;j<19;j++)cost[i][j]=Init_Length;
	cost[1][3]=cost[3][1]=10;
	cost[3][5]=cost[5][3]=40;
	cost[1][7]=cost[7][1]=40;
	cost[3][7]=cost[7][3]=50;
	cost[2][7]=cost[7][2]=40;
	cost[2][6]=cost[6][2]=30;
	cost[4][6]=cost[6][4]=20;
	cost[4][13]=cost[13][4]=40;
	cost[6][12]=cost[12][6]=30;
	cost[12][8]=cost[8][12]=20;
	cost[8][9]=cost[9][8]=10;
	cost[6][9]=cost[9][6]=30;
	cost[10][9]=cost[9][10]=10;
	cost[6][10]=cost[10][6]=40;
	cost[9][10]=cost[10][9]=10;
	cost[9][11]=cost[11][9]=20;
	cost[1][15]=cost[15][1]= 50;
	cost[5][10]=cost[10][5]=30;
	cost[11][12]=cost[12][11]=10;
	cost[11][15]=cost[15][11]=40;
	cost[13][16]=cost[16][13]=30;
	cost[14][18]=cost[18][14]=40;
	cost[17][18]=cost[18][17]=5;
	cost[7][10]=cost[10][7]=35;
	printf("请输入您现在所在的位置:\n"); 
	scanf("%d",&v0);     
	while(v0>18||v0<1)     
	{      printf("ERROR!请重新输入编号从1到18的数\n");
		scanf("%d",&v0);     
	}     
	for(i=1;i<19;i++) 
	for(j=1;j<19;j++)   
	path[i][j]=0; 
	for(v=1;v<19;v++){          
		D[v]=cost[v0][v];
	if(D[v]<Init_Length) {      
		path[v][(++(top[v]))]=v0;
		path[v][(++(top[v]))]=v;      
	}
	} D[v0]=0;
	  final[v0]=1;   
	for(i=2;i<19;++i) 
	{      min=Init_Length; 
	for(w=1;w<19;++w){      
	if((final[w]==0)&&(D[w]<min)){      
		v=w;min=D[w];      
	}
	}   
		final[v]=1;     
	for(w=1;w<19;++w){      
	if((final[w]==0)&&(min+cost[v][w]<D[w])){        
		D[w]=min+cost[v][w];     
	for(j=1;j<19;j++)   
		path[w][j]=path[v][j]; 
		top[w]=top[v]+1; 
		path[w][(top[w])]=w;
			} 
		}
	}     printf("请输入你要去的地方:\n");   
	scanf("%d",&w);   
	printf("\n");   
	while(w>18||w<1){
        printf("ERROR!输入错误,请重新输入编号从1到18\n");   
		scanf("%d",&w);      
	}   
	printf("最短路径为:\n"); 
	for(i=1;path[w][i]!=0;i++)       
        printf("-->%d",path[w][i]);     
	printf("\n");
	printf("最短路径的长度为: %d\n",D[w]);
}

