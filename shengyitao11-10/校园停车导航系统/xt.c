#include "xt.h"
void Init_Graph(Graph *G)
{
    int i,j;
    G->vertexnum=15;//点的数目为15
    G->edgenum=20;//边的数目为20
    ///////最初初始化一下图 
    for(i=0;i<G->vertexnum;i++)
    {
        for(j=0;j<G->vertexnum;j++)
        {
            if(i==j)
            {
                G->edge[i][j]=0;//初始化如果自己和自己就为0 
            }
            else
            {
                G->edge[i][j]=INF;//否则初始化为无线大 
            }
        }
    }
    //////////////具体输入图
    G->place[0].index=1;
    strcpy(G->place[0].name,"南门");//程序名存入了G
    strcpy(G->place[0].intro,"九江学院最繁华的大门但是门口不能停车\n");
    G->place[1].index=2;
    strcpy(G->place[1].name,"一食堂小门前");
    strcpy(G->place[1].intro,"可以停适量的车。\n");
    G->place[2].index=3;
    strcpy(G->place[2].name,"南区操场入口边");
    strcpy(G->place[2].intro,"地方较大方便停车\n");
    G->place[3].index=4;
    strcpy(G->place[3].name,"二食堂门口");
    strcpy(G->place[3].intro,"位置狭长，不适应停很多车\n");
    G->place[4].index=5;
    strcpy(G->place[4].name,"马路");
    strcpy(G->place[4].intro,"在划白线的地方可以停。\n");
    G->place[5].index=6;
    strcpy(G->place[5].name,"逸夫图书馆门口");
    strcpy(G->place[5].intro,"位置较大，多为图书馆老师停车所在地\n");
    G->place[6].index=7;
    strcpy(G->place[6].name,"西门");
    strcpy(G->place[6].intro,"空位较大可以停车\n");
    G->place[7].index=8;
    strcpy(G->place[7].name,"厚德楼");
    strcpy(G->place[7].intro,"旁边可以停适量的车\n");
    G->place[8].index=9;
    strcpy(G->place[8].name,"四食堂前方");
    strcpy(G->place[8].intro,"可以停几辆车，空位较少\n");
    G->place[9].index=10;
    strcpy(G->place[9].name,"外国宿舍门前");
    strcpy(G->place[9].intro,"空位有些，可以少量停车\n");
    G->place[10].index=11;
    strcpy(G->place[10].name,"五食堂门口和旁边");
    strcpy(G->place[10].intro,"可以适当的停车\n");
    G->place[11].index=12;
    strcpy(G->place[11].name,"义丰楼旁边");
    strcpy(G->place[11].intro,"老师停车所在地\n");
    G->place[12].index=13;
    strcpy(G->place[12].name,"文友楼旁边");
    strcpy(G->place[12].intro,"老师停车所在地\n");
    G->place[13].index=14;
    strcpy(G->place[13].name,"立信楼旁边");
    strcpy(G->place[13].intro,"老师停车所在地\n");
    G->place[14].index=15;
    strcpy(G->place[14].name,"北区田径馆门口");
    strcpy(G->place[14].intro,"外来人员锻炼身体可在这停车\n");
    ///////////////////////////
    //具体距离  建立图的边的值
   G->edge[0][1]=1200;
   G->edge[1][0]=1200;
   G->edge[0][2]=1100;
   G->edge[2][0]=1100;
   G->edge[1][3]=1000;
   G->edge[3][1]=1000;
   G->edge[2][4]=300;
   G->edge[4][2]=300;
   G->edge[3][4]=350;
   G->edge[4][3]=350;
   G->edge[3][5]=900;
   G->edge[5][3]=900;
   G->edge[5][6]=300;
   G->edge[6][5]=300;
   G->edge[6][4]=1300;
   G->edge[4][6]=1300;
   G->edge[5][7]=1400;
   G->edge[7][5]=1400;
   G->edge[7][8]=1000;
   G->edge[8][7]=1000;
   G->edge[8][6]=750;
   G->edge[6][8]=750;
   G->edge[7][11]=900;
   G->edge[11][7]=900;
   G->edge[11][9]=600;
   G->edge[9][11]=600;
   G->edge[9][8]=950;
   G->edge[8][9]=950;
   G->edge[11][10]=150;
   G->edge[10][11]=150;
   G->edge[10][12]=800;
   G->edge[12][10]=800;
   G->edge[12][13]=150;
   G->edge[13][12]=150;
   G->edge[14][15]=350;
   G->edge[15][14]=350;    
}
void show_menu(Graph *G)
{
    int choice;
    int start;
    int end;
    int i;
    int returnmenu;
    int place;
    float minroad;
    int flag=0;
    do
    {
    system("cls");
    
    printf("*********欢迎来到九江学院校园地图停车导航系统********\n");
    printf("********      以下为简易地图         *********\n");

    printf("        北            \n");
    printf("         |            \n");
    printf("   西---------东\n");
    printf("         |      \n");
    printf("        南    \n"); 
    printf("                        15.北区田径馆门口                   \n");
    printf(" 12. 义丰楼旁边    13.   文友楼旁边   14.   立信楼旁边               \n");
    printf("          9.四食堂前方                       \n");
    printf("          11.五食堂门口和旁边                \n");
    printf("          10.外国宿舍门前             \n");
    printf("          7.西门                           \n");
    printf("          6.逸夫图书馆门口           \n"); 
    printf("          8.厚德楼                     \n");
    printf("          5.马路                       \n");
    printf("          4. 二食堂门口              \n");
    printf("          2.一食堂小门前                    \n");
    printf("          3.南区操场入口边            \n");
    printf("                           1.南门                      \n");
   
    printf("请输入您所选择的功能序号：\n"); 
    printf("1.查询最短停车路径\n");
    printf("2.查询停车点信息\n");
    printf("3.退出\n");
    scanf("%d",&choice);
    if(choice==1)
    {
    
        printf("请输入起点以及终点序号：\n");
        scanf("%d%d",&start,&end); 
        if(start<0||start>15||end<0||end>15)
        {
            printf("输入有误!\n");
            exit(-1);
        }
        
        shortestdistance(G);
        minroad=G->edge[start-1][end-1];
        display(G,start,end);
        printf("最小路径为：%.2f M\n",minroad);
    }
    else if(choice==2)
    {
    
        printf("请输入您想查询位置的序号\n");
        scanf("%d",&place);
        for(i=0;i<G->vertexnum;i++)
        {
            if(place==i+1)
            {
                printf("该地点为:\n");
                puts(G->place[i].name);
                printf("简介为：\n");
                puts(G->place[i].intro);
            }

        }
        
        
        
        
    }
    else if(choice==3)
    {
        exit(-1);
    }
    else
    {
        printf("输入错误！\n");
    }
    printf("请输入是否返回主菜单(1是，2不是)：\n");
    scanf("%d",&returnmenu);
    if(returnmenu==1)
    {
        flag=0;
    }
    else if(returnmenu==2)
    {
        flag=1;
    }
}
while(flag==0);
} 
void shortestdistance(Graph *G)
{
    
    int m,n,w;
    //m为中间点
    // n为起点
    //w为终点
    for(m=0;m<G->vertexnum;m++)
    {
        for(n=0;n<G->vertexnum;n++)
        {
            for(w=0;w<G->vertexnum;w++)
            {
                if(G->edge[n][w]>(G->edge[n][m]+G->edge[m][w]))
                {
                    G->edge[n][w]=G->edge[n][m]+G->edge[m][w];
                    path[n][w]=m;//n->w要经过 m
         
                    path[w][n]=m;//w->n要经过 m 
                 } 
            }
        }
     } 
    
     
    
    
}
void display(Graph *G,int start,int end)
{
    int i=start-1;
    int j=end-1;
    printf("您要查询的两地点间最短停车路径是: ");
    if(G->edge[i][j]!=INF)
    {
        if(i<j)
        {
            printf("%s",G->place[end-1].name);
            while(path[i][j]!=0)
            {/*把i到j的路径上所有经过的景点按逆序打印出来*/
                printf("<--");
                printf("%s",G->place[path[i][j]].name);
                if(i<j)
                    j=path[i][j];
                else
                    i=path[j][i];
            }
            printf("<--");
            printf("%s",G->place[start-1].name);
            printf(" ");
            
        }
        else
        {
            printf("%s",G->place[start-1].name);
            while(path[i][j]!=0)
            {/*?把i到j的路径上所有经过的景点按顺序打印出来*/
                printf("-->");
                printf("%s",G->place[path[i][j]].name);
                if(i<j)
                    j=path[i][j];
                else
                    i=path[j][i];
            }
            printf("-->");
            printf("%s",G->place[end-1].name);
            printf(" ");
        
        }
    }
    else
        printf("输入错误！不存在此路！\n");
    printf(" ");

 } 

