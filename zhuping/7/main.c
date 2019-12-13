#include"map.h"
int main(int argc,int **argv)
{   char k;init();
	printf("九江学院校园导游系统\n");printf("\n");
    while(1){   
		printf("1.景点信息查询请按“1”键;\n");
		printf("2.景点最短路径查询请按“2”键;\n");
		printf("3.校内景点地图查询请按“3”键;\n");	    
		printf("4.退出系统请按“4”键;\n");
		printf("请选择: \n");scanf("%c",&k);
		switch(k){
		case '1':printf("景点介绍查询（请输入1-22）。\n");
			introduce();break;
		case '2':printf("景点最短路径查询");
			shortdistance();break;
		case '3':printf("景点地图。\n");
			map();break;
		case '4':printf("谢谢使用!\n");exit(0);
		}}
    return 0;}
