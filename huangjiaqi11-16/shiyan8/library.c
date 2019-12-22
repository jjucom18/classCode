#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AVAILABLE 0
#define UNAVAILABLE 1
#define MAXNAME 30
#define CLEAR "cls"

typedef struct book{
    char *name;
    int id;
    int count;
    int status;
    struct book *next;
}Book;

void welcome();
void error(char *);           // [异常提醒]
char land();                  // [主页面项目]
int usrstudent();             // [学生入口]返回 0表示返回主页 1表示继续执行本函数
int usrmanager();             // [管理员入口]返回 0表示返回主页 1表示继续执行本函数
int viewbook();               // [查看图书]返回打印的图书个数     失败返回-1
int addbook();                // [注册图书]添加图书成功 返回图书id  失败返回-1
int modbook();                // [修改图书]修改图书信息   成功后返回id  失败 -1
int delbook();                // [注销图书]删除成功 返回被删除图书的id 失败返回-1
void printbook(Book *);       // [打印图书]
Book *lookup(char *, int);    // [搜索图书]
int borrowbook();             // [借阅图书]
int returnbook();             // [归还图书]

Book *head = NULL;
int nbook = 0;
int main(){
    
    welcome();
    return 0;
}
void welcome(){
    printf("*************************欢迎使用图书管理系统*************************\n");
    while(1){
        printf("-------------------------------------\n");
        printf("请输入项目前编号执行相关操作：\n");
        printf("\n[1] 管理员入口\n\n[2] 学生入口\n\n[0] 退出\n\n");
        switch(land()){
            case '1':
                while(1){
                    if(usrmanager()){
                        continue;
                    }else{
                        break;
                    }
                 }
                break;
            case '2':
                while(1){
                    if(usrstudent()){
                        continue;
                    }else{
                        break;
                    }
                }
                break;
            case '0':
                exit(0);
            default:
                error("采集项目参数失败");
        }
    }
}
char land(){
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("[请输入命令： 1 / 2 / 0 选择项目]");
    }
    return '\0';
}
void error(char *s){
    fprintf(stderr, "%s\n", s);
}
char dostudent(){
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i )
            ;
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '3' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("[请输入命令： 1 / 2 / 3/ 0 选择项目]");
    }
}
int usrstudent(){
    printf("-------------------------------------\n");
    printf("请输入项目前编号执行相关操作：\n\n");
    printf("[1] 借阅图书\n[2] 归还图书\n[3] 查看馆存图书\n");
    printf("[0] 返回主页\n");
    switch(dostudent()){
        case '1':
            borrowbook();
            break;
        case '2':
            returnbook();
            break;
        case '3':
            viewbook();
            break;
        case '0':
            return 0;
        default:
            error("采集项目参数失败");
            break;
    }
    return 1;
}
int borrowbook(){
    system(CLEAR);
    char sname[MAXNAME];
    printf("搜索图书:\n");
        scanf("%s", sname);
        getchar();
        Book *bp;
        char *namep = NULL;
        if((bp = lookup(namep = strdup(sname), 0)) == NULL){
            printf("图书 %s 不存在\n", namep);
            fflush(stdin);
            return -1;
        }else{
            printbook(bp);
            if(! bp->status){
                printf("借阅图书： Y N\n");
            }else{
                printf("图书外借中\n");
                return 0;
            }
            while(1){
                char c = '\0';
                scanf("%c", &c);
                getchar();
                if(!(c == 'Y' || c == 'y' || c == 'N' || c == 'n')){
                    fflush(stdin);
                    error("指令无效");
                    continue;
                }
                if(c == 'Y' || c == 'y'){
                    --bp->count > -1 ? printf("成功\n") : printf("失败\n");
                    if(! bp->count){
                        bp->status = UNAVAILABLE;
                    }
                    return bp->id;
                }else{
                    return 0;
                }
            }
        }  
    return -1;
}
int returnbook(){
    system(CLEAR);
    char sname[MAXNAME];
    printf("归还图书：\n");
    scanf("%s", sname);
    getchar();
    Book *bp;
    char *namep;
    if((bp = lookup(namep = strdup(sname), 0)) == NULL){
        fflush(stdin);
        printf("此图书并不是馆内图书\n");
        return -1;
    }else{
        printbook(bp);
        printf("归还图书： Y N\n");
        while(1){
            char c = '\0';
            scanf("%c", &c);
            getchar();
            if(!(c == 'Y' || c == 'y' || c == 'N' || c == 'n')){
                fflush(stdin);
                error("指令无效");
            }else if(c == 'Y' || c == 'y'){
                bp->count++ ? : (bp->status = AVAILABLE);
                printf("成功\n");
                return bp->id;
            }else{
                return 0;
            }
        }
    }

    return -1;
}
char domanager(){

    char c, flag;
    int i;
    
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '3' || flag == '4' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("[请输入命令： 1 / 2 / 3/ 4 / 0 选择项目]");
            
    }
    
    return '\0';
}
int usrmanager(){
    printf("-------------------------------------\n");
    printf("请输入项目前编号执行相关操作：\n\n");
    printf("[1] 查看已存图书\n[2] 注册新图书\n[3] 修改已有图书信息\n[4] 注销现存图书\n");
    printf("[0] 返回主页\n");
    switch(domanager()){
        case '1':
            viewbook();
            break;
        case '2':
            addbook();
            break;
        case '3':
            modbook();
            break;
        case '4':
            delbook();
            break;
        case '0':
            return 0;
        default:
            error("采集项目参数失败");
            break;
    }
    return 1;

}
int viewbook(){
    system(CLEAR);      ///////////////////////////////////////////
    Book *bp;
    for(bp =head; bp != NULL; bp = bp->next){
        printbook(bp);
    }
    if(nbook){
        return nbook;
    }else{
        printf("图书馆还没有图书哦\n");
        return 0;
    }
    return -1;
}
void printbook(Book *bp){
    printf("图书编号：%d\n", bp->id);
    printf("图书名：%s\n", bp->name);
    printf("图书存数：%d\n", bp->count);
    printf("图书状态：%s\n", bp->status ? "不可借" : "可借");
}
int addbook(){
    system(CLEAR);      ///////////////////////////////////////////
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
        printf("请输入小于1000的图书编号：\n");
        scanf("%d", &id);
        getchar();
        if(!(id > 0 && id < 1000)){
            error("输入编号不符合要求");
            fflush(stdin);
            continue;
        }
        printf("请输入小于50的图书数量：\n");
        scanf("%d", &count);
        getchar();
        if(!(count > 0 && count < 50)){
            error("输入数目不符合要求");
            fflush(stdin);
            continue;
        }
        Book *bp;        
        if((bp = lookup(namep = strdup(sname), id)) == NULL){
            bp = (Book *)malloc(sizeof (Book));
            if(bp == NULL || (bp->name = namep) == NULL){
                error("注册图书失败");
                fflush(stdin);
                continue;
            }
            bp->id = id;
            bp->count = count;
            bp->status = AVAILABLE;
            ++nbook;
            
            bp->next = head;
            head = bp;
            printf("图书 %s 注册成功\n", sname);
            return id;
        }else{
            fflush(stdin);
            error("图书名或编号已经被占用");
        }
    }

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
int modbook(){  // 修改除id之外的信息  因为要修改id 直接删掉后重新添加会更好
    system(CLEAR);      ///////////////////////////////////////////
    Book *bp = NULL;
    while(1){
        int id = 0;
        printf("请输入要修改信息的图书编号：\n");
        scanf("%d", &id);
        getchar();
        if(!(id > 0 && id < 1000)){
            fflush(stdin);
            error("图书编号不符合要求");
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
                    error("输入项目前编号选择相关项目");
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
                                error("图书名已存在");
                                continue;
                            }
                            if((bp->name = namep) != NULL){
                                printf("修改成功\n");
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
                                error("数目不符合要求");
                                continue;
                            }
                            bp->count = bnum;
                            printf("修改成功\n");
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
                                error("指令无效");
                                continue;
                            }
                            if(c == 'Y' || c == 'y'){
                                 status == AVAILABLE ? bp->status = UNAVAILABLE : (bp->status = AVAILABLE);
                                 printf("修改成功\n");
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
                        error("获取参数失败");
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
    system(CLEAR);      ///////////////////////////////////////////
    Book *bp, *fbp;
    
    int id = 0;
    printf("请输入要注销的图书编号：\n");
    scanf("%d", &id);
    getchar();
    if(!(id > 0 && id < 1000)){
        fflush(stdin);
        error("图书编号不符合要求");
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
                error("指令无效\n");
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
    return -1;
}
