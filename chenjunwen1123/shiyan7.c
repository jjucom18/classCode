#include<stdlib.h>  
#include<string.h>   
#define INFINITY      32767   
#define MAX_VERTEX_NUM      30 
#define MAX 30 
#define TRUE 1 
#define FALSE 0 

typedef struct{
  	int adj; 
}ArCell,ArcNode[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 
typedef struct{      char name[30];   
     	int num;  
    	char info[100];
}VexNode;
typedef struct{ 
   	VexNode vertex[MAX_VERTEX_NUM];   
     	ArcNode arcs;  
    	int vexnum,arcnum; 
}AdjMatrix;  
int LocateVex(AdjMatrix G,char* v){ 
int m=-1,i;
for(i=0;i<G.vexnum;i++)   
     	if(strcmp(v,G.vertex[i].name)==0){ 
		m=i;   
	 	break;  
    	}  
return m; 
}  
AdjMatrix CreateDN(){
  	AdjMatrix G; 
   	int i,j;    
      	G.vexnum=25;  
    	G.arcnum=31;
  	for(i=0;i<G.vexnum;i++)     
	   	G.vertex[i].num=i;      
	for(i=0;i<G.vexnum;i++)      
	for(j=0;j<G.vexnum;j++)   
      		G.arcs[i][j].adj=INFINITY;  


G.arcs[0][3].adj=400;      
G.arcs[0][4].adj=150;   
G.arcs[1][2].adj=150;     
G.arcs[1][6].adj=500;   
G.arcs[2][3].adj=50;    
G.arcs[3][5].adj=100;     
G.arcs[4][5].adj=200;    
G.arcs[4][6].adj=100;     
G.arcs[6][7].adj=50;    
G.arcs[6][11].adj=80;     
G.arcs[7][8].adj=5;
G.arcs[7][15].adj=5;    
G.arcs[8][9].adj=5;      
G.arcs[9][10].adj=35;      
G.arcs[9][14].adj=20;
G.arcs[10][11].adj=20;     
G.arcs[10][12].adj=5;
G.arcs[10][14].adj=30;
G.arcs[11][12].adj=5; 
G.arcs[12][13].adj=10;    
G.arcs[15][16].adj=20;  
G.arcs[15][17].adj=10; 
G.arcs[16][19].adj=100;      
G.arcs[16][18].adj=250;     
G.arcs[18][20].adj=20;      
G.arcs[19][21].adj=50; 
G.arcs[20][22].adj=30;     
G.arcs[22][23].adj=100;  
G.arcs[19][20].adj=400;    
G.arcs[21][20].adj=400; 
G.arcs[22][20].adj=450;            
strcpy(G.vertex[0].name,"北门");   
strcpy(G.vertex[0].info,"北门");   
strcpy(G.vertex[1].name,"西门"); 
strcpy(G.vertex[1].info,"西门");  
strcpy(G.vertex[2].name,"南门"); 
strcpy(G.vertex[2].info,"南门"); 
strcpy(G.vertex[3].name,"北区田径馆");     
strcpy(G.vertex[3].info,"北区田径馆");  
strcpy(G.vertex[4].name,"香远楼");  
strcpy(G.vertex[4].info,"香远楼");  
strcpy(G.vertex[5].name,"厚德楼");     
strcpy(G.vertex[5].info,"厚德楼");   
strcpy(G.vertex[6].name,"红楼");    
strcpy(G.vertex[6].info,"红楼");   
strcpy(G.vertex[7].name,"南区田径场");    
strcpy(G.vertex[7].info,"南区田径场");   
strcpy(G.vertex[8].name,"学生二食堂");    
strcpy(G.vertex[8].info,"学生二食堂");   
strcpy(G.vertex[9].name,"学生一食堂");    
strcpy(G.vertex[9].info,"学生一食堂");    
strcpy(G.vertex[10].name,"竞知楼");  
strcpy(G.vertex[10].info,"竞知楼");    
strcpy(G.vertex[11].name,"11栋电子女生宿舍"); 
strcpy(G.vertex[11].info,"11栋电子女生宿舍"); 
strcpy(G.vertex[12].name,"主图书馆");    
strcpy(G.vertex[12].info,"主图书馆"); 
strcpy(G.vertex[13].name,"逸夫图书馆");    
strcpy(G.vertex[13].info,"逸夫图书馆"); 
strcpy(G.vertex[14].name,"蝶湖");    
strcpy(G.vertex[14].info,"蝶湖"); 
strcpy(G.vertex[15].name,"校医院");     
strcpy(G.vertex[15].info,"校医院");    
strcpy(G.vertex[16].name,"15栋电子男生宿舍");    
strcpy(G.vertex[16].info,"15栋电子男生宿舍"); 
strcpy(G.vertex[17].name,"莲池和五柳湖");   
strcpy(G.vertex[17].info,"莲池和五柳湖");    
strcpy(G.vertex[18].name,"学生五食堂");   
strcpy(G.vertex[18].info,"学生五食堂"); 
strcpy(G.vertex[19].name,"学生三食堂");  
strcpy(G.vertex[19].info,"学生三食堂");    
strcpy(G.vertex[20].name,"四服楼"); 
strcpy(G.vertex[20].info,"四服楼");  
strcpy(G.vertex[21].name,"学生四食堂");  
strcpy(G.vertex[21].info,"学生四食堂");  
strcpy(G.vertex[22].name,"行政楼");    
strcpy(G.vertex[22].info,"行政楼"); 
strcpy(G.vertex[23].name,"万福超市");     
strcpy(G.vertex[23].info,"万福超市"); 

  for(i=0;i<G.vexnum;i++)   
 	for(j=0;j<G.vexnum;j++)  
    		G.arcs[j][i].adj=G.arcs[i][j].adj;     
return G;  }  

void ShortestPath_DIJ(AdjMatrix G)  { 
   	int v,w,i,min,c=0,x,ex=1,v0 ;  
    	int last[MAX], D[MAX], p[MAX][MAX];    
      	while(ex){ 
       		printf("请输入一个起始景点编号:");  
		scanf("%d",&v0);        
	      	if(v0<0||v0>G.vexnum)        
	      	{ 
	  		printf("景点编号不存在!请重新输入景点编号:"); 
	  		scanf("%d",&v0);       
	     	} 
	   	if(v0>=0&&v0<G.vexnum) 
		   	ex=0;      } 
   	for(v=0;v<G.vexnum;v++)     
       	{          last[v]=FALSE;  
		D[v]=G.arcs[v0][v].adj;    
	  	for(w=0;w<G.vexnum;w++)     
			p[v][w]=FALSE;  
		if(D[v]<INFINITY)   
	 	{    
	      	
		p[v][v0]=TRUE; 
   		p[v][v]=TRUE;          }      }  

	D[v0]=FALSE;  
    	last[v0]=TRUE; 
   	for(i=1;i<G.vexnum;i++)  
    	{          min=INFINITY;     
	   	for(w=0;w<G.vexnum;w++)      
		 	if(!last[w])        
				if(D[w]<min)   
		   		{        
			    		v=w;    
					min=D[w];    
		    		}       
	     	last[v]=1; 
       		for(w=0;w<G.vexnum;w++) 
	   		if(!last[w]&&(min+G.arcs[v][w].adj<D[w]))     
	       		{        
		       		D[w]=min+G.arcs[v][w].adj;    
		   		for(x=0;x<G.vexnum;x++)  
		   			p[w][x]=p[v][x]; 
				p[w][w]=TRUE;              }  
	} 
   	for(v=0;v<G.vexnum;v++){
      		if(v0!=v)printf("%s",G.vertex[v0].name);         
	       	for(w=0;w<G.vexnum;w++){
	  		if(p[v][w]&&w!=v0)printf("-->%s",G.vertex[w].name);       
		 	c++;   
	 	}
      		if(c>G.vexnum-1&&v0!=v)  
	  		printf("       最短总路线长%dm\n\n",D[v]);      }  }  
typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];  
typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
void ShortestPath_Floyd(AdjMatrix G,PathMatrix *P,DistancMatrix *D)  { 
      int u,v,w,i,k,j,ex=1; 
      for(v=0;v<G.vexnum;v++) /* 各对结点之间初始已知路径及距离*/ 
	      for(w=0;w<G.vexnum;w++){     
		      (*D)[v][w]=G.arcs[v][w].adj;      
		      for(u=0;u<G.vexnum;u++)      
			      (*P)[v][w][u]=FALSE;   
		      if((*D)[v][w]<INFINITY){  
		      	      (*P)[v][w][v]=TRUE; 
		     	      (*P)[v][w][w]=TRUE;        }      } 
      for(u=0;u<G.vexnum;u++)     
	      for(v=0;v<G.vexnum;v++)  
		      for(w=0;w<G.vexnum;w++)         
			      if((*D)[v][u]+(*D)[u][w]<(*D)[v][w]){          
				      (*D)[v][w]=(*D)[v][u]+(*D)[u][w];       
				      for(i=0;i<G.vexnum;i++)  
				  	      (*P)[v][w][i]=(*P)[v][u][i]||(*P)[u][w][i];  
		      	      }     
      while(ex){ 
     	      printf("请输入出发点和目的地的编号(用空格分开):\n\n");   
       	      scanf("%d%d",&k,&j);     
	      if(k<0||k>G.vexnum||j<0||j>G.vexnum){ 
	 	      printf("景点编号不存在!请重新输入出发点和目的地的编号:\n\n"); 
	 	      scanf("%d%d",&k,&j);        
	      }
    	      if(k>=0&&k<G.vexnum&&j>=0&&j<G.vexnum)   
       	      ex=0; 
      } 
      printf("%s",G.vertex[k].name);    
      for(u=0;u<G.vexnum;u++) 
     	      if((*P)[k][j][u]&&k!=u&&j!=u)   
	    	      printf("-->%s",G.vertex[u].name);   
printf("--->%s",G.vertex[j].name);   
printf("      最短总路线长%dm\n",(*D)[k][j]); 
}  
void ShowAll(AdjMatrix  G){
  	int v; 
printf("        _________________________________________________________________________________________\n\n");  
printf("       | 编号   |景点名称        | 简介                                                  |\n\n");   
for(v=0;v<G.vexnum;v++)   
printf("       |  %-3d  | %-15s| %-65s|\n",G.vertex[v].num,G.vertex[v].name,G.vertex[v].info);  
printf("       |_________________________________________________________________________________________|\n\n");  
}  
void Find(AdjMatrix G){ 
   	int k,ex=1;  
    	while(ex){
       		printf("请输入要查询的景点标号:\n\n");   
	  	scanf("%d",&k);  
	 	if(k<0||k>G.vexnum) 
		{    
	       		printf("您真幽默!请重新输入景点标号:\n\n"); 
	    		scanf("%d",&k);   
	      		if(k<0||k>G.vexnum)     
			{   
		  		printf("您太会开玩笑了!请重新输入景点标号:\n\n");   
		  		scanf("%d",&k); 
				if(k<0||k>G.vexnum)        
		       		{          
			     		printf("您不要玩我了!请重新输入景点编号:\n\n");     
					scanf("%d",&k); 
				}             }         }  
	  	if(k>=0&&k<G.vexnum)     
		  	ex=0;      }     
       	printf("\n\n景点编号:%d \n",G.vertex[k].num);   
     	printf("\n\n景点名称:%s \n",G.vertex[k].name);  
    	printf("\n\n景点简介:%s \n\n\n",G.vertex[k].info);  } 
