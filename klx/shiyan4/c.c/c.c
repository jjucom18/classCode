#include<stdio.h>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<stack>
int main()
{
    Manager dch;
    int IfContinue=1;
    while(IfContinue)
    {
        cout<<"what do you want to do?"<<endl;
        cout<<"Input ----(add/del/exit)"<<endl;
        char cmd[5];
        scanf("%s",cmd);
        switch(cmd[0])
        {
        case 'a':
        {
            string num;
            int arrtime;
            cout<<"input the number And arrtime:";
            cin>>num>>arrtime;
            dch.AddCar(Car(num,arrtime));
            break;
        }
        case 'd':
        {
            string num;
            int awaytime;
            cout<<"input the number And awaytime:";
            cin>>num>>awaytime;
            Car dchOfCar=dch.DelCar(num,awaytime);
            cout<<"charge:"<<dch.Charge(dchOfCar);
            break;
        }
        case 'e':
        {
            IfContinue=0;
            scanf("%*s %*d");
            break;
        }
        default:
            printf("input error!---please input again:\n");
            break;
        }
    }
}
