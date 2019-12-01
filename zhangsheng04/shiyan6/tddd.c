#include<iostream>

#include"BTNode.h"
#include<stdlib.h>
#include<vector> 
#include"Hufm.h"
#include<queue>





using namespace std;
template<class T>
void Level(const BTNode<T>* t)
{
    if(t==NULL)
    {
        return;
    }
    queue<const BTNode<T>*> q;

    q.push(t);
    while(!q.empty())
    {
        t=q.front();
        cout<<q.front()->data<<" ";
        q.pop();


        if(t->left!=NULL)
            q.push(t->left);
        if(t->right!=NULL)
            q.push(t->right);
    }
}
template<class T>
void code(BTNode<T>* t,T* arr,int n)//**编码算法**
{
	int now=0;
	
	for(int i=0;i<n;i++)
	{
		now=0;
		char a[100];
		tocode(t,a,now,arr[i]);
	}

	
	
}

template<class T>
void tocode(BTNode<T>* t,char* a,int& n,T& node)
{


		if(n>=0&&node==t->data)
		{
			for(int i=0;i<n;i++)
			{
				cout<<a[i];
			}
			cout<<endl;

		}

		
	
	if(t->left)
	{
		
		a[n]='0';
		n++;
		tocode(t->left,a,n,node);
	}
	if(t->right)
	{
		
		a[n]='1';
		n++;
		tocode(t->right,a,n,node);
	}
	n--;//到了错误的叶子节点，返回枝干 
	
}
int main()
{
	cout<<"哈夫曼编码";
	int a[]={12,40,15,8,25};
	BTNode<int>* root;
	root=MakeHufm(a,5);
	Level(root);
	cout<<endl;
	code(root,a,5);
	return 0;
}

#ifndef HUFM_H
#define HUFM_H

#include<iostream>

using namespace std;

template<class T>
struct HufmNode
{
	BTNode<T> *t;
	int operator <(const HufmNode& h)
	{
		return (t->data<h.t->data);
	}
	int operator <=(const HufmNode& h)
	{
		return (t->data<=h->data);
	}
};
template<class T>
class Heap
{
	vector<T> vec;
	int size;
	void BuildHeap(void);
	void PercolateDown(int h);
	void PercolateUp();
public:
	explicit Heap(int max=100):vec(max),size(0){
	}
	explicit Heap(const vector<T>& vt):vec(vt.size()+10),size(vt.size())
	{
			for(int i=0;i<size;i++)
	{
		vec[i]=vt[i];
	}
	BuildHeap(); 
	}

	bool Empty(void)const{return (size==0);}
	int Size()
	{
		return size;
	} 
	void Insert(const T& item);
	const T& Top(void)const
	{
		return vec[0];
	}
	void DeleteMin(void);
	void DeleteMin(T& item);
	

};
template<class T>
void Heap<T>::Insert(const T& item)
{
	if(size==vec.size())
	{
		vec.resize(size*2);
	}
	vec[size]=item;
	size++;
	PercolateUp();
}
template<class T>
void Heap<T>::PercolateUp()
{
	int c=size-1;
	int p=(c-1)/2;
	T temp=vec[c];
	while(c>0)
	{
		if(temp<vec[p])
		{
			vec[c]=vec[p];
			c=p;
			p=(c-1)/2;
	    }else
	    {
	    	break;
	    }
	
	}
	vec[c]=temp;
}

template<class T>
void Heap<T>::DeleteMin(void)
{
	if(size==0)
	{
		cout<<"MInHeap is Empty";
		exit(1);
	}
	size--;
	vec[0]=vec[size];
	PercolateDown(0);
}
template<class T>
void Heap<T>::DeleteMin(T& item)
{
	if(size==0)
	{
		cout<<"MInHeap is Empty";
		exit(1);
	}
	item=vec[0];
	size--;
	vec[0]=vec[size];
	PercolateDown(0);
}
template<class T>
void Heap<T>::PercolateDown(int h)
{
	
	int p=h;
	int c=2*h+1;
	T temp=vec[h];
	while(c<size)
	{
		if(vec[c+1]<vec[c]&&(c+1)<size)
		c++;
		if(vec[c]<temp)
		{
			vec[p]=vec[c];
			p=c;
			c=2*p+1;
		}else{
			break;
		}
	}
	vec[p]=temp;

}
/*template<class T>
void Heap<T>::Heap(const vector<T>& vt):vec(vt.size()+10),size(vt.size())
{

	for(int i=0;i<size;i++)
	{
		vec[i]=vt[i];
	}
	BuildHeap(); 
}*/
template<class T>
void Heap<T>::BuildHeap(void)
{
	for(int i=size/2-1;i>=0;i--)
	PercolateDown(i);
}

template<class T>
BTNode<T>* MakeHufm(const T* pa,int n)
{
	HufmNode<T> hf;
	BTNode<T> *t,*left,*right;
	Heap<HufmNode<T> > H(n);
	for(int i=0;i<n;i++)
	{
		t=GetBTNode(pa[i]);
		hf.t=t;
		H.Insert(hf);
	}
	for(int i=1;i<n;i++)
	{
		H.DeleteMin(hf);
		left=hf.t;
		H.DeleteMin(hf);
		right=hf.t;
		t=GetBTNode(right->data+left->data,left,right);
		hf.t=t;
		H.Insert(hf);
	}
	H.DeleteMin(hf);
	t=hf.t;
	return t;
	 
}
#endif
