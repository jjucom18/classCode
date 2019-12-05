#include<stdio.h>
#include<string.h>
#define Num 11
#define Maxedge 5000 
typedef struct{
	 char name[10] ;
	  int number;
	   char introduce[100];
}vertex; 
 vertex ver[Num];
  int edge[Num][Num][2];
   int shortest[Num][Num][2];
    int path[Num][Num][2];
    void show1()
{
	     printf("\n\n\n\n\n\n\n\n\n\n\n");
	      }
 
void show2() 
{
	 int i=1;
	 printf("\t\t\t九江学院各地点的编号:\n");
	 for(i=1;i<=Num;i++)
	 {
	   	 printf("%d、%s\t",i,ver[i].name);
	       }
	     printf("\n\n");
	      
}
 
void init(){
	 int i,j;
	 ver[1].number =1;
	 strcpy(ver[1].name,"九江学院西南门");
	 strcpy(ver[1].introduce,"从这里进入");
	 ver[2].number =2;
	 strcpy(ver[2].name,"主图书馆");
	 strcpy(ver[2].introduce,"可借阅图书，自习室，电子阅览室等");
	 ver[3].number =3;
	 strcpy(ver[6].name,"山上食堂");
	 strcpy(ver[6].introduce,"有一食堂二食堂两个食堂,学生、教师用餐处，有各种美食");
	 ver[4].number =4;
	 strcpy(ver[4].name,"竞知楼");
	 strcpy(ver[4].introduce,"九院最大的教学楼之一");
	 ver[5].number =5;
	 strcpy(ver[5].name,"山上宿舍楼");
	 strcpy(ver[5].introduce,"大多数为女生宿舍");
	 ver[6].number =6;
	 strcpy(ver[3].name,"电子信息楼");
	 strcpy(ver[3].introduce,"可以做各种电子类课程实验");
	 ver[7].number =7;
	 strcpy(ver[7].name,"南区操场");
	 strcpy(ver[7].introduce,"有塑胶跑道，足球场，观众席等");
	 ver[8].number =8;
	 strcpy(ver[8].name,"逸夫楼");
	 strcpy(ver[8].introduce,"理工科类图书馆");
	 ver[9].number =9;
	 strcpy(ver[9].name,"山下食堂");
	 strcpy(ver[9].introduce,"三食堂是学校最大的食堂，四食堂又称四服楼，二三楼是学生活动区域，五食堂是风味食堂");
	 ver[10].number =10;
	 strcpy(ver[10].name,"山下宿舍");
	 strcpy(ver[10].introduce,"山下学生休息的地方");
	 ver[11].number =11;
	 strcpy(ver[11].name,"四大教学楼：立信楼，文友楼，义丰楼，香远楼");
	 strcpy(ver[11].introduce,"教学楼，归学校二级学院专属");
	 for(i=1;i<=Num;i++)
	 { for(j=1;j<=Num;j++){ 
		 edge[i][j][0]=Maxedge;
		 edge[i][j][1]=Maxedge;
	 }
       }	 
         for(i=1;i<=Num;i++)
	 {
		 edge[i][i][0]=0;
		 edge[i][i][1]=0;
	 }
	 edge[1][2][0]=edge[2][1][0]=100;
	 edge[1][3][0]=edge[3][1][0]=80;
	 edge[1][4][0]=edge[4][1][0]=100;
	 edge[2][3][0]=edge[3][2][0]=50;
	 edge[2][5][0]=edge[5][2][0]=300;
	 edge[3][4][0]=edge[4][3][0]=50;
	 edge[3][6][0]=edge[6][3][0]=300;
	 edge[4][6][0]=edge[6][4][0]=220;
	 edge[4][7][0]=edge[7][4][0]=400;
	 edge[5][6][0]=edge[6][5][0]=50;
	 edge[5][7][0]=edge[7][5][0]=250;
	 edge[5][8][0]=edge[8][5][0]=250;
	 edge[5][9][0]=edge[9][5][0]=250;
	 edge[6][7][0]=edge[7][6][0]=220;
	 edge[7][8][0]=edge[8][7][0]=400;
	 edge[7][9][0]=edge[9][7][0]=400;
	 edge[9][8][0]=edge[8][9][0]=200;
    	 edge[11][8][0]=edge[8][11][0]=400;
	 edge[9][10][0]=edge[10][9][0]=50;
	 edge[1][2][1]=edge[2][1][1]=85;
	 edge[1][3][1]=edge[3][1][1]=100;
	 edge[1][4][1]=edge[4][1][1]=90;
	 edge[2][3][1]=edge[3][2][1]=30;
	 edge[2][5][1]=edge[5][2][1]=200;
	 edge[3][4][1]=edge[4][3][1]=150;
	 edge[3][6][1]=edge[6][3][1]=350;
	 edge[4][6][1]=edge[6][4][1]=150;
	 edge[4][7][1]=edge[7][4][1]=600;
	 edge[5][6][1]=edge[6][5][1]=60;
	 edge[5][7][1]=edge[7][5][1]=200;
	 edge[5][8][1]=edge[8][5][1]=100;
	 edge[5][9][1]=edge[9][5][1]=300;
	 edge[6][7][1]=edge[7][6][1]=200;
	 edge[7][8][1]=edge[8][7][1]=500;
	 edge[7][9][1]=edge[9][7][1]=300;
	 edge[9][8][1]=edge[8][9][1]=300;
	 edge[11][8][1]=edge[8][11][1]=200;
	 edge[9][10][1]=edge[10][9][1]=100;         
}	 
char show3()
{
	char i;
	printf("信息查询请输入a.\n");
	printf("最短路径查询请输入b.\n");
	printf("最快时间查询请输入c.\n");
	printf("加入中间点输入d.\n");
	printf("退出系统输入e.\n");
	printf("你的选择:");
	scanf("%s",&i);
	return i;
}
                          
                                       
void information()
{
	int i;
	while(1)
	{ 
		system("cls"); 
		show1(); 
		show2(); 
		printf("请输入查询地点的编号:"); 
		scanf("%d",&i); 
		if(i<=Num&&i>=1)
		{ 
			printf("名称:%s\n简介:%s\n",ver[i].name,ver[i].introduce); 
			return; 
		}
		else
		{
			printf("输入有误~");
		}
	}                                                               
}	