void Display(){ 
  	printf("\n                                            九江学院校园导游\n\n");    
      	printf("                                                      ------电子工程学院\n"); 
   	printf("                                _____________________________________________ \n\n");  
    	printf("                                |            1.浏览校园全部景点              |\n\n");  
    	printf("                                |            2.查询任意景点信息              |\n\n");  
    	printf("                                |            3.查看全部浏览最短路线          |\n\n");   
     	printf("                                |            4.查询任意两点的最短路线        |\n\n"); 
   	printf("                                  |            5.退出导游系统                 |\n\n"); 
   	printf("                                  |____________________________________________|\n\n\n\n");  
    	printf("选择功能如下:\n\n");  }  
void main(){
  	system("color D"); 
        system("mode con: cols=128 lines=60"); 
   	AdjMatrix g;    
      	int i; 
   	PathMatrix a; 
   	DistancMatrix b;     
       	g=CreateDN();   
  	Display();    
      	while(1){ 
       		scanf("%d",&i);   
	 	if(i==1)     
	   	{     
	       		system("cls");   
	      		Display();       
		 	ShowAll(g);   //鏄剧ず鍏ㄦ櫙       
			printf("\n\n您可以继续选择使用本系统的其他服务，输入5退出系统:\n\n");    
	      		continue ;      
	    	}          if(i==2)     
	   	{           
		     	system("cls");        
		  	Display();   
	     		Find(g);      
			printf("\n\n您可以继续选择使用本系统的其他服务，输入5退出系统:\n\n");
	  		continue;      
	    	}          if(i==3)  
		{        
		  	system("cls");   
	     		Display();       
		 	ShortestPath_DIJ(g);      
	      		printf("\n\n您可以继续选择使用本系统的其他服务，输入5退出系统:\n\n");  
	    		continue;   
	 	}          if(i==4)     
	   	{              system("cls");    
	      		Display();       
		 	ShortestPath_Floyd(g,&a,&b);       
		 	printf("\n\n您可以继续选择使用本系统的其他服务，输入5退出系统:\n\n"); 
	   		continue;  
		}        
	      	if(i==5)      
	    	{   
	    		exit(0);    
	  	}      }  }  