int init(LinkQueue *wait,LinkQueue *park,LinkStack *giveway)//init为初始化
{
    QueueNode newnode1 = (QueueNode)malloc(sizeof(struct QueueNode));//QueueNode的初始化分配内存
    if(NULL == newnode1)
    {
        return F;
    }
    newnode1->next = NULL;
    wait->front = newnode1;
    wait->rear = newnode1;

    QueueNode newnode2 = (QueueNode)malloc(sizeof(struct QueueNode));
    if(NULL == newnode2)
    {
        return F;
    }
    newnode2->next = NULL;
    park->front = newnode2;
    park->rear = newnode2;

    giveway->top = NULL;
    giveway->count = 0;
}

void menu(LinkQueue *wait,LinkQueue *park,LinkStack *giveway,int num,int t)
{
    printf("---------欢迎来到九江学院校园停车场 !----------\n");
    printf("------------ 请选择如下功能  ------------\n");
    printf("---------        1 : 停车.        ----------\n");
    printf("--------         2 : 离开.         ----------\n");
    printf("--------         3 : 查询.          ---------\n");
    printf("---------       4 : 退出系统     ---------\n");
    int option;
    scanf("%d",&option);
    switch(option)
    {
        case 1:{
            park1(wait,park);
            printf("停车完成！\n");
            menu(wait,park,giveway,num,t);
            break;
        }
        case 2:{
            leave2(wait,park,giveway,num,t);
            menu(wait,park,giveway,num,t);
            break;
        }
        case 3:{
            view3(*wait,*park);
            menu(wait,park,giveway,num,t);
            break;
        }
        case 4:{
           //printf("--------   欢迎再次使用，谢谢！  --------\n");
		   break;
        }
        default:{
            printf("--------     请输入正确的指令！    --------\n");
            menu(wait,park,giveway,num,t);
            break;
        }//无任何case匹配时，才会执行default;如果有case语句匹配时，运行结果是和default放在switch的最后是一样的。
    }

}

