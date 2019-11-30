#include<cstdio>

#include<iostream>

#include<cstring>

#include<cstdlib>

#define INF 0x3f3f3f3f;

#define n 10

using namespace std;

const int max_v=50;

int path[max_v][max_v];

 

typedef struct

{

    char name[20];

    char code[20];

    char intro[100];

}DataType;

 

typedef struct

{

    int num;

    DataType data;

}View;

 

typedef struct

{

    View view[max_v];

    int pl[max_v][max_v];

    int vexnum,arcnum;

}AMGraph;

 

void DisplayTu(){

    printf("***------------------学校平面图--------------------***\n\n");

    printf("***                       北门(2)              ***\n");

    printf("***   艺术学院(10)--------|   |---------体育馆(3)  ***\n");

    printf("***        |                图书馆(1)      |       ***\n");

    printf("***        三食堂广场(9)        |            |       ***\n");

    printf("***         |             竟知楼(5)      |       ***\n");

    printf("***         |                 |            |       ***\n");

    printf("***   蝶湖(8)                 |            |       ***\n");

    printf("***     |                     |            |       ***\n");

    printf("***     |                     ---------教工食堂(4)   ***\n");

    printf("***     ---教工宿舍(7)---南门(6)-------------|       ***\n\n");

    printf("***------------------------------------------------***\n\n");

    system("pause");

    system("cls");

}

 

void init(AMGraph &AM){ 

    int i=1;

    AM.view[i].num=i;

    strcpy(AM.view[i].data.code,"zzti_1");

    strcpy(AM.view[i].data.name,"图书馆");

    strcpy(AM.view[i].data.intro,"图书馆馆迎门而立，俯瞰国道，是学校的标志性建筑.");

    i++;

    AM.view[i].num=i;

    strcpy(AM.view[i].data.code,"zzti_2");

    strcpy(AM.view[i].data.name,"北门");

    strcpy(AM.view[i].data.intro,"位于图书馆前,中央立着国旗,使其威严庄重.");

    i++;

    AM.view[i].num=i;

    strcpy(AM.view[i].data.code,"zzti_3");

    strcpy(AM.view[i].data.name,"体育馆");

    strcpy(AM.view[i].data.intro,"新奇的建筑风格，为中工增添了别样的色彩.");

    i++;

    AM.view[i].num=i;

    strcpy(AM.view[i].data.code,"zzti_4");

    strcpy(AM.view[i].data.name,"教工食堂");

    strcpy(AM.view[i].data.intro,"千树万树,织就花的云锦,再现了陶令笔下的意境,耐人寻味.");

    i++;

    AM.view[i].num=i;

    strcpy(AM.view[i].data.code,"zzti_5");

    strcpy(AM.view[i].data.name,"竟知楼");

    strcpy(AM.view[i].data.intro,"是同学们举办活动的地方.");

    i++;

    AM.view[i].num=i;

    strcpy(AM.view[i].data.code,"zzti_6");

    strcpy(AM.view[i].data.name,"南门");

    strcpy(AM.view[i].data.intro,"拥有一个小山丘,及众多果树.");

    i++;

    AM.view[i].num=i;

    strcpy(AM.view[i].data.code,"zzti_7");

    strcpy(AM.view[i].data.name,"教工宿舍");

    strcpy(AM.view[i].data.intro,"两个白色的海豚位于池中间,周围布满了荷花.");

    i++;

    AM.view[i].num=i;

    strcpy(AM.view[i].data.code,"zzti_8");

    strcpy(AM.view[i].data.name,"蝶湖");

    strcpy(AM.view[i].data.intro,"从图书馆前的桥下穿过,一些小岛坐落其中.");

    i++;

    AM.view[i].num=i;

    strcpy(AM.view[i].data.code,"zzti_9");

    strcpy(AM.view[i].data.name,"莲池");

    strcpy(AM.view[i].data.intro,"海拔较低,风景优美是休闲散步的好地方.");

    i++;

    AM.view[i].num=i;

    strcpy(AM.view[i].data.code,"zzti_10");

    strcpy(AM.view[i].data.name,"艺术学院");

    strcpy(AM.view[i].data.intro,"有湖水和很多树木,空气清新,风景优美.");

    for(int j=1;j<=i;j++)

        for(int k=1;k<=i;k++){

            if(k==j)

                AM.pl[j][k]=0;

            else

                AM.pl[j][k]=INF;

            path[j][k]=k;

        }

    AM.pl[1][2]=AM.pl[2][1]=50;

    AM.pl[1][3]=AM.pl[3][1]=300;

    AM.pl[2][3]=AM.pl[3][2]=200;

    AM.pl[2][10]=AM.pl[10][2]=460;

    AM.pl[1][5]=AM.pl[5][1]=200;

    AM.pl[1][10]=AM.pl[10][1]=400;

    AM.pl[3][5]=AM.pl[5][3]=800;

    AM.pl[3][4]=AM.pl[4][3]=900;

    AM.pl[4][5]=AM.pl[5][4]=400;

    AM.pl[5][10]=AM.pl[10][5]=500;

    AM.pl[5][9]=AM.pl[9][5]=400;

    AM.pl[5][6]=AM.pl[6][5]=700;

    AM.pl[8][10]=AM.pl[10][8]=150;

    AM.pl[8][9]=AM.pl[9][8]=100;

    AM.pl[6][8]=AM.pl[8][6]=260;

    AM.pl[6][7]=AM.pl[7][6]=50;

    AM.pl[6][4]=AM.pl[4][6]=1000;

    AM.pl[7][8]=AM.pl[8][7]=200;

    AM.pl[9][10]=AM.pl[10][9]=50;

}

 

