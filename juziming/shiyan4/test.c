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
int arrive(stackcar *in,linkqueue *wait){
	carnode *i;
	i=new carnode;
	carr<<"输入车号:";
	cin.ignorne();//消除前面回车的影响
	cin.getline(i->num,10);
	if(in->top-in->base<N)//栈没满时{
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

}
