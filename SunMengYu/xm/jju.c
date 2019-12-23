#include"jju.h"


int path[Max][Max]={0};
void Init_Graph(Graph *G)
{
    int i,j;
    G->vertexnum=17;
    G->edgenum=20;
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
    ////////////////////具体输入图
    G->place[0].index=1;
    strcpy(G->place[0].name,"南门");
    strcpy(G->place[0].intro,"比较古老的一个门，晚上的夜景很漂亮。\n");
    G->place[1].index=2;
 strcpy(G->place[1].name ,"竞知楼");
    strcpy(G->place[1].intro,"电子学院上课的地方。\n");
    G->place[2].index=3;
    strcpy(G->place[2].name,"一食堂");
    strcpy(G->place[2].intro,"离11栋最近的一个食堂。\n");
    G->place[3].index=4;
    strcpy(G->place[3].name,"三食堂");
    strcpy(G->place[3].intro,"唯一一个有三层楼的食堂。\n");
    G->place[4].index=5;
    strcpy(G->place[4].name,"厚德楼");
    strcpy(G->place[4].intro,"不太清楚这个神秘的楼。\n");
    G->place[5].index=6;
    strcpy(G->place[5].name,"香远楼");
    strcpy(G->place[5].intro,"外国语学院上课的地方。\n");
    G->place[6].index=7;
    strcpy(G->place[6].name,"义丰楼");
    strcpy(G->place[6].intro,"经管学院上课的地方。\n");
    G->place[7].index=8;
    strcpy(G->place[7].name,"文友楼");
    strcpy(G->place[7].intro,"理学院上课的地方。\n");
    G->place[8].index=9;
    strcpy(G->place[8].name,"实训楼");
    strcpy(G->place[8].intro,"金工实习和微机课\n");
    G->place[9].index=10;
    strcpy(G->place[9].name,"立信楼");
    strcpy(G->place[9].intro,"会计学院上课的地方。\n");
    G->place[10].index=11;
    strcpy(G->place[10].name,"逸夫楼");
    strcpy(G->place[10].intro,"工科书比较多。\n");
     G->place[11].index=12;
    strcpy(G->place[11].name,"西门");
    strcpy(G->place[11].intro,"升国旗的地方。\n");
    G->place[12].index=13;
    strcpy(G->place[12].name,"北门");
    strcpy(G->place[12].intro,"门口比较荒凉。\n");
    /////////////////////////////////////////
    //具体距离
   G->edge[0][1]=200;
   G->edge[1][0]=200;
   G->edge[0][2]=300;
   G->edge[2][0]=300;
   G->edge[1][3]=500;
   G->edge[3][1]=500;
   G->edge[2][4]=400;
   G->edge[4][2]=400;
   G->edge[3][4]=700;
   G->edge[4][3]=700;
   G->edge[3][5]=300;
   G->edge[5][3]=300;
   G->edge[5][6]=100;
   G->edge[6][5]=100;
   G->edge[6][4]=300;
   G->edge[4][6]=300;
   G->edge[5][7]=600;
   G->edge[7][5]=600;
   G->edge[7][8]=1000;
   G->edge[8][7]=1000;
   G->edge[8][6]=1500;
    G->edge[6][8]=1500;
   G->edge[7][11]=900;
   G->edge[11][7]=900;
   G->edge[11][9]=500;
   G->edge[9][11]=500;
   G->edge[9][8]=2500;
   G->edge[8][9]=2500;
   G->edge[11][10]=500;
   G->edge[10][11]=500;
   G->edge[10][12]=200;
   G->edge[12][10]=200;
   G->edge[12][13]=100;
   G->edge[13][12]=100;
   G->edge[13][16]=500;
   G->edge[16][13]=500;
   G->edge[15][16]=100;
   G->edge[16][15]=100;
   G->edge[14][15]=200;
   G->edge[15][14]=200;
}
void show_menu(Graph *G){
    system("clear");
    int choice;
    int start;
    int end;
    int i;
    char returnmenu;
    int place;
    float minroad;
     int flag=0;
    while(1){
        system("clear");
        MOVETO(8,55)
        printf("----------    九江学院校园导航系统        ----------\n");
        MOVETO(10,55)
        printf("----------       以下为简易地图           ----------\n");
        MOVETO(12,80)
        printf("13.北门\n");
        MOVETO(20,130)
        printf("11.逸夫楼\n");
        MOVETO(16,95)
        printf("10.立信楼\n");
        MOVETO(18,95)
        printf("8.文友楼\n");
        MOVETO(20,95)
        printf("7.义丰楼\n");
        MOVETO(22,95)
        printf("6.香远楼\n");
        MOVETO(24,95)
        printf("5.厚德楼\n");
        MOVETO(20,120)
        printf("9.实训楼\n");
        MOVETO(18,40)
        printf("12西门\n");
        MOVETO(35,105)
        printf("3.一食堂\n");
        MOVETO(20,75)
        printf("4.三食堂\n");
        MOVETO(30,50)
        printf("2.竞知楼\n");
        MOVETO(50,30)
        printf("1.南门\n");
        MOVETO(30,130)
        printf("        北            \n");
        MOVETO(31,130)
        printf("         |            \n");
        MOVETO(32,130)
        printf("   西---------东\n");
        MOVETO(33,130)
        printf("         |      \n");
        MOVETO(34,130)
        printf("        南    \n");
        MOVETO(8,0)
        printf("请输入您所选择的功能序号：\n");
        MOVETO(9,0)
        printf("1.查询路径\n");
        MOVETO(10,0)
        printf("2.查询地点信息\n");
        MOVETO(11,0)
        printf("3.返回上层\n");
        MOVETO(12,0)
        scanf("%d",&choice);
        if(choice==1){

            printf("请输入起点\n");
            scanf("%d",&start);
            printf("请输入终点\n");
             scanf("%d",&end);
            if(start<0||start>17||end<0||end>17){
                printf("输入有误!\n");
                exit(-1);
            }

            shortestdistance(G);
            minroad=G->edge[start-1][end-1];
            display(G,start,end);
            printf("\n");
            printf("最小路径为：%.2f M\n",minroad);

        }else if(choice==2){

            printf("请输入您想查询位置的序号\n");
            scanf("%d",&place);
            for(i=0;i<G->vertexnum;i++){
                if(place==i+1){
                    printf("该地点为:\n");
                    puts(G->place[i].name);
                    printf("简介为：\n");
                    puts(G->place[i].intro);
                }

            }
        }else if(choice==3){
            return;
        }else{
            printf("输入错误！\n");
        }
        printf("\n");
        getchar();
        printf("请按任意键返回\n");
        getchar();
        system("clear");
    }

}
void shortestdistance(Graph *G)
{

    int k,v,w;
    //k为中间点
    // v为起点
    //w为终点
    for(k=0;k<G->vertexnum;k++)
    {
        for(v=0;v<G->vertexnum;v++)
        {
            for(w=0;w<G->vertexnum;w++)
            {
                if(G->edge[v][w]>(G->edge[v][k]+G->edge[k][w]))
                {
                    G->edge[v][w]=G->edge[v][k]+G->edge[k][w];
                    path[v][w]=k;//v->w要经过 k

                    path[w][v]=k;//w->v要经过 k
                                }
           }
        }
     }

}
void display(Graph *G,int start,int end)
{
    int i=start-1;
    int j=end-1;

    printf("您要查询的两景点间最短路径是: \n");
    if(G->edge[i][j]!=INF)
    {
        if(i<j)
        {
            printf("%s",G->place[end-1].name);
            while(path[i][j]!=0)
            {/*?把i到j的路径上所有经过的景点按逆序打印出来*/
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


 /*************************************************/


List_User *initList_User(){
 List_User *list = (List_User *)malloc(sizeof(List_User));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;

    return list;
}//链表初始化

void addTail_User(List_User *list,User *data){

    NodeUser *node = (NodeUser *)malloc(sizeof(NodeUser));
    node->data = data;
    node->next = NULL;

    if(list->head == NULL){
        list->head = node;
    }else{
        list->tail->next = node;
    }
    list->tail = node;

    return;
}//头插法构建链表

void Free_Userlist(NodeUser *list){

    NodeUser *tmp;
    while(list != NULL){
        tmp = list;
         list = list->next;
        free(tmp);
        tmp = NULL;
    }
    return;
}//释放链表


void UserToFile_list(List_User *list){

    NodeUser *tmp = list->head;
    FILE *fp;
    fp = fopen("user.txt","a");
    if (fp != NULL)
    {
        while(tmp != NULL){
            fprintf(fp, "%ld\t", tmp->data->number);
            fprintf(fp, "%s\t", tmp->data->password);
            fprintf(fp, "%s\n", tmp->data->name);

            tmp = tmp->next;
        }
        fclose(fp);
    }else{
        printf("文件保存失败 ！\n");
    }
}

void UserFromFile_list(List_User *list){
 FILE *fp;
    fp = fopen("user.txt", "r");
    if (fp != NULL)
    {
        while(!feof(fp)){
            User *user = (User *)malloc(sizeof(User));
            fscanf(fp, "%ld", &(user->number));
            fscanf(fp, "%s", user->password);
            fscanf(fp, "%s", user->name);

            addTail_User(list,user);
        }

        fclose(fp);

    }else{
        printf("文件打开失败 ！\n");
    }
    return;
}
/************************************************************************/

void CreateTree_User(Tree_User *tree, User *data){
    TreeNode_User *node = (TreeNode_User *)malloc(sizeof(TreeNode_User));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    if (tree->root == NULL){
        tree->root = node;
}else{
        TreeNode_User *tmp = tree->root;
        while(tmp != NULL){
            if (tmp->data->number > data->number ){
                if (tmp->left == NULL){
                    tmp->left = node;
                    return;
                }else{
                    tmp = tmp->left;
                }
            }else{
                if (tmp->right ==NULL){
                    tmp->right = node;
                    return;
                }else{
                    tmp = tmp->right;
                }
            }
        }
    }
    return;
}

void displayTree_User(TreeNode_User *tree){

    if(tree->data->number == 0 || tree->data->number > 1000000000000)       return;
    printf("账号: %ld\t",tree->data->number);
    printf("用户名: %s\t",tree->data->name);
     printf("\n");
    printf("_____________________________________________________________________________________\n");

    return;
}

void InOrder_User(TreeNode_User *tree){
    if (tree){
        InOrder_User(tree->left);
        displayTree_User(tree);
        InOrder_User(tree->right);
    }
    return;
}

void FreeTree_User(TreeNode_User *tree){
    if (tree){
        FreeTree_User(tree->left);
        free(tree->data);
        free(tree);
        FreeTree_User(tree->right);
    }
    return;
}

void UserFromFile_Tree(Tree_User *tree){
    FILE *fp;
    fp = fopen("user.txt", "r");
    if (fp != NULL)
    {
        while(!feof(fp)){
            User *user = (User *)malloc(sizeof(User));
            fscanf(fp, "%ld", &(user->number));
            fscanf(fp, "%s", user->password);
            fscanf(fp, "%s", user->name);

            CreateTree_User(tree, user);
        }

        fclose(fp);

    }else{
        printf("文件打开失败 ！\n");
    }
    return;
}
/****************************************************************/

User *Input_User_Data(){
    system("clear");
    long int number;
    char password[50];
    char name[30];
    User *user = (User *)malloc(sizeof(User));
    printf("请输入你要注册的账户\n");
    scanf("%ld",&number);
    user->number = number;
    printf("请输入姓名\n");
    scanf("%s",name);
    strcpy(user->name,name);

    printf("请输入密码\n");
    scanf("%s",password);
    strcpy(user->password,password);

    printf("\n");
    printf("请按任意键返回\n");
    getchar();
    getchar();
    system("clear");


    return user;
}

TreeNode_User *Tree_Search_User(TreeNode_User *tree,long int number){
    TreeNode_User *ptr = tree;
    while(ptr){
        if ( ptr->data->number == number )  return(ptr);
        if (ptr->data->number > number )        ptr = ptr->left;
        else    ptr = ptr->right;
    }
    return NULL;
}

long int SignIn_User(){
      system("clear");
    long int number;
    char password[50];
    int sign1 = 1, sign2 = 1;
    Tree_User *tree = (Tree_User *)malloc(sizeof(Tree_User));
    TreeNode_User *node;
    tree->root = NULL;
    UserFromFile_Tree(tree);
    printf("请输入账号\n");
    scanf("%ld",&number);

    while(1){
        if(sign1 >= 3){
                printf("账号错误三次 !\n");
                printf("正在退出....\n");
                sleep(2);
                system("clear");
                return 0;

        }else if((node = Tree_Search_User(tree->root,number)) == NULL){
                printf("账号不存在 !\n");
                printf("请重新输入\n");
                scanf("%ld",&number);

                sign1++;

        }else{
            break;
        }
  }
    printf("请输入密码\n");
    scanf("%s",password);
    while(1){
        if(sign2 >= 3){
                printf("密码错误三次 !\n");
                printf("正在退出....\n");
                sleep(2);
                system("clear");
                return 0;

        }else if(strcmp(node->data->password,password)){
                printf("密码错误 !\n");
                printf("请重新输入\n");
                scanf("%s",password);

                sign2++;
        }else{
            break;
        }
    }
    FreeTree_User(tree->root);
    printf("\n");
    printf("正在登入.....\n");
    sleep(2);
    getchar();
    system("clear");

    return number;
}

void UserToFile(User *user){

    FILE *fp;
    fp = fopen("user.txt","a");
    if (fp != NULL){
            if(user->number == 0)       return;
            fprintf(fp, "%ld\t", user->number);
            fprintf(fp, "%s\t", user->password);
            fprintf(fp, "%s\n", user->name);

        fclose(fp);
    }else{
        printf("文件保存失败 ！\n");
    }
    return;
}

void User_Menu(User *user){
    char flag;
    int sign = 0;
    int seat = 0;
    Graph G;
    TreeNode_User *node;
    Tree_User *tree = (Tree_User *)malloc(sizeof(Tree_User));
    tree->root = NULL;

    while(1){
 printf("欢迎您: %s\n",user->name );
        printf("1.校园导航\n");
        printf("2.返回上层\n");
        flag = getchar();
        switch(flag){

            case '1':   Init_Graph(&G);
                        show_menu(&G);
                        getchar();
                        system("clear");

                        break;

            case '2':   FreeTree_User(tree->root);
                        system("clear");

                        return;
        }

    }
    return;
}


void SignIn_User_Menu(){
    system("clear");
    char flag;
    long int number;
    User *user = (User *)malloc(sizeof(User));
 User *user1;
    Tree_User *tree = (Tree_User *)malloc(sizeof(Tree_User));
    TreeNode_User *node;
    tree->root = NULL;
    UserFromFile_Tree(tree);
    while(1){
        printf("1.登入\n");
        printf("2.注册\n");
        printf("3.退出\n");
        flag = getchar();
        switch(flag){
            case '1':   UserFromFile_Tree(tree);
                        if((number = SignIn_User(user)) != 0){
                            node = Tree_Search_User(tree->root,number);
                            User_Menu(node->data);

                        }
                        FreeTree_User(tree->root);
                        tree->root = NULL;
                        getchar();
                        break;
            case '2':   user1 = Input_User_Data();
                        UserToFile(user1);
                        FreeTree_User(tree->root);
                        tree->root = NULL;
                        break;
            case '3':   free(user);
                        FreeTree_User(tree->root);
                        getchar();
 system("clear");

                        return;
        }
    }


    return;
}

void Manage_Menu(){
    char flag;
    Tree_User *tree = (Tree_User *)malloc(sizeof(Tree_User));
    tree->root = NULL;
    UserFromFile_Tree(tree);
    while(1){
        printf("1.用户信息\n");
        printf("2.退出\n");
        flag = getchar();
        switch(flag){

            case '1':   getchar();
                        system("clear");
                        InOrder_User(tree->root);
                        printf("\n");
                        printf("请按任意键返回\n");
                        getchar();
                        system("clear");
                        break;
 case '2':   system("clear");
                        FreeTree_User(tree->root);
                        return;
        }

    }
    return;
}


void Main_Menu(){
    char flag;
    while(1){
        printf("请选择你要进行的操作\n");
        printf("1.用户登入\n");
        printf("2.管理\n");
        printf("3.退出\n");
        flag = getchar();
        switch(flag){

            case '1':   getchar();
                        system("clear");
                        SignIn_User_Menu();
                        system("clear");
                        break;
            case '2':   system("clear");
                        getchar();
                        Manage_Menu();
                        system("clear");
                        getchar();
                        break;

            case '3':   system("clear");
                        return;


        }

    }
}















