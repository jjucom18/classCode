
// bookManagement.cpp : 定义控制台应用程序的入口点。

//

 

#include "stdafx.h"

#include "bookManagement.h"

 

int main()

{

	while(1)

	{

		cout<<"\n图书管理系统\n";

		cout<选择功能:";

		int f;

		cin>>f;

		switch(f)

		{

		case 1:scan();

               break;

		case 2:insert(); 

               break;

		case 3:borrow();

               break;

		case 4:give_back();

               break;

		case 5:record();

			   break;

	    case 6:exit(1);

		default:cout<<"输入有误，请重新输入"<

#include // 包含setw设置输出格式

#include 

using namespace std;





class Information

{   

public:

	int num;      //存放书的书号

	string name;   //书名

	string aut;    //作者

	int stock;      //库存



	Information(){}

	Information (int num,string name,string aut,int stock)

	{

		this->num=num;

		this->name=name;

		this->aut=aut;

		this->stock=stock;

	}

    friend ostream& operator<<(ostream& out,Information &book);



};



ostream& operator<<(ostream& out,Information &book)

{

	out<

#include // 包含setw设置输出格式

#include 

using namespace std;





class Record

{   

public:

	int stu_Num;        //存放学生的借书号

	int book_Num;       //存放借阅的书号

	string book_Name;   //存放书名

	string T;



	Record(){}

	Record (int stu_Num,int book_Num,string book_Name,string T)

	{

		this->stu_Num=stu_Num;

		this->book_Num=book_Num;

		this->book_Name=book_Name;

		this->T=T;

	}

    friend ostream& operator<<(ostream& out,Record &stu);

	Record & operator=(Record &stu)

	{

		this->book_Num=stu.book_Num;

		this->stu_Num=stu.stu_Num;

		this->book_Name=stu.book_Name;

		this->T=T;

		return *this;

	}



};



ostream& operator<<(ostream& out,Record &stu)

{

	out<

using namespace std;

#include





template

class SeqList

{

private:

	void init(T values[], int n);         //初始化顺序表





public:

	T *element;                            //动态数组存储顺序表的数据元素

	int length;                            //顺序表的数组容量

	int n;                                 //顺序表元素个数



	SeqList(int length=40);               //构造空表，length指定容量

	SeqList(int length, T x);             //构造顺序表，length个元素值为x

	SeqList(T values[], int n);           //构造顺序表，由values数组提供元素

	~SeqList();                           //析构函数



	T get(int i);

	T& operator[](int i);

	bool empty();                         //判断顺序表是否为空

	int count();                          //求元素个数

	void insert(int i, T x);              //插入x作为第i个元素

	virtual void insert(T x);

	T remove(int i);                      //删除第i个元素并返回其值

	void removeALL();                     //删除所有元素

	virtual int search(T key, int start = 0);//从start位置开始查找key



	friend ostream& operator<<<>(ostream&,SeqList&);      //重载输出流，输出所有元素







};



//seqlist的构造与析构

template

SeqList::SeqList(int length)            //构造一个空表

{

	this->element=new T[length];         //若length<0，c++停止运行

	this->length=length;

	this->n = 0;

}



template

SeqList::SeqList(int length, T x)       //构造一个顺序表，且表内所有元素相同

{

	this->element=new T[length];

	this->length=this->n = length;

	for (int i=0;ilength;i++)

		this->element[i] = x;

}



template

SeqList::SeqList(T values[], int n)       //构造顺序表，由values数组提供元素，n指定元素个数

{

	this->init(values, n);

}



template

void SeqList::init(T values[], int n)      //初始化顺序表

{

	this->length=n*2;

	this->element=new T[this->length];

	this->n=n;

	for (int i=0;ielement[i]=values[i];

}



template

SeqList::~SeqList()

{

	delete[]this->element;

}



template

bool SeqList::empty()                     //判断是否为空，若空返回true

{

	return this->n == 0;

}



template

int SeqList::count()

{

	return this->n;

}



template

T SeqList::get(int i)

{

	T old=this->element[i];

	return old;

}



template  

void SeqList::insert(int i, T x)         //在i位置插入X，并进行容错处理

{

	if(i<0)

		i=0;

	if(i>this->n)

		i=this->n;

	T *temp=this->element;

	if(this->n==this->length)

	{

		this->length*=2;

		this->element=new T[this->length];

		for(int j=0;jelement[j]=temp[j];

	}

	for(int j=this->n-1;j>=i;j--)

		this->element[j+1]=temp[j];

	if(temp!= this->element)

		delete[] temp;

	this->element[i]=x;

	this->n++;



}



template

void SeqList::insert(T x)

{

	insert(this->n, x);

}



template

int SeqList::search(T key,int start)

{

	for (int i=start; in; i++)

		if(this->element[i] == key)

			return i;

	return -1;

}



template

T& SeqList::operator[](int i)

{

	if (i>=0&&in)

		return this->element[i];

	throw out_of_range("i超出范围");

}



template

T SeqList::remove(int i)

{

	if (this->n>0&&i>=0&&ielement[i];

		for (int j=i;jn;j++)

			this->element[j]=element[j+1];

		this->n--;

		return old;

	}

	throw out_of_range("指定参数i超出范围！");           //抛出异常

}



template

void SeqList::removeALL()

{

	this->n=0;

}



template

ostream& operator<<<>(ostream& out,SeqList&list)

{

	out<<"(";

	if (list.n > 0)

		out<

#include // 包含setw设置输出格式

#include 

using namespace std;





class Date

{   

public:

	int Year;        

	int Month;       

	int Day;





	Date(){}

	Date(int Year,int Month,int Day)

	{

		this->Year=Year;

		this->Month=Month;

		this->Day=Day;

	}



    friend ostream& operator<<(ostream& out,Date &d);

	friend istream& operator>>(istream& out,Date &d);

};



ostream& operator<<(ostream& out,Date &d)

{

	out<>(istream& in,Date &d)

{

	in>>d.Year>>d.Month>>d.Day;

	return in;

}

