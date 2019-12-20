//使用函数的版本  
  
#include <stdio.h>  
#include <stdlib.h>  
int pass();  //验证密码  
void work();  //业务驱动  
double getBalance();  //获得余额  
void showMenu();    //显示菜单  
void updatePassword();   //更改密码  
double withdraw(double d);   //取款  
double save(double d);   //存款  
void saveBalance(double d);   //退出系统时保存数据  
  
/*主函数：*/  
int main()  
{  
    printf("欢迎您光临CSDN银行\n");  
    if (pass())  
    {  
        work();  
    }  
    return 0;  
}  
/* 
功能：验证用户密码 
返回值：密码正确，返回1； 
        不能通过密码验证，返回0 
*/  
int pass()  
{  
    int iPass;  //用户验证时输入的密码  
    int iPassInFile;  //记录正确的密码  
    int iTry=3;   //进入系统时尝试的次数  
    FILE *fp;  //用于文件操作  
    //密码保存在文件中，先取出  
    if ((fp=fopen("password.txt", "r"))==NULL)  
    {  
        printf("password file cannot open!");  
        exit(0);  
    }  
    fscanf(fp, "%d", &iPassInFile);  
    fclose(fp);  
  
    //进入系统，密码三次不对将退出  
    do  
    {  
        iTry--;  
        printf("请输入密码：");  
        scanf("%d", &iPass);  
        if(iPass==iPassInFile)  
            break;  
        else  
        {  
            if(iTry>0)  
                printf("超过3次将退出，你已经尝试%d次！\n", iTry);  
            else  
            {  
                printf("对不起，你不能进入系统\n");  
            }  
        }  
    }  
    while(iTry);  
    return iTry;  
}  
  
/* 
功能：办理业务 
*/  
void work()  
{  
    int iChoice;   //用于选择系统功能  
    double dBalance;  //账户余额  
    dBalance = getBalance();  
    //办理业务  
    do  
    {  
        showMenu();  
        printf("请输入（0-4）：");  
        scanf("%d", &iChoice);  
        switch(iChoice)  
        {  
        case 1:  
            printf("您的余额有%.2lf元. \n",dBalance);  
            break;  
        case 2:  
            dBalance = withdraw(dBalance);  
            break;  
        case 3:  
            dBalance = save(dBalance);  
            break;  
        case 4:  
            updatePassword();  
            break;  
        case 0:  
            printf("欢迎您再来. \n");  
        }  
   }  
    while(iChoice);  
    saveBalance(dBalance);  
}  
  
1  
/* 
功能：获得账户余额 
返回值：账户余额 
*/  
double getBalance()  
{  
    double dBalance;  //账户余额  
    FILE *fp;  //用于文件操作  
    //从文件中取出余额  
    if ((fp=fopen("balance.dat", "r"))==NULL)  
    {  
        printf("data file cannot open!");  
        exit(0);  
    }  
    fscanf(fp, "%lf", &dBalance);  
    fclose(fp);  
    return dBalance;  
}  
  
/*功能：显示菜单*/  
void showMenu()  
{  
    printf("\n您可以办理下面的业务：\n");  
    printf("  1.查询\n");  
    printf("  2.取款\n");  
    printf("  3.存款\n");  
    printf("  4.改密码\n");  
    printf("  0.退出\n");  
}  
  
/*功能：更改密码*/  
void updatePassword()  
{  
    FILE *fp;  //用于文件操作  
    int iPassInFile;  
    int iNewPass1, iNewPass2;   //用于修改密码  
    printf("请输入新密码：");  
    scanf("%d", &iNewPass1);  
    printf("再输入新密码：");  
    scanf("%d", &iNewPass2);  
    if(iNewPass1==iNewPass2)  
    {  
        iPassInFile = iNewPass1;  
        printf("密码修改成功，请注意保密.\n");  
        //保存密码（可能修改过）  
        if ((fp=fopen("password.txt", "w"))==NULL)  
        {  
            printf("password file cannot open!");  
            exit(0);  
        }  
        fprintf(fp, "%d", iPassInFile);  
        fclose(fp);  
    }  
    else  
        printf("两次输入不一致，密码修改失败.\n");  
}  
  
/* 
功能：取款 
参数：取款前的余额 
返回值：取款后的余额 
*/  
double withdraw(double d)  
{  
    double dMoney;  //取款金额  
    printf("输入取款额: ");  
    scanf("%lf", &dMoney);  
    if(d>dMoney)  
    {  
        d-=dMoney;  
        printf("取款后，您还有%.2lf元. \n",d);  
    }  
    else  
        printf("余额不足，取款失败. \n");  
    return d;  
}  
  
/* 
功能：存款 
参数：存款前的余额 
返回值：存款后的余额 
*/  
double save(double d)  
{  
    double dMoney;  //存款金额  
    printf("输入存款额: ");  
    scanf("%lf", &dMoney);  
    d+=dMoney;  
    printf("存款后，您有%.2f元. \n",d);  
    return d;  
}  
  
/* 
功能：将余额保存到文件中 
参数值：账户余额 
*/  
void saveBalance(double d)  
{  
    FILE *fp;  //用于文件操作  
    //保存余额  
    if ((fp=fopen("balance.dat", "w"))==NULL)  
    {  
        printf("data file cannot open!");  
        exit(0);  
    }  
    fprintf(fp, "%f", d);  
    fclose(fp);  
}  
