#include<stdio.h>
#include<string.h>
#include"List.c"

int main()
{       int choice = 0;
        int num = 0;
        LinkQueue Q;
        initQueue(&Q);
        while(1)
        {
                printf("################ Bank queuing system #############\n");
                printf("###           1:申请一个号码           \n");
                printf("###           2:询问                       \n");
                printf("###           3:离开银行    \n");
                printf("###           4:取号列表    \n");
                printf("###           5:退出                       \n\n\n");
                printf("   请输入你的选择[1-5]:   ");
                scanf("%d",&choice);
                switch(choice)
                {  case 1 :
                        if(flag)
                        {
                                system("clear");
                                bankNumber++;
                                enterQueue(&Q,bankNumber);
                                totalNumber++;
                                printf("您的等待号码id %d\n",bankNumber);
                                printf("%d 在你之前，请等一会儿\n",Query(&Q,bankNumber));
                                sleep(2);
                                system("clear");
                                break;
                        }
                        else
                        {
                                system("clear");
                                printf("         停止申请银行号码\n");
                                break;
                        }
                case 2 :
                        system("clear");
                        printf("请输入你的号码:\n");
                        scanf("%d",&num);
                        printf("%d 在你之前，请等一会儿\n",Query(&Q,num));
                        sleep(2);
                        system("clear");
                        break;
                case 3 :
                        system("clear");
                        printf("you (%d) are leaving bank ....\n",Q.front->next->value);
                        deQueue(&Q);
                        totalNumber--;
                        sleep(2);
                        system("clear");
                        break;
                case 4 :
                        system("clear");
                        printf("Waiting List :");
                        printQueue(&Q);
                        sleep(3);
                        system("clear");
                        break;
                case 5 :
                        exit(0);
                        break;
                default :
                        break; } }
                return OK;
}
