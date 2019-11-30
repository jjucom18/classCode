#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<queue>
using namespace std;

priority_queue<int,vector<int>, greater<int> > q;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		q.push(t);
	}
	
	long long sum=0; 
	while(!q.empty()){
		int not_leaf=0;
		
		if(q.size()>=2){
			//取两次最小值合成非叶节点 
			not_leaf+=q.top();
			q.pop();
			not_leaf+=q.top();
			q.pop();
			
			sum+=not_leaf;//sum(W[i]·P[l]=非叶节点权值和)
			q.push(not_leaf);	
		}
		else break;
	}
	printf("%lld",sum);
	return 0;
}
