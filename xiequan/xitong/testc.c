#include<iostream>

#include<cstring>

#include<iomanip>

using namespace std;

struct student{

    char name[20];        

    int num;              

    int number;           

    int Class;            

    char major[30];       

    char grade[10];       

    char achievement[200];

};

class votesystem{

private:

    student*st;

    int count;         

    int size;          

public:

    votesystem();

    ~votesystem();

    void InitHashTable(int n);                  //初始化哈希表

    int Hash(char*name);                        //计算哈希地址

    void collision(int &s);                     //冲突，计算下一个地址

    int search(char *name,int &s);              //查找

    void insert(char*name);                      //插入

    int vote(char*name);                        //投票

    void display();                             //显示哈希表

    void showvote(int k);                       //按哈希表下标显示票数

    void showrank();                            //显示排行榜

};

votesystem::votesystem()
{

    st=NULL;

    count=0;

    size=0;

}

votesystem::~votesystem()

{

    delete[]st;

    count=0;

}

 

void votesystem::InitHashTable(int n)  //初始化哈希表

{

    size=n;

    st=new student[size];

    for(int i=0;i<size;i++)

        st[i].name[0]='\0';

}



int votesystem::Hash(char *name)        //求哈希地址，key为所有拼音德ASCII的累计值，size为表长

{

    char *p=name;

    int key=0;

    while(*p)

    {

        key+=int(*p);

        p++;

    }

    return key%size;

}



void votesystem::collision(int &s)       //开放地址发解决冲突

{

    s=s+1;

}



int votesystem::search(char *name,int &s)  //查找

{

    s=Hash(name);                          //哈希表定位

    while(st[s].name[0]!='\0'&&strcmp(st[s].name,name))

        collision(s);   //处理冲突

    if(!strcmp(st[s].name,name))

        return 1;       //找到

    else return 0;      //未找到

}



void votesystem::insert(char *name)//插入

{

    int s;

    char a[2];

    search(name,s);

    cout<<"提名学生信息格式:\n"

    <<"\t学号:1613022006\n"

    <<"\t班级:1\n"

    <<"\t专业:计科\n"

    <<"\t年级:二\n"

    <<"\t突出事迹:国家二等奖学金 \n";

    strcpy(st[s].name,name);

    cout<<"学号:\t";

    cin>>st[s].num;

    cout<<"班级:\t";

    cin>>st[s].Class;

    cout<<"专业:\t";

    cin.getline(a,2);

    cin.getline(st[s].major,30);

    cout<<"年级:\t";

    cin.getline(st[s].grade,10);

    cout<<"突出事迹:\t";

    cin.getline(st[s].achievement,200);//提名即为投一票，当前元素加一

    st[s].number=1;//提名即为投一票

    count++;

}



int votesystem::vote(char*name)      //投票，纪录已存在时调用search函数

{

    int s;

    int f;

    f=search(name,s);//定位

    if(f) {st[s].number++; return 1;}//投票成功

    else return 0;//投票失败

}



void votesystem::display()           //显示哈希表

{

    for(int i=0;i<size;i++)

        if(st[i].name[0]!='\0')

            cout<<st[i].num<<' '<<st[i].name<<' '<<st[i].grade<<"年级"<<' '<<st[i].major<<' '

            <<st[i].Class<<"班"<<' '<<st[i].number<<"票"<<' '<<st[i].achievement<<endl;

}



void votesystem::showvote(int k)      //按哈希表下标显示票数

{

    cout<<"现得票数:"<<st[k].number;

}



void votesystem::showrank()            //显示排行榜

{

    int k;

    int a[11];    //定义一个数组存放前十名在哈希表中的下标

    for(int i=0;i<10;i++) a[i]=-1;

    for(int i=0;i<size;i++)  //遍历哈希表

    {

        if(st[i].name[0]!='\0')

        {

            for( k=9;k>=0;k--)//利用插入法进行排序

            {

                if(a[k]>-1)

                {

                    if(st[a[k]].number<st[i].number)

                        a[k+1]=a[k];

                    else break;

                }

            }

            a[k+1]=i;

        }

    }

    cout<<"   学号          姓名       得票数"<<endl;

    for(int i=0;i<10&&a[i]>-1;i++){

        cout<<left<<setw(15)<<st[a[i]].num<<setw(15)<<st[a[i]].name<<setw(15)<<st[a[i]].number<<endl;

    }

        

}



int main()

{

    int choose=-1,k=-1;

    char name[40];

    votesystem L;

    L.InitHashTable(50);

    while(choose!=5)//不是选择 5 的情况下继续运行， 否则退出

    {

        cout<<"****************************\n";

        cout<<" 校园十大优秀青年评比系统\n";

        cout<<"1--选手信息\n";

        cout<<"2--选手得票\n";

        cout<<"3--投票\n";

        cout<<"4--前十排行榜单\n";

        cout<<"5--退出投票系统\n";

        cout<<"****************************\n";

        cout<<"感谢使用本系统!\n";

        cout<<"请选择操作";

        cin>>choose;

        switch(choose)

        {

                char a[2];

            case 1:

                L.display();break;

            case 2:

                cout<<"请输入选手姓名的拼音(如:yjd):"<<endl;

                cin.getline(a,2);

                cin.getline(name,40);

                int f;

                f=L.search(name,k);

                if(f) L.showvote(k);

                cout<<endl;

                //else cout<<"无此纪录!\n";

                break;

            case 3:

                cout<<"请输入选手姓名拼音(如:yjd)"<<endl;

                cin.getline(a,2);

                cin.getline(name,40);

                f=L.search(name,k);

                if(f) {L.vote(name);cout<<"投票成功\n";}

                else

                {

                    cout<<"无纪录!\n";

                    cout<<"1--提名该学生\n"

                    <<"2--返回系统界面\n"

                    <<"请选择操作:";

                    int t;

                    cin>>t;

                    if(t==1)

                    {

                        L.insert(name);

                        cout<<"选手提名成功\n";

                    }

                }break;

            case 4:L.showrank();break;

            case 5:cout<<"投票系统已关闭!\n";break;

            default:

                cout<<"操作无效，请重新选择!\n"; break;

        }

        

    }

    

    return 0;

}



