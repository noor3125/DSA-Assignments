#include<iostream>
#include<queue>
using namespace std;
class Stck{
	queue<int>q;
	public:
	
	void push(int x){
		q.push(x);
		
		int n=q.size();
		for(int i=0;i<n-1;i++)
		{
			q.push(q.front());
			q.pop();
		}
		
	}
	void pop(){
		if(!q.empty())
		{
			q.pop();
		}
	}
	int top()
	{
		if(q.empty())
		{
			return -1;
		}
		return q.front();
	}
	int size()
	{
		return q.size();
	}
};
int main()
{
	Stck s;
	s.push(3);
	s.push(4);
	s.push(7);
	s.push(5);
	
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout<<"size:"<<s.size()<<endl;
	
}
