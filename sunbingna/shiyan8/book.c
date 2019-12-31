#include"book.h"

    Book *head = NULL;
    int nbook = 0;

int choice(){
    while(1){
        system("clear");
    int m;
    printf("\n*************************欢迎使用图书管理系统*************************\n\n");
    printf("请输入项目前编号执行相关操作：\n\n");
    printf("[1] 查看图书\n[2] 添加新图书\n[3] 修改图书信息\n[4] 删除图书\n");
    printf("[0] 退出系统\n");
    
        scanf("%d",&m);
    switch(m){
        case 1:
            viewbook();
            break;
        case 2:
            addbook();
            break;
        case 3:
            modbook();
            break;
        case 4:
            delbook();
            break;
        case 0:
            return 0;
        default:
            printf("采集项目参数失败");
            break;
    }}
    return 1;
    
}
int viewbook(){
    system("clear");  
    Book *bp;
    printf("图书编号 图书名 图书存数 图书状态\n");
    for(bp =head; bp != NULL; bp = bp->next){
        printf("%d \t%s\t%d\t%s\n", bp->id, bp->name,bp->count,bp->status ? "不可借" : "可借");
    }sleep(2);
    if(nbook){
        return nbook;
    }else{
        printf("图书馆还没有图书哦\n");
        return 0;
    }
    sleep(2);
    return -1;
}
void printbook(Book *bp){
    printf("图书编号 图书名图书存数图书状态\n");
    printf("%d \t%s\t%d\t%s\n", bp->id, bp->name,bp->count,bp->status ? "不可借" : "可借");
}

int addbook(){
    system("clear");     
    char sname[MAXNAME];
    int id, count;
    char *namep;

    while(1){
        id = 0;
        count = 0;
        namep = NULL;
        printf("请输入图书名：\n");
        scanf("%s", sname);
        getchar();
        printf("请输入图书编号：\n");
        scanf("%d", &id);
        getchar();
        if(!(id > 0 && id < 1000)){
            printf("输入编号不符合要求");
            fflush(stdin);
            continue;
        }
        printf("请输入图书数量：\n");
        scanf("%d", &count);
        getchar();
        if(!(count > 0 && count < 50)){
            printf("输入数目不符合要求");
            fflush(stdin);
            continue;
        }
        Book *bp;        
        if((bp = lookup(namep = strdup(sname), id)) == NULL){
            bp = (Book *)malloc(sizeof (Book));
            if(bp == NULL || (bp->name = namep) == NULL){
                printf("注册图书失败");
                fflush(stdin);
                continue;
            }
            bp->id = id;
            bp->count = count;
            bp->status = AVAILABLE;
            ++nbook;
          /*   Book *p = head;
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = bp; */
            
            bp->next = head;
            head = bp;
            printf("图书 %s 注册成功\n", sname);
            
            return id;
        }else{
            fflush(stdin);
            printf("图书名或编号已经被占用");
        }
    }
sleep(2);
    return -1;
}
Book *lookup(char *s, int id){
    Book *bp;
    for(bp = head; bp != NULL; bp = bp->next){
        if(id == bp->id || strcmp(s, bp->name) == 0){
            return bp;
        }
    }
    return NULL;
}
int modbook(){  
    system("clear");    
    Book *bp = NULL;
    while(1){
        int id = 0;
        printf("请输入要修改信息的图书编号：\n");
        scanf("%d", &id);
        getchar();
        if(!(id > 0 && id < 1000)){
            fflush(stdin);
            printf("图书编号不符合要求");
            continue;
        }
        if((bp = lookup("", id)) != NULL){
            printf("以下为要修改的图书的现有信息：\n");
            printbook(bp);
            printf("[1] 修改图书名\n[2] 修改图书数量\n[3] 修改图书状态\n[0] 放弃修改\n");
            while(1){
                int i;
                scanf("%d", &i);
                getchar();
                if(!(i == 1 || i == 2 || i == 3 || i == 0)){
                    fflush(stdin);
                    printf("输入项目前编号选择相关项目");
                    continue;
                }
                switch(i){
                    case 1:
                        while(1){
                            char newname[MAXNAME], *namep;
                            printf("图书名：\n");
                            scanf("%s", newname);
                            getchar();
                            if((lookup(namep = strdup(newname), 0)) != NULL){
                                fflush(stdin);
                                printf("图书名已存在");
                                continue;
                            }
                            if((bp->name = namep) != NULL){
                                printf("修改成功\n");
                                sleep(2);
                                return id;
                            }
                        }
                        break;
                    case 2:
                        while(1){
                            int bnum;
                            printf("输入图书数量：\n");
                            scanf("%d", &bnum);
                            getchar();
                            if(!(bnum > 0 || bnum < 1000)){
                                fflush(stdin);
                                printf("数目不符合要求");
                                continue;
                            }
                            bp->count = bnum;
                            printf("修改成功\n");
                            sleep(2);
                            return id;
                        }
                        break;
                    case 3:
                        while(1){
                            char c;
                            int status;
                            status = bp->status;
                            status == AVAILABLE ? printf("修改状态为[不可借]： Y N\n") : printf("修改状态为[可借]： Y N\n");
                            scanf("%c", &c);
                            getchar();
                            if(!( c == 'Y' || c == 'y' || c == 'N' || c == 'n')){
                                fflush(stdin);
                                printf("指令无效");
                                continue;
                            }
                            if(c == 'Y' || c == 'y'){
                                 status == AVAILABLE ? bp->status = UNAVAILABLE : (bp->status = AVAILABLE);
                                 printf("修改成功\n");
                                 sleep(2);
                                 return id;
                            }else{
                                printf("放弃修改\n");
                                return 0;
                            }
                        }
                        break;
                    case 0:
                        return 0;
                    default:
                        printf("获取参数失败");
                        break;   
                }
            }
        }else{
            printf("没有此图书\n");
            return 0;
        }
    }
    return -1;
}
int delbook(){
    system("clear");      ///////////////////////////////////////////
    Book *bp, *fbp;
    
    int id = 0;
    printf("请输入要注销的图书编号：\n");
    scanf("%d", &id);
    getchar();
    if(!(id > 0 && id < 1000)){
        fflush(stdin);
        printf("图书编号不符合要求");
        return -1;
    }
    for(fbp = bp = head; bp != NULL; fbp = bp, bp = bp->next){
        if(bp->id == id){
            printbook(bp);
            break;
        }
    }
    if(bp != NULL){
        while(1){
            printf("确定要注销此图书：Y  N\n");
            char YN;
            scanf("%c", &YN);
            getchar();
            if(!((YN == 'Y' || YN == 'y') || (YN == 'N' || YN == 'n'))){
                fflush(stdin);
                printf("指令无效\n");
                continue;
            }
            if(YN == 'Y' || YN == 'y'){
                bp == head ? head = bp->next : (fbp->next = bp->next);
                free(bp->name);                                         //2018-05-26修改：添加释放name这块内存//bp内存的只是指向name的指针
                free(bp);
                bp = NULL;
                printf("图书注销成功\n");
                break;
            }else{
                printf("放弃注销\n");
                return 0;
            }
        }  
        return id;
    }else{
        printf("要注销的图书编号不存在\n");
        return -1;
    }
    sleep(2);
    return -1;
}

