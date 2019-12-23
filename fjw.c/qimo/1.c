#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE-1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define MAXSIZE 100







typedef int Status;
typedef int Boolean;
typedef struct{
	int x,y,dir;
}point;//点坐标xy和下一步方向dir 1右2下3左4上







typedef struct node{
	point point;
	struct node* next;
}Node;
typedef Node Elemtyoe;
typedef struct{
	Node * top;
	Node * bottom;
}Linkstack,*pLinkstack;

int NosoutionReason = 0;
int mp[MAXSIZE][MAXSIZE],n,m;
int mpcopy[MAXSIZE][MAXSIZE];
int visit[MAXSIZE][MAXSIZE];
point solution[MAXSIZE];
int dx[] = {0,1,0,-1};//dx为x方向

