#ifndef jju_h
#define jju_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MOVETO(x,y) 	printf("\033[%d;%dH",(x),(y));
//校园导航系统
#define Max 100
#define INF 10000
typedef struct place{
    char name[20];			//名字 
    int index;				//下标 
    char intro[30];			//简介 
}PLA;						//定义位置
typedef struct {
    PLA place[Max];
    float edge[Max][Max];
    int vertexnum;			//点的数目 
    int edgenum;			//边数目 
}Graph;						//定义一个图 
void Init_Graph(Graph *G);	//初始化一个图
void show_menu(Graph * G);	//输出菜单 
void shortestdistance(Graph *G);			//求最短距离 
void display(Graph *G,int start,int end);	//展示路径 


/***********************************************************/

typedef struct _User{
	long int number;			//用户账号
	char name[20]; 				//用户名
	char password[30];			//密码

}User;


typedef struct _node
{
	User  *data;
	struct _node *next;

}NodeUser;

typedef struct _linkedList
{
	NodeUser *head;
	NodeUser *tail;
	NodeUser *current;

}List_User;

typedef struct  _TreeNode{
	User *data;
	struct _TreeNode *left, *right;
}TreeNode_User;

typedef struct _Tree{
	TreeNode_User *root;
}Tree_User;


/********************************链表******************************/

List_User *initList_User();
void addTail_User(List_User *list,User *data);
void Free_Userlist(NodeUser *list);
void UserToFile_list(List_User *list);
void UserFromFile_list(List_User *list);

/********************************树*******************************/

void CreateTree_User(Tree_User *tree, User *data);
void displayTree_User(TreeNode_User *tree);
void InOrder_User(TreeNode_User *tree);
void FreeTree_User(TreeNode_User *tree);
void UserFromFile_Tree(Tree_User *tree);

User *Input_User_Data();
TreeNode_User *Tree_Search_User(TreeNode_User *tree,long int number);
long int SignIn_User();
void UserToFile(User *user);

/*****************************************************************/
void SignIn_User_Menu();
void User_Menu(User *user);
void Manage_Menu();
void Main_Menu();


#endif
