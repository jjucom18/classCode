#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h> 
#include<windows.h>
#include<conio.h>


int main(){
    LinkedList bank;
    bank=LinkedListInit();
    LinkedListCreat(bank);
    menu(bank); 
    return 0;
 }

int LinkedListInsert(LinkedList head){
            int tempnum;
            char gc;
            char tempname[10];
            float tempbalance;
//采用随机数生成用户的帐号
            do{  
                tempnum = rand()%100000*10; //随机生成   
             }while((tempnum/100000)==0);//检查是否是六位数
            printf("系统为你自动生成的6位数帐号是%d\n",tempnum);

//输入用户姓名！！！
            printf("请输入用户姓名：");
            fflush(stdin);
            for(int i=0;i<9;i++){
            scanf("%c",&gc);
            if(gc == '\r' || gc == '\n') break;
                 tempname[i] = gc;
                    }   
//余额输入
            printf("请输入用户余额：");
            scanf("%f",&tempbalance);

//以下是在单链表中将账户按帐号由小到大的顺序存放的操作。          
            LinkedList p;
            LinkedList q,r;
            p = head->next; 

//将账户信息放在r结点上
            r =(LinkedList)malloc(sizeof(Account));
            r->accnum = tempnum;
            for(int i=0;i<9;i++){
               r->name[i]=tempname[i];
               }
            r->balance = tempbalance;
            r->next = NULL;

//找到合理的存放结点处        
            while(p->accnum < r->accnum){
                q = p;
                p = p->next;
                if(p ==NULL)break;    
                 }

//完成插入操作。
            q->next = r;
            r->next = p; 

//清屏并返回主菜单。
            printf("您已完成开户操作，任意键返回主菜单。");
            fflush(stdin);
            getchar();
            system("cls"); 
            return 0;
}

int LinkedListDel(LinkedList head){
           LinkedList p,q,r;
           p = head;
           int tempnum;

//通过帐号来查找需要销毁的账户
           printf("请输入要销毁的账户："); 
           scanf("%d",&tempnum);
           //while循环找到所需销毁帐户
           while(p!=NULL){

//if中的语句为销毁账户的语句。
            if(p->accnum == tempnum){
                r = p ;
                q->next = p->next;
                free(r);

//销毁完成后返回主菜单。
                fflush(stdin);
                printf("\n账户已销毁，任意键返回主菜单。"); 
                getchar();
                system("cls");
                return 0; 
                  }
             else 
             q = p;
             p = p->next;
             continue;

//账户不存在时则返回主菜单
            printf("\n账户不存在，3秒后返回主菜单。");
            Sleep(3000);
            system("cls");
            fflush(stdin);
            return 0;
}


//取款

int hhh(LinkedList head){      //就要hhh
    int tempnum;
    float tempbalance;
    LinkedList p,q;
    p = head->next;

//tempbalance临时存放存入金额，tempnum临时存放帐号
    printf("请输入取款帐号：");
    scanf("%d",&tempnum);
    while(p!=NULL){
        if(p->accnum == tempnum){
            printf("请输入取款金额：");
            scanf("%f",&tempbalance);

//余额不足则返回主菜单
            if(tempbalance > p->balance){
                printf("对不起，您的余额不足。\n\n");
                printf("三秒后返回菜单");
                fflush(stdin);
                system("cls");
                return 0;
              }
            else 
            p->balance = p->balance - tempbalance;

//取款完成后返回主菜单。
            printf("取款操作完成，任意键返回主菜单。");
            fflush(stdin);
            getchar();
            system("cls"); 
            return 0;                   
                }
                    else 
                    q = p;
                    p = p->next;
                    continue;
                    }

//未完成操作同样需返回主菜单。
                printf("\n账户不存在，3秒后返回主菜单。");
                Sleep(3000);
                system("cls");
                fflush(stdin);
                return 0;
} 


//存款

int  putinmoney(LinkedList head ){
    int num;
    float tempbalance; 
    LinkedList p;
    LinkedList q;
    p=head->next;

//num存放存款的帐号，tempbalance存放所存的金额。
    printf("请输入需存款的账户帐号: ");
    scanf("%d",&num); 

//找到对应的账户。
    while(p!=NULL){
         if(p->accnum == num){
            printf("请输入您的存款金额");
            scanf("%f",&tempbalance); 
            p->balance = p->balance + tempbalance;
            printf("存款完成，您现在的余额为：%f",p->balance);

//操作完成后返回主菜单。
            printf("\n任意键返回主菜单。");
            fflush(stdin);
            getchar();
            system("cls"); 
            return 0;
              }
         else 
            q = p;
            p = p->next;
            continue;
       }

//操作失败仍返回主菜单。
    printf("该用户不存在，三秒后返回主菜单！");
    Sleep(3000);
    system("cls");
    fflush(stdin);
    return 0;
 }


//查询

int  LinkedListGet(LinkedList head ){
   int num; 
   LinkedList p,q;
   p=head->next;

//num存放需查找的帐号。
   printf("请输入需查找的账户帐号: ");
   scanf("%d",&num);

//开始查询账户 
   while(p!=NULL){
        if(p->accnum == num){

//以下为输出的账户信息
            printf("%d\n",p->accnum);
            for(int i=0;i<9;i++){
                  if(p->name[i+1]=='\0')break;
                  else
                    printf("%c",p->name[i]);
              }
        printf("\n%f\n",p->balance);

//完成查询后返回主菜单。
        printf("您所查找的账户信息如上，任意键返回主菜单！");
        fflush(stdin);
        getchar();
        system("cls");
        return 0;
          }
        else 
            q = p;
            p = p->next;
            continue;
       }

//查询未完成也返回主菜单
      if(p==NULL){
        printf("该用户不存在，三秒后返回主菜单！");
        Sleep(3000);
          }
    system("cls");
    fflush(stdin);
    return 0;
 }


//菜单界面

//是不是很low，HHH
void showmenu(){
    printf("\n\n\n\n\n");
    printf("\t\t\t  以下为银行功能，请输入功能前的序号\n");
    printf("\t\t\t---------------------------------------\n");
    printf("\t\t\t|             1.开户                  |\n");
    printf("\t\t\t|             2.销户                  |\n");
    printf("\t\t\t|             3.支出                  |\n");
    printf("\t\t\t|             4.存入                  |\n");
    printf("\t\t\t|             5.查询                  |\n");
    printf("\t\t\t|             6.退出                  |\n");
    printf("\t\t\t---------------------------------------\n\n");
} 

  
对应与菜单各个功能的选择

//嗯，很简单的switch。（大拇指！！！）
int  menu(LinkedList head){
    int i;
    while(1){
    showmenu();
    scanf("%d",&i);
    switch(i){
        case 1:system("cls");LinkedListInsert(head); break;
        case 2:system("cls");LinkedListDel(head);break;
        case 3:system("cls");balancehhh(head);break;
        case 4:system("cls");putinmoney(head);break;
        case 5:system("cls");LinkedListGet(head);break;
        case 6:exit(0);
        default:system("cls");
        }
    }
    return 0;
 }
