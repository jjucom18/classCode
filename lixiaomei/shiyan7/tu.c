#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<math.h>
#define max 30

#define Init_Length 10000

void shortestdistance();
void print(){
	printf("欢迎来到九江学院\n");
	printf("*****\n");
	printf("1 南门\n");
	printf("2 教工食堂\n");
	printf("3 主图\n");
	printf("4 竞知楼\n");
	printf("5 一食堂\n");
	printf("6 中通快递\n");
	printf("7 11栋\n");
	printf("8 15栋\n");
	printf("9 莲池\n");
	printf("10 西门\n");
	printf("11 五食堂\n");
	printf("12 三食堂\n");
	printf("13 四服楼\n");
	printf("14 27栋\n");
	printf("15 香远楼\n");
	printf("16 厚德楼\n");
	printf("17 公共机房\n");
	printf("18 逸夫图书馆\n");
	printf("19 室内田径馆\n");
	printf("20 操场\n");
	printf("21 北门\n");
	printf("功能1.地点查询请输入i\n");
	printf("功能2.查询最短路径请输入s\n");
	printf("功能3.退出系统请输入e\n");
	printf("请输入你的选择:");
}

void introduce(){
	int a;
	printf("请输入地点编号:");
	scanf("%d",&a);
	getchar();
	printf("\n");
	while(a<1||a>21){
		printf("错误！请输入数字1到21:\n\n");
		scanf("%d",&a);
	}
	switch(a){
		case 1:
			printf("1 南门\n\n");break;
		case 2:
			printf("2 教工食堂\n\n");break;
		case 3:
			printf("3 主图\n\n");break;
		case 4:
			printf("4 竞知楼\n\n");break;
		case 5:
			printf("5 一食堂\n\n");break;
		case 6:
			printf("6 中通快递\n\n");break;
		case 7:
			printf("7 11栋女生宿舍\n\n");break;
		case 8:
			printf("8 15栋男生宿舍\n\n");break;
		case 9:
			printf("9 莲池背单词的好地方\n\n");break;
		case 10:
			printf("10 西门升国旗的地方\n\n");break;
		case 11:
			printf("11 五食堂\n\n");break;
		case 12:
			printf("12 三食堂\n\n");break;
		case 13:
			printf("13 四服楼\n\n");break;
		case 14:
			printf("14 27栋\n\n");break;
		case 15:
			printf("15 香远楼\n\n");break;
		case 16:
			printf("16 厚德楼\n\n");break;
		case 17:
			printf("17 公共机房\n\n");break;
		case 18:
			printf("18 逸夫图书馆\n\n");break;
		case 19:
			printf("19 室内田径馆\n\n");break;
		case 20:
			printf("20 操场\n\n");break;
		case 21:
			printf("21 北门\n\n");break;

	}
	printf("/n");
}
void main(){
	char k;
	print();
	scanf("%c",&k);
	while((k!='i')&&(k!='e')&&(k!='s')){
		getchar();
		printf("错误！请输入i或s或e\n");
		scanf("%c",&k);
	}
	switch(k){
		case 'i':printf("进入景点查询:\n");
				 introduce();
				 break;
		case 's':printf("进入最短路径查询:\n");
				 shortestdistance();
				 break;
		case 'e':exit(0);
	}
}
void shortestdistance(){
	int i,v,w,v0,j;
	int cost[1][21];
	int min;
	int top[22]={0};
	int cos[22][22];
	int path[22][22];
	int final[22]={0};
	int D[22];
	for(i=0;i<22;i++)
		for(j=0;j<22;j++)
	cost[i][j]=Init_Length;
	cost[1][3]=cost[3][1]=612;
	cost[3][5]=cost[5][3]=500;
	cost[1][7]=cost[7][1]=776;
	cost[3][7]=cost[7][3]=159;
	cost[2][7]=cost[7][2]=590;
	cost[2][6]=cost[6][2]=864;
	cost[4][6]=cost[6][4]=782;
	cost[4][13]=cost[13][4]=947;
	cost[6][12]=cost[12][6]=299;
	cost[12][8]=cost[8][12]=255;
	cost[8][9]=cost[9][8]=250;
	cost[6][9]=cost[9][6]=350;
	cost[10][9]=cost[9][10]=682;
	cost[6][10]=cost[10][6]=1100;
	cost[9][11]=cost[11][9]=185;
	cost[11][13]=cost[13][11]=16;
	cost[14][18]=cost[18][14]=478;
	cost[18][21]=cost[21][18]=877;
	cost[18][16]=cost[16][18]=555;
	printf("请输入你现在所在的位置:\n");
	scanf("%d",&v0);
	while(v0>21||v0<1){
		printf("错误!");
		scanf("%d",&v0);

	}
	for(i=1;i<22;i++)
		for(j=1;j<22;j++)
			path[i][j]=0;
	for(v=1;v<22;v++){
		D[v]=cost[v0][v];
		if(D[v]<Init_Length){
			path[v][(++(top[v]))]=v;
		}
	}
	D[v0]=0;final[v0]=1;
	for(i=2;i<14;++i){
		min=Init_Length;
		for(w=1;w<22;++w){
			if((final[w]==0)&&(D[w]<min)){
				v=w;min=D[w];
			}
		}
		final[v]=1;
		for(w=1;w<22;++w){
			if((final[w]==0)&&(min+cost[v][w]<D[w])){
				D[w]=min+cost[v][w];
				for(j=1;j<22;j++)
					path[w][j]=path[v][j];
				top[w]=top[v]+1;
				path[w][(top[w])]=w;
			}
		}
	}
	printf("请输入你要去的地方:\n");
	scanf("%d",&w);
	printf("\n");
	while(w>21||w<1){
		printf("错误\n");
		scanf("%d",&w);
	}
	printf("最短路径:\n");
	for(i=1;path[w][i]!=0;i++)
		printf("%d",path[w][i]);
	printf("\n");
	printf("最短路径:%d\n",D[w]);
}
