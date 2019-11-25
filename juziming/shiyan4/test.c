#include<iostream.h> 
#include<stdlib.h> 
#include<string.h> 
#define N 2 
#define  price 0.1 //时间
struct time{
	int hour;
	int min;
};//车辆信息
struct carnode{
	char num[10];
	time reach;
	time leave;
};//模拟车站 栈
struct stackcar{
	 carnode *base; 
	 carnode *top; 
	 int stacksize; 
};
struct queuenode{
	carnode *data;
	queuenode *next;
};//模拟通道
struct liankqueue{
	queuenode *frond;
	queuenode *rear;
};//便道空否
int queueemty(linkqueue q)
{
	if(q.frond==q.rear)
		return 1;
	else return 0;
}//初始化栈
viod initstack(stackcar *s)
{
	s->base=new carnode;
	if(!s->base) exit(0);//分配失败 退出
	s->top=s->base;
	s->stacksize=N;
}//进出栈
int push(stackcar *s,carnode *e)
{
	if(s->top-s->base==s->stacksize)
		return 0;
	else
		*s->top++=*e;
        return 1;
}
int pop(stackcar *s,carnode *e)
{
	if(s->top==s->base)return 0;/*=VS==?!小错就是大错*/
	else *e=*--s->top;return 1;
}
//栈判空函数
int stackempety(stackcar s){
	if(s.base==s.top) return 1;
	else return 0;
}//初始化便道
int initqueue(linkqueue *q)
{
	q->frond=q->rear=new queuenode;
	if(!q->rear)exit(0);
	q->frond->next=NULL;
	return 1;
}//进出便道
int enqueue(linkqueue *q,carnode *e){
	queuenode *p; 
		p=new queuenode; 
		if(!p)exit(0); 
		p->data=e; 
		p->next=0;
	    q->rear->next=p;
	   return 1;
}
int dequeue(linkqueue *q,carnode *e){
	queuenode *p; 
		if(q->frond==q->rear)return 0; 
		p=q->frond->next;
	    e=p->data;
        q->frond->next=p->next;
		if(q->rear==p)q-rear=q->frond;
		delete(p)return 1;
}//车辆进入时处理
int arrive(stackcar *in,linkqueue *wait) 
{
	carnode *i;
	i=new carnode;
	carr<<"输入车号:";
	cin.ignorne();//消除前面回车的影响
	cin.getline(i->num,10);
	if(in->top-in->base<N)//栈没满时
	{
		cerr<<"车到达的时间(00:00):小时为";
	cin>>i->reach.hour;cout<<"t\t   分钟为";
	cin>>i->reach.min;
	push(in,i);cerr<<"a????"; 
	//system("cls");
    cout<<"\t\t车辆已成功进入停车场"<<endl<<endl; 
	cout<<"\t\t车号为"<<i->num<<"的车进入\t";
cout<<"  到  达  的  时  间  :  "<<i->reach.hour<<":"<<i->reach.min<<endl<<endl:
	return 1;
}
else
{
queuenode *w;
w=new queuenode;
w->data=i;
w->next=NULL;
wait->rear->next=w;
wait->rear=w;
cout<<"\t\t 抱歉 车位已满 请在便道等待"<<endl;
return 1;
}
return 0;
} //车辆离开时处理函数
int flag=0,a1,a2,b1,b2;double money;
carnode *p,*t;
queuenode *q;
p=new carnode;
cout<<"请输入车牌号：";
cin.ignore();
cin.getline(p->num,10);
while(!stackempty(*in))
{
	t=new carnode;
	pop(in,t);
	if(strcmp(p->num,t->num)==0){
		cout<<"输出离开的时间 (00:00)";
		cin>>p->leave.hour,cin>>p->leave.min;
		cout<<"车牌号为"<<p->num<<"的车离开"<<endl;
		a1=p->leave.hour;a2=t->reach.hour;
		b1=p->leave.min;b2=t->reach.min;
		if(b1>=b2)money=((a1-a2+24)%24*60+(b1-b2)%60)*price;
		else money=((a1-a2+23)%24*60+(b1-b2+60)*60)*price;
		cout<<"车到达的时间:"<<t->reach.hour<<":"<<t->reach.min<<endl;
		cout<<"车离开的时间:"<<p->leave.hour<<":"<<p->leave.min<<endl;
		cout<<"费用为:"<<money<<endl;
		flag=1;delete(t);
        break;
	}else push(temp,t);
}
if(flag==0)
	cout<<"没有此车"<<endl;
	while(!stackempty(*temp)){
		pop(temp,p);
		push(in,p);
	}
delete(p);
if(flag&&wait->frond!=wait->rear){
	q=new queuenode;
	q=wait->frond->next;
	t=q->data; 
	if(p)
    { push(in,t);
		cout<<"车号为"<<t->num<<"的车进入时间是:";
		cin>>t->reach.hour;cout<<"\t\t  分钟为";
		cin>>t->reach.min;}
wait->frond->next=q->next;
wait->rear=wait->rear;
if(q==wait->rear){
	wait->rear=wait->frond;
	delete(q);
}
return 1;
}//输入打印信息
void print(stackcar *in,stackcar *temp,linkqueue *wait){
	char c;int count=1;
	carnode *p,*t;
	queuenode *q;
    p=new carnode;t new carnode;
	q=new queuenode;
	cout<<"\t\t 1.打印便道的车辆数"<<endl;
	cout<<"\t\t 2.打印dy停车场的车辆数"<<endl;
	cout<<"\t\t 3.退出打印"<<endl;
	cout<<"\t\t 4.请输入你的选择";
	cin>>c;
	if(c=='1'){
		q=wait->frond->next;
		if(wait->frond!=wait->rear)
			while(q){
				p=q->data;
				cout<<"第"<<count<<"辆车s的车牌号是"<<p->num<<endl;
				q=q->next;
				count++;
			}
		else
			cout<<"n便道是空的"<<endl;
	}
	if(c=='2'){
		count=0;
		while(!stackempty(*in)){
			pop(in,t);
			push(temp,t);
		}while(!stackempty(*temp)){
			pop(temp,t);
			cout<<"第"<<++count<<"辆车的车牌是"<<t->num<<endl;
			count++;
			push(in,t);
		}if(count==0)
		cout<<"车站里没有车"<<endl;
	}
}
void menu(){
	cout<<"\t\t************************"<<endl;
	cout<<"\t\t************************"<<endl;
	cout<<"\t\t\t 1:车到达"<<endl;
	cout<<"\t\t\t 2:车离开"<<endl;
	cout<<"\t\t\t 3:打印信息"<<endl;
	cout<<"\t\t\t 4;退出"<<endl;
	cout<<"\t\t************************"<<endl;
	cout<<"\t\t************************"<<endl;
	cout<<"请选择:";
}
void main()
{
	char c;
	stackcar in,t;
	linkqueue road;
	initstack(&in);initstack(&t);
	cout<<endl;
	cout<<"\t\t\t模拟停车场系统"<<endl<<endl;
	while(1){
		menu();
		cin>>c;
		switch(c){
			case'1':arrive(&in,&road);break;
			case'2':leave(&in,&t,&road);break;
			case'3':print(&in,&t,&road);break;
			default;exit(0);		
		};
	}
}