void Display(AMGraph AM){

    printf("以下是全部景点的代号和编号:\n\n");

    printf("代号\t\t名称\n");

    for(int i=1;i<=n;i++)

        printf("%s\t\t%d\n",AM.view[i].data.code,AM.view[i].num);

    printf("\n");

}

 

void Edit(AMGraph &AM){

    printf("欢迎编辑景点信息！\n");

    Display(AM);

    printf("请输入要编辑的景点的代号:\n");

    char q[20];

    cin>>q;

    for(int i=1;i<=n;i++){

        if(strcmp(AM.view[i].data.code,q)==0){

            printf("请输入新的景点信息：\n");

            printf("[提示:按照 代号、名称、介绍顺序输入!]\n\n");

            cin>>AM.view[i].data.code;

            cin>>AM.view[i].data.name;

            cin>>AM.view[i].data.intro;

            printf("修改成功！\n\n");

        }

    }

    system("pause");

    system("cls");

}

 

void Query(AMGraph AM){

    printf("欢迎查询景点信息！\n");

    Display(AM);

    printf("请输入要查询的景点的代号：\n\n");

    char q[20];

    cin>>q;

    for(int i=1;i<=n;i++){

        if(strcmp(AM.view[i].data.code,q)==0){

            printf("该景点的具体信息如下:\n");

            printf("名称:%s\n",AM.view[i].data.name);

            printf("简介:%s\n\n",AM.view[i].data.intro);

        }

    }

    system("pause");

    system("cls");

}

 

void ShortestPath(AMGraph AM){

    printf("欢迎查询景点路径！\n");

    Display(AM);

    printf("请输入要查询的两景点的编号:\n");

    int a,b;

    scanf("%d%d",&a,&b);

    for(int k=1;k<=n;k++)

        for(int i=1;i<=n;i++)

            for(int j=1;j<=n;j++){

                if(AM.pl[i][k]+AM.pl[j][k]<AM.pl[i][j]){

                    AM.pl[i][j]=AM.pl[i][k]+AM.pl[j][k];

                    path[i][j]=path[i][k];

                }

            }

    int sum=0,t;

    printf("您查询的景点 %s 到 %s 之间的最短路径为:\n",AM.view[a].data.name,AM.view[b].data.name);

    while(a!=b){

        printf("%s->",AM.view[a].data.name);

        t=a;

        a=path[a][b];

        sum+=AM.pl[t][a];

    }

    printf("%s\n\n",AM.view[b].data.name);

    printf("两景点之间的路径长度为:%dm\n\n",sum);

    system("pause");

    system("cls");

}

 

void Menu(){

    printf("--------校园导游咨询--------\n\n");

        printf("       1.景点平面图展示.\n");

        printf("       2.基本信息修改.\n");

        printf("       3.景点信息查询.\n");

        printf("       4.景点路径查询.\n");

        printf("       5.退出.\n\n");

        printf("------------------------------\n\n");

}

 

int main()

{

    AMGraph AM;

    init(AM);

    while(1){

        Menu();

        printf("请选择功能:\n\n");

        int a;

        scanf("%d",&a);

        if(a==5){

            printf("---------------------\n");

            printf("谢谢使用！旅途愉快！\n");

            printf("---------------------\n");

            break;

        }

        else if(a!=1&&a!=2&&a!=3&&a!=4){

            printf("您的输入选择不符合要求，请重新输入！\n");

            continue;

        }

        switch(a){

            case 1:DisplayTu();break;

            case 2:Edit(AM);break;

            case 3:Query(AM);break;

            case 4:ShortestPath(AM);break;

        }

    }

    return 0;

}

 

/*

修改：

zzti_1

图书馆

图书馆馆迎门而立，俯瞰国道，是学校的标志性建筑之一.

*/

 

 

 

 

