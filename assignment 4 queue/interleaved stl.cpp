#include<bits/stdc++.h>
using namespace std;
void interleave(queue<int>&q){
	queue<int> q1,q2;
	
	
	int n;
	int i;
	if(q.size()%2!=0)
	{
		cout<<"Enter a valid size interleaving between even sized queue possible!!"<<endl;
		return;
	}
	n=q.size();
	for( i=0;i<n/2;i++)
	{
		q1.push(q.front());
		q.pop();
	}
	for(i=0;i<n/2;i++)
	{
		q2.push(q.front());
		q.pop();
	}
	while(!q1.empty())
	{
		q.push(q1.front());
		q1.pop();
		q.push(q2.front());
		q2.pop();
	}
	
}
int main()
{
	queue<int>q;
	int n;
	cout<<"size of queue"<<endl;
	cin>>n;
	int i,a;
	for(i=0;i<n;i++)
		{
			cin>>a;
			q.push(a);
		}
	interleave(q);
	n=q.size();
	for(i=0;i<n;i++)
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}
