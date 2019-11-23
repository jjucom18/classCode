#include"carpark.h"

CAR parking[10];
CAR giveway[10];
int per = N;
int topp = -1;
int topg = -1;
QUE *front = NULL;
QUE *rear = NULL;
 
void enterque()
{
    QUE *newnode = (QUE *)malloc(sizeof(QUE));
    if(rear == NULL)
    {
	newnode->flt = 1;
	front = newnode;
	rear = newnode;
	rear->next = NULL;
    }
    else
    {
        newnode->flt = 1;
	rear = newnode;
	rear->next = NULL;
    }
}
 
void outque()
{
    if(front == NULL)
    {
        printf("没有人在等待!\n");
    }
    else
    {
 
        QUE *tmp = front;
	front->flt = 0;
	front = front->next;
	free(tmp);
	tmp = NULL;
    }
}
 
void pushp()
{
    if(topp == 9)
    {
        printf("停车位已满，请等待！\n");
    }
    else
    {
        topp++;
        time_t timer = time(NULL);
	parking[topp].timer = (char *)malloc(30);
	strcpy(parking[topp].timer,ctime(&timer));
    }
}
 
char * popp()
{
    char *str = (char *)malloc(30);
    if(topp == -1)
    {
        printf("停车位为空！\n");
    }
    else
    {
        strcpy(str,parking[topp].timer);
	free(parking[topp].timer);
	parking[topp].timer = NULL;
	topp--;
    }
    return str;
}
 
void pushg(char *tm)
{
    if(topg == 9)
    {
        printf("让路间已经不能在进车了！\n");
    }
    else
    {
        topg++;
	giveway[topg].timer = (char *)malloc(30);
        strcpy(giveway[topg].timer,tm);
    }
}
 
void popg()
{
    if(topg == -1)
    {
        printf("让路间还是空的哦！\n");
    }
    else
    {
        topp++;
	parking[topp].timer = (char *)malloc(30);
        strcpy(parking[topp].timer,giveway[topg].timer);
	topg--;
    }
}
 
void incar()
{
    if(topp == 9)
    {
        printf("停车位已经满！请耐心等待！\n");
	enterque();
    }
    else
    {
        if(rear == NULL)
	{
	    printf("当前有空位！请停车！\n");
	    pushp();
	}
	else
	{
	    printf("停车位已满！请等待！\n");
	    enterque();
	}
    }
}
 
void outcar()
{
    int no,i,temp;
    printf("请输出要出车的停车位号：");
    char *tmp = (char *)malloc(30);
    scanf("%d",&no);
    if(no > topp)
    {
        printf("该车位没有车！\n");
	goto end;
    }
    temp = topp - no;
    for(i = 0; i < temp; i++)
    {
        //char *tmp = (char *)malloc(30);
        tmp = popp();
	pushg(tmp);
    }
    tmp = popp();
    time_t timer = time(NULL);
    printf("进来时间：%s\n",tmp);
    printf("当前时间：%s\n",ctime(&timer));
    mytime(tmp,ctime(&timer));
    for(i = 0;i < temp; i++)
    {
        popg();
    }
    if(front == NULL)
    {
        //printf("我去居然没人在等车～～～\n");
    }
    else
    {
        printf("有空位了！等待人员进入停车！\n");
	outque();
	pushp();
    }
    end:
    printf("");
}
 
void myprint()
{
    int i;
    for(i = 0;i <= topp; i++)
    {
        printf("%d:%s",i,parking[i].timer);
    }
}
 
void mytime(char *timer1,char *timer2)
{
    int hour1 = (timer1[11]- '0') * 10 + (timer1[12] - '0');
    int min1 = (timer1[14]- '0') * 10 + (timer1[15] - '0');
    int sec1 = (timer1[17]- '0') * 10 + (timer1[18] - '0');
    int hour2 = (timer2[11]- '0') * 10 + (timer2[12] - '0');
    int min2 = (timer2[14]- '0') * 10 + (timer2[15] - '0');
    int sec2 = (timer2[17]- '0') * 10 + (timer2[18] - '0');
    printf("您一共停了:%02d:%02d:%02d\n",hour2-hour1,min2-min1,sec2-sec1);
    int money = ((hour2 - hour1) * 60 * 60 + (min2 - min1) * 60 + (sec2 - sec1)) * per;
    printf("消费了%d元钱！\n",money);
}
 
