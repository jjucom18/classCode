#include <string.h>

#include <stdio.h>

#include <malloc.h>

#include <stdlib.h>

#define Max 30000

#define NUM 10

typedef struct ArcCell

{


	int adj;

} ArcCell;

typedef struct VertexType

{


	int number;

	char *sight;

	char *description;

} VertexType; 

typedef struct
{


	VertexType vex[NUM] ;
	
	ArcCell arcs[NUM] [NUM] ;
	
	int vexnum,arcnum;
	
} MGraph; 

MGraph G; 

int P[NUM] [NUM] ;

long int D[NUM] ;

int  x[9] ={
	0} ;

		
	
	void main() 
	
{


	int v0,v1;

	char ck;

	CreateUDN(NUM,11) ;
	
	do
		
	{


		ck=Menu() ;
		
		switch(ck) 
			
		{


			case '1':

				system("cls") ;
				
				// narrate() ;
				
				 printf("\n\n\t\t\t请选择起点景点（0～10）：") ;
				
				 scanf("%d",&v0) ;
				
				 printf("\t\t\t请选择终点景点（0～10）：") ;
				
				scanf("%d",&v0) ;
				
				printf("\t\t\t请选择终点景点（0～9）：") ;
				
				scanf("%d",&v1) ;
				
				ShortestPath(v0) ;
				
				output(v0,v1) ;   
					
					printf("\n\n\t\t\t\t请按任意键继续...\n") ;
				
				getchar() ;
				
				getchar() ;
				
				break;
				
			case '2':search() ;
					 
					 break;
					 
			case '3':
					 
					 system("cls") ;
					 
					 //narrate();
					 x[0] =1; 
						 
						 HaMiTonian(1) ;
					 
					 printf("\n\n\t\t\t\t请按任意键继续...\n") ;
					 
					 getchar() ;
					 
					 getchar() ;
					 
					 break;
					 
		} ;
		
	} while(ck!='e') ;
	
} 

char Menu() 
	
{


	char c;

	int flag;

	do{


		flag=1;

		system("cls") ;
		
		narrate() ;
		
		printf("\n\t\t\t┏━━━━━━━━━━━━━━━┑\n") ;
		
		printf("\t\t\t┃                              ┃\n") ;
		
		printf("\t\t\t┃      1、查询景点路径       ┃\n") ;
		
		printf("\t\t\t┃      2、查询景点信息       ┃\n") ;
		
		printf("\t\t\t┃      3、推荐参观路线       ┃\n") ;
		
		printf("\t\t\t┃      t、退出                ┃\n") ;
		
		printf("\t\t\t┃                              ┃\n") ;
		
		printf("\t\t\t┗━━━━━━━━━━━━━━━┛\n") ;
		
		printf("\t\t\t\t请输入您的选择：") ;
		
		scanf("%c",&c) ;
		
		if(c=='1'||c=='2'||c=='3'||c=='t') 
			
			flag=0;
		
	} while(flag) ;
	
	return c;
	
} 

char SearchMenu() 
	
{


	char c;

	int flag;

	do{


		flag=1;

		system("cls") ;
		
		narrate() ;
		
		printf("\n\t\t\t┏━━━━━━━━━━━━━━━┑\n") ;
		
		printf("\t\t\t┃                              ┃\n") ;
		
		printf("\t\t\t┃      1、按照景点编号查询   ┃\n") ;
		
		printf("\t\t\t┃      2、按照景点名称查询   ┃\n") ;
		
		printf("\t\t\t┃      t、返回                ┃\n") ;
		
		printf("\t\t\t┃                              ┃\n") ;
		
		printf("\t\t\t┗━━━━━━━━━━━━━━━┛\n") ;
		
		printf("\t\t\t\t请输入您的选择：") ;
		
		scanf("%c",&c) ;
		
		if(c=='1'||c=='2'||c=='t') 
			
		flag=0;

	} while(flag) ;
	
	return c;
	
} 

void search() 
	