void floyd_path(int temp)
{
	int i=1,j=1,k=1,l=1;
	for(i=1;i<=Num;i++)
	{
		for(j=1;j<=Num;j++)
		{
			shortest[i][j][temp]=edge[i][j][temp]; 
			path[i][j][temp]=0;
		} 
	}
	for(k=1;k<=Num;k++)
    	{ for(i=1;i<=Num;i++) 
		{for(j=1;j<=Num;j++)
			{if(shortest[i][j][temp]>(shortest[i][k][temp]+shortest[k][j][temp]))
				{  
					shortest[i][j][temp]=(shortest[i][k][temp]+shortest[k][j][temp]);  
					path[i][j][temp]=path[j][i][temp]=k;
				}  
			} 
		}	
	}  	
}

void show4(int i,int j, int temp) 
{
	int k=0,a=i,b=j;
	int S;
	double L;
	int h,m,s;
	printf("\n请输入起始时间：");
	scanf("%d:%d:%d",&h,&m,&s);
	if(shortest[i][j][temp]!=Maxedge)
	{
		if(temp == 0)
			printf("从%s到%s的最短路径为:\n",ver[i].name,ver[j].name);
		if(temp == 1)
			printf("从%s到%s的最快时间的路径为:\n",ver[i].name,ver[j].name);
		printf("%s",ver[i].name);
		while(path[i][j][temp]!=0)
		{
			k=path[i][j][temp];
			while(path[i][k][temp]!=0)
			{
				k=path[i][k][temp];
			}
			printf("----%s",ver[k].name);
			i=k;
		}
		printf("----%s;\n",ver[j].name );
		if(temp == 0)
		{
			printf("最短距离为:%d米。\n",shortest[a][b][temp]);
			S = shortest[a][b][temp] / 1;
			Time(h, m, s, S);
		}
		if(temp == 1)
		{
			printf("最快时间为:%d秒。\n",shortest[a][b][temp]);
			Time(h, m, s, shortest[a][b][temp]); 
		}
	}
	else
		printf("从%s不能到达%s。",ver[i].name ,ver[j].name );
}                                                                                                                                                                                                                                        
void shortestpath(int temp)
{ 
	int i=0,j=0;
	while(1) 
	{ 
		system("cls");  
		show1();  
		show2();  
		printf("请输入要查询的两点的编号:(以空格间隔)");  
		scanf("%d%d",&i,&j);  
		if(i<=Num&&i>0&&j<=Num&&j>0)  
		{  
			floyd_path(temp);   
			show4(i,j,temp); 
			return;  
		}  
	}
}

