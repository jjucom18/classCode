#ifndef parking_h
#define parking_h
#include<stdio.h>
#include<stdlib.h>

const int maxStack=3;//最多元素个数
enum Error_code
{
	success, underflow, overflow
} ;

template <class Stack_entry>
class Stack
{
	private:
	unsigned int count;//记录栈内元素个数
    Stack_entry entry[maxStack] ;//数组实现
	public:
	 Stack() 
     {
         count=0;
     } 
     bool empty()  const
     {

         if(count==0)  return true;
         else return false;
     } 
     bool full()  const
     {
         if(count==maxStack)  return true;
         else return false;
     } 
     Error_code pop() 
     {
         if(count==0)  return underflow;
         else
		 {
			 --count;
			 return success;
		 } 
	 } 
	 Error_code top(Stack_entry &item)  const//取栈顶元素
	{
		 if(count==0)  return underflow;
		 else
		{
			 item=entry[count-1] ;
			 return success;
        } 
	}
	Error_code push(Stack_entry &item) 
	{
		if(count >= maxStack)  return overflow;
		else
		{
			entry[count++] =item;
			item.position = count;//返回停车位置，从1开始记
			return success;
		} 
	} 
}
template<class Node_entry>//链队列结点定义（单链表）
struct Node
{
	//数据成员
	Node_entry entry;
	Node<Node_entry> *next;
	//构造函数
	Node() {} 
	Node(Node_entry new_entry, Node<Node_entry> *new_next=NULL) 
	:entry(new_entry) , next(new_next) {}
};
template<class Queue_entry>
class Queue
{
public:
	unsigned int count;//结点个数
	Node<Queue_entry> *front, *rear;//队列头、尾结点
	Queue() //构造函数
	{
		count=0;
		front=rear=NULL;
	} 
	bool empty()  const
	{
	if(count==0)  return true;
	else return false;
	} 
	Error_code serve() 
	{
	if(count==0)  return underflow;
	else
		{
			Node<Queue_entry> *out=front;
			front=front->next;
			if(front==NULL)  rear=NULL;
			delete out;
			count--;
			return success;
		} 
	} 
	Error_code retrieve(Queue_entry &item)  const//取队列头元素
	{
		if(count==0)  return underflow;
		else
		{
			item=front->entry;//解引用
			return success;
		} 
	}
	Error_code append(const Queue_entry &item) 
	{
		Node<Queue_entry> *in=new Node<Queue_entry>(item) ;
		if(in==NULL)  return overflow;
		if (count == 0) 
		{
			front=rear=in;
		}     
		else
		{
			rear->next=in;
			rear=in;;
		} 
		count++;
		return success;
	} 
} 