{


	int num;

	int i;

	char c;

	char name[20] ;
	
	do
		
	{


		system("cls") ;
		
		c=SearchMenu() ;
		
		switch (c) 
			
		{


			case '1':

				system("cls") ;
				
				narrate() ;
				
				printf("\n\n\t\t请输入您要查找的景点编号：") ;
				
				scanf("%d",&num) ;
				
				for(i=0;i<NUM;i++) 
					
				{


					if(num==G.vex[i] .number) 
						
					{


						printf("\n\n\t\t\t您要查找景点信息如下:") ;
						
						printf("\n\n\t\t\t%-25s\n\n",G.vex[i] .description) ;
						
						printf("\n\t\t\t按任意键返回...") ;
						
						getchar() ;
						
						getchar() ;
						
						break;
						
					} 
					
				} 
				
				if(i==NUM) 
					
				{


					printf("\n\n\t\t\t没有找到！") ;
					
					printf("\n\n\t\t\t按任意键返回...") ;
					
					getchar() ;
					
					getchar() ;
					
				} 
				
				break;
				
			case '2':
				
				narrate() ;
				
				system("cls") ;
				
				printf("\n\n\t\t请输入您要查找的景点名称：") ;
				
				scanf("%s",name) ;
				
				for(i=0;i<NUM;i++) 
					
				{


					if(!strcmp(name,G.vex[i] .sight) ) 
						
					{


						printf("\n\n\t\t\t您要查找景点信息如下:") ;
						
						printf("\n\n\t\t\t%-25s\n\n",G.vex[i] .description) ;
						
						printf("\n\t\t\t按任意键返回...") ;
						
						getchar() ;
						
						getchar() ;
						
						break;
						
					} 
					
				} 
				
				if(i==NUM) 
					
				{


					printf("\n\n\t\t\t没有找到！") ;
					
					printf("\n\n\t\t\t按任意键返回...") ;
					
					getchar() ;
					
					getchar() ;
					
				} 
				
				break;
				
		} 
		
	} while(c!='t') ;
	
} 

void CreateUDN(int v,int a) 
	
{


	int i,j;

	G.vexnum=v;

	G.arcnum=a;

	for(i=0;i<G.vexnum;++i)  G.vex[i] .number=i;
	
	G.vex[0] .sight="南门";
	
	G.vex[0] .description="人流量最多的门，对面是小吃街";
	
	G.vex[1] .sight="主图";
	
	G.vex[1] .description="内有诚信超市，学生自修室";
	
	G.vex[2] .sight="南区田径馆";
	
	G.vex[2] .description="运动健身";
	
	G.vex[3] .sight="竞知楼";
	
	G.vex[3] .description="九江学院最大教学楼";
	
	G.vex[4] .sight="红楼";
	
	G.vex[4] .description="历史悠久";
	
	G.vex[5] .sight="教工宿舍";
	
	G.vex[5] .description="老师活动中心";
	
	G.vex[6] .sight="15栋男生宿舍";
	
	G.vex[6] .description="电子男生普通宿舍";
	
	G.vex[7] .sight="14栋男生宿舍";
	
	G.vex[7] .description="电子男生高寝";
	
	G.vex[8] .sight="11栋女生宿舍";
	
	G.vex[8] .description="电子学院女生宿舍";
	
	G.vex[9] .sight="学生三食堂";
	
	G.vex[9] .description="最大食堂，经济实惠";
	
	G.Vex[10].description="四服楼";

	G.Vex[10].sight="学生主要生活用品购买，快递领取处"
	for(i=0;i<G.vexnum;++i) 
		
		for(j=0;j<G.vexnum;++j) 
			
			G.arcs[i] [j] .adj=Max;
	
	G.arcs[0] [1] .adj=G.arcs[1] [0] .adj=610;
	
	G.arcs[0] [2] .adj=G.arcs[2] [0] .adj=600;
	
	G.arcs[0] [3] .adj=G.arcs[3] [0] .adj=720;
	
	G.arcs[1] [4] .adj=G.arcs[4] [1] .adj=200;
	
	G.arcs[2] [4] .adj=G.arcs[4] [2] .adj=300;
	
	G.arcs[3] [5] .adj=G.arcs[5] [3] .adj=420;
	
	G.arcs[5] [7] .adj=G.arcs[7] [5] .adj=550;
	
	G.arcs[4] [6] .adj=G.arcs[6] [4] .adj=310;
	
	G.arcs[4] [7] .adj=G.arcs[7] [4] .adj=300;
	
	G.arcs[6] [8] .adj=G.arcs[8] [6] .adj=460;
	
	G.arcs[7] [8] .adj=G.arcs[8] [7] .adj=450;
	
	G.arcs[8] [9] .adj=G.arcs[9] [8] .adj=610;
	
} 

void narrate() 
	