void Time(int h, int m, int s, int S)
{
	s += S; 
	if(s >= 60）{
		       	m += (s / 60);	
			s %= 60;
			if(m >= 60)
			{
			h += (h / 60);
			m %= 60;
			if(h >= 24)
			{
			h %= 24;
			}
			}

			}

			printf("到达时间为：%02d:%02d:%02d\n\n",h,m,s);
			}

void Intermediate_point(){
system("cls");
show1(); 
show2();
int i,j,k,temp;
k = -1;
int point[11];
printf("请输入要查询的几点的编号:(以空格间隔，-1结束)");
for(i = 0; i <= 11; i++)
{
	scanf("%d",&point[i]);
	k++;
	if(point[i] == -1) break;

}  

printf("1.最短路径\n2.最快时间\n3.退出\n");

while(1){
	printf("\n请输入查询代号：");
	scanf("%d",&temp);
	if(temp == 3) break;{
	for(i = 0 ; point[i] != -1; i++){  
		if(point[i]<=Num&&point[i]>0&&point[i+1]<=Num&&point[i+1]>0)  
		{  
			floyd_path(temp-1);  
			show5(point[i],point[i+1],temp-1,point,k);  
		} 
}
} 

void show5(int i,int j, int temp,int point[],int k1) 
{
	int k=0,a=i,b=j,t;
	int S;
	double L;
	if(shortest[i][j][temp]!=Maxedge)
	{
		if(i == point[0])
		{
			printf("从");
			for(t = 0; t < k1; t++){
				printf("%s--",ver[point[t]].name);
			}
			if(temp == 0) 
				printf("的最短路径为:\n");
			if(temp == 1) 
				printf("的最快时间路径为:\n");
			printf("%s",ver[point[0]].name);
		}
		while(path[i][j][temp]!=0)
		{
			k=path[i][j][temp];
			while(path[i][k][temp]!=0)
			{
				k=path[i][k][temp];
			}
			printf("----%s",ver[k].name);
			i=k;
		}
		printf("----%s",ver[j].name );

	}
	else
		printf("从%s不能到达%s。",ver[i].name ,ver[j].name );
}

int main()
{
	char i;
	int h,m,s;
	printf("\n\n\n\n\n\n\t\t\t\t\t欢迎使用九江学院导航系统!\n\n\n");
	init(); 
	system("pause");
	fflush(stdin);
	while (1)
	{
		system("cls");
		show1();
		show2();
		i=show3();
		switch(i)
		{
			case 'a':information();break;   
			case 'b':shortestpath(0);break; 
			case 'c':shortestpath(1);break; 
			case 'd':Intermediate_point();break;   
			case 'e':system("cls");
		        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tGOODBYE!\n\n\n\n\n\n\n\n\n\n\n");
				 system("pause");exit(0);
			default :printf("输入错误～\n");break;  
		} 
		system("pause"); 
	}
}                                                                                                                                                                                                                                                                                                                                                                                                                                 
