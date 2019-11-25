void parkingmanagement::arrival(carstack&cs,carqueue &cq,int cnum,double ctime)
	int pos;
	if(!(cs.full()))
{
	int fl(0),i;
	for(i=0;i<=cs.top;i++)
	{
		if(cs.s[i].number==cnum)
		{
			fl=1;
			break;
		}
	}
	if(fl==1)
		cout<<"输入错误！请重新输入！如果到达的车的车牌号!=栈内已有车牌的车牌号"<<endl;
	else
	{
		pos=pushstack(cs,cnum,ctime);
		cout<<"该停车场还有空位，请到"
			<<pos<<"号车位进行泊车"<<endl;
		cout<<endl;
	}
}
else
{
	pos=pushqueue(cq,cnum,ctime);
	cout<<"该停车场已满，请将车停到便道"
		<<pos<<"号车位上"<<endl;
	cout<<endl;
}
int parkingmanagement::pushstack(carstack &cs,int cnum,double ctime)
{
	if(cs.top==Max-1)
	{
		cout<<"该停车场已满!"<<endl;
		return Max;
	}
	else
	{
		cs.top++;
		(cs.s[cs.top]).number=cnum;
		(cs.s[cs.top]).time=ctime;
		return(cs.top+1);
	}
}
void parkingmangement::leave(carstack &cs,carqueue &cp,int cnum,double ctime)
{
	int i,flag(0),pstack,count(1),outcarnum;
	double hour;
	car*p;
	for(i=0;i<=cs.top;i++)
		if((cs.s[i]).number==cnum)
		{
			flag=1;
			break;
		}
	if(flag)
	{
		popstack(cs,cnum);
		hour=ctime-popstacktime;
		outcarnum=popqueue(cq);/
		pastack=pushstack(cs,outcarnum,ctime);
		cout<<"该车在本停车场内停留时间为"
			<<hour<<"分钟，应付金额"<<hour*
			(price/60)<<"endl;
		cs.top--;
	}
	else
	{
		p=cq.front;
		while(p!=NULL)
		{
			count++;
			p=p->next;
			if(p->number==cnum)
			{
				deletequeue(cq,count);
				if(count>Max)
				{
					cout<<"您的车在便道上位置为"
						<<count<<"号车位，请自行驶离，无需付费！"<<endl;
					break;
				}
			}
		}
		if(p==NULL)cout<<"您的车不在本停车场内，或输入有误，请重新输入!"<<endle;
	}
}

