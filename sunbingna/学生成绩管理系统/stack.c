#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<string.h>
#include<unistd.h>

typedef struct node{
	char account[5],password[5];
	struct node *next;
}stacknode, *plinkstack;

typedef struct stack{
	plinkstack top;		//栈顶指针 
	int count;				//计数器 
}Linkstack;

int stackempty(Linkstack  S)
{ 
        if (S.count == 0)
                return 1;
        else
                return 0;
}

void push(Linkstack *S)		//入栈操作 
{
    char account[5],password[5],repassword[5];
	plinkstack s = (plinkstack)malloc(sizeof(stacknode));
    printf("\n请输入帐号:");
    scanf("%s",account);
    printf("\n请输入密码:");
    scanf("%s",password);
    printf("\n请确认密码:");
    scanf("%s",repassword);
    if(strcmp(password,repassword) != 0)
    {
        printf("\n密码有误!\n");
        sleep(2);
        return;
    }
	strcpy(s->account,account);
    strcpy(s->password,password);
	s -> next = S -> top;		//把当前的栈顶赋值给新的元素的后继(指针的指向)
	S -> top = s;		//新的节点赋值给栈顶指针（即让新元素成为栈顶元素）
	S -> count++;
    printf("\n注册成功!\n");
    sleep(2);
}


void traversestack(Linkstack s)
{
	plinkstack p;
	p = s.top;
	while(p)
	{
        printf("%s%s",p->account,p->password);
		p = p -> next;
	}
	printf("\n");
}

/*  构造一个空栈S */
void InitStack(Linkstack *S)
{   
    S -> top = (plinkstack)malloc(sizeof(stacknode));
    S -> top = NULL;
    S -> count = 0;
}

bool match(Linkstack *S)
{
    plinkstack p = (plinkstack)malloc(sizeof(stacknode));
    char account[5],password[5];
    printf("\n请输入帐号:");
    scanf("%s",account);
    printf("\n请输入密码:");
    scanf("%s",password);
    if(S->count == 0)
    {
        printf("\n查无此人!请先注册!\n");
        sleep(2);
        return false;
    }
    p = S->top;
    while(p)
	{
        if(strcmp(p->account,account) == 0&&strcmp(p->password,password) ==0)
        {
            printf("\n欢迎登录!\n");
            sleep(2);
            return true;
        }
		p = p -> next;
        if(p == NULL)
        {
            printf("查无此人!请重新输入!\n");
            sleep(2);
            return false;
        }
	}
}

/* int main()
{
        int j;
        Linkstack s;
        InitStack(&s);
        push(&s);
        traversestack(s);
        return 0;
} */
void stackchoice()
{
    Linkstack s;
    InitStack(&s);
    int l;
    while(1)
    {
        choicemenu();
        scanf("%d",&l);
        switch (l)
        {
        case 1:
            {
                if(match(&s))
                Choice();
            }
            break;
        case 2:
            push(&s);
            break;
        case 3:
            exit(0);
            break;
        default:
            break;
        }
    }
}