{


	int i,k=0;

	printf("\n\t\t*****************欢迎使用校园导游程序***************\n") ;
	
	printf("\n\t\t********************九江学院*******************\n") ;
	
	printf("\t__________________________________________________________________\n") ;
	printf("\t\t景点名称\t\t|\t景点描述\n") ;
	
	printf("\t________________________________|_________________________________\n") ;
	
	for(i=0;i<NUM;i++) 
		
	{


		printf("\t (%2d) %-10s\t\t\t|\t%-25s\n",i,G.vex[i] .sight,G.vex[i] .description) ;
		
		k=k+1;
		
	} 
	
	printf("\t________________________________|_________________________________\n") ;
	
} 

void ShortestPath(int num) 
	
{


	int v,w,i,t;

	int final[NUM] ;
	
	int min;
	
	for(v=0;v<NUM;v++) 
		
	{


		final[v] =0;
		
		D[v] =G.arcs[num] [v] .adj;
		
		for(w=0;w<NUM;w++) 
			
			P[v] [w] =0;
		
		if(D[v] <30000) 
			
		{


			P[v] [num] =1;
			
			P[v] [v] =1;
			
		} 
		
	} 
	
	D[num] =0;
	
	final[num] =1;   
		
		for(i=0;i<NUM;++i)    
			
		{


			min=Max;   

				for(w=0;w<NUM;++w) 
					
					if(!final[w] )  
						
						if(D[w] <min)  
							
						{


							v=w;

							min=D[w] ;
							
						} 
			
			final[v] =1; 
				
				for(w=0;w<NUM;++w) 
					
					if(!final[w] &&((min+G.arcs[v] [w] .adj) <D[w] ) ) 
						
					{


						D[w] =min+G.arcs[v] [w] .adj;
						for(t=0;t<NUM;t++) 
							
							P[w] [t] =P[v] [t] ;
						
						P[w] [w] =1;
						
					} 
			
		} 
	
} 

void output(int sight1,int sight2)  
	
{


	int a,b,c,d,q=0;

	a=sight2; 

		if(a!=sight1)  /* 如果景点二不和景点一输入重合，则进行 */ 
			
		{


			printf("\n\t从%s到%s的最短路径是",G.vex[sight1] .sight,G.vex[sight2] .sight) ;/* 输出提示信息 */ 
				
				printf("\t(最短距离为%dm.) \n\n\t",D[a] ) ;
			
			printf("\t%s",G.vex[sight1] .sight) ; 
				
				d=sight1;   /* 将景点一的编号赋值给d */  
				
				for(c=0;c<NUM;++c) 
					
				{


gate:;     

		 P[a] [sight1] =0;
	 
	 for(b=0;b<NUM;b++) 
		 
	 {


		 if(G.arcs[d] [b] .adj<30000&&P[a] [b] )  /* 如果景点一和它的一个临界点之间存在路径且最短路径 */ 
			 
		 {


			 printf("-->%s",G.vex[b] .sight) ; /* 输出此节点的名称 */ 
				 
				 q=q+1;  /* 计数变量加一，满8控制输出时的换行 */
				 
				 P[a] [b] =0;
			 
			 d=b;     /* 将b作为出发点进行下一次循环输出，如此反复 */
				 
				 if(q%9==0)  printf("\n") ;
			 
			 goto gate;
			 
		 } 
		 
	 } 
	 
				} 
			
		} 
	
} 

void HaMiTonian(int m)  

{


	if(m>9)   return; 
		
	L: NextValue(m) ; 
		
		if(x[m] ==0)  
			
			return; 
				
				if(m==8&&G.arcs[0] [x[10] -1] .adj!=30000)  
					
					display() ; 
						
				else 
				
				HaMiTonian(m+1) ; 
				
				goto  L; 
				
} 

void NextValue(int k)  

{
	 

		int j; 

		l:x[k] =(x[k] +1) %10; 
		
		if(x[k] ==0)  
			
			return; 
				
				if(G.arcs[x[k-1] -1] [x[k] -1] .adj!=30000)  
					
				{
					 

						for(j=0;j<k;j++)  
							
							if(x[j] ==x[k] )  
								
								goto l; 
									
									return;     
									
				}  
	
				else 
					
					goto l;     
					
}  

void display()  
	
{
	 int i=0;

	printf("\n\n\t");
	
	for(i=0;i<10;i++)  
		
		printf("%s->",G.vex[x[i] -1] .sight); 
			
			printf("出口") ;
	
	printf("\n");
	
}  