int linklength(LinkQueue q)
{
    int i = 0;
    while(q.front != q.rear)
    {
        i++;
        q.front = q.front->next;
    }
    return i;
}

int enqueue(LinkQueue *pack,int num,int t)
{
    QueueNode newnode = (QueueNode)malloc(sizeof(struct QueueNode));
    if(NULL == newnode)
    {
        return F;
    }
    newnode->infom.number = num;
    newnode->infom.time = t;
    newnode->next = NULL;
    pack->rear->next = newnode;
    pack->rear = newnode;//把rear的next给rear
    return T;
}

int dequeue(LinkQueue *q,int *num,int *t)
{
    if(q->front == q->rear)
    {
        printf("没有这种车在里面!\n");//如果队头等于队尾则该队为空
        return F;
    }
    *num = q->front->next->infom.number;
    *t = q->front->next->infom.time;
    QueueNode temp = q->front->next;
    q->front->next = temp->next;
    if(temp->next == NULL)
    {
        q->rear = q->front;
    }
    free(temp);
    return T;
}

void park1(LinkQueue *wait,LinkQueue *park)
{
    printf("请输入车号和停车时间\n");
    int num,t;
    scanf("%d%d",&num,&t);
    if(linklength(*park) >= MAX)
    {
        printf("停车场已满，进入等待区！\n");
        enqueue(wait,num,t);
    }
    else
    {
        enqueue(park,num,t);
    }
}

int push(LinkStack *s,int num,int t)
{
    StackNode newnode = (StackNode)malloc(sizeof(struct stack));
    if(NULL == newnode)
    {
        return F;
    }
    newnode->data.number = num;
    newnode->data.time = t;
    newnode->next = s->top;
    s->top = newnode;
    s->count++;
    return T;
}

int pop(LinkStack *s,int *num,int *t)//出栈
{
    if(0 == s->count)
    {
        printf("the stack is empty !\n");//栈空不能入栈
        return F;
    }
    *num = s->top->data.number;
    *t = s->top->data.time;
    StackNode temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->count--;//更新栈顶指针
    return T;
}//栈顶元素存入*num *t,返回

void leave2(LinkQueue *wait,LinkQueue *park,LinkStack *giveway,int num,int t)
{
    printf("请输入要离开车的车号\n");
    int leavenumber;
    scanf("%d",&leavenumber);
    int i = 0;
    QueueNode head = park->front;
    while(head != park->rear)
    {
        if(head->next->infom.number != leavenumber)
        {
            head = head->next;
            i++;
        }
        else
            break;
    }
    int j = 0;
    if(i <= MAX-1)
    {
        while(j != i)
        {
            dequeue(park,&num,&t);
            push(giveway,num,t);
            j++;
        }
        dequeue(park,&num,&t);
    }
    else
    {
        printf("查无此车！\n");
    }
    while(giveway->top != NULL)
    {
        pop(giveway,&num,&t);
        enqueue(park,num,t);
    }
    if(linklength(*wait) != 0)
    {
        dequeue(wait,&num,&t);
        enqueue(park,num,t);
    }
}

void view3(LinkQueue wait,LinkQueue park)
{
    printf("--------   目前停车场状况    -------- \n");
    printf("停车场共%d个车位，当前停车场共有%d量车，等待区共有%d量车\n",
        MAX,linklength(park),linklength(wait));
    printf("         --------------------- ----------------        \n");
    printf("车    号：");
    QueueNode head1 = park.front;
    QueueNode head2 = park.front;
    while(head1 != park.rear)
    {
        printf("%d  ",head1->next->infom.number);
        head1 = head1->next;
    }
    printf("\n");
    printf("停车时间：");
    while(head2 != park.rear)
    {
        printf("%d ",head2->next->infom.time);
        head2 = head2->next;
    }
    printf("\n");
}




