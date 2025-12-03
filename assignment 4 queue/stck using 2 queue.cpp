#include<iostream>
#include<queue>
using namespace std;
class stck{
	queue<int>q1,q2;
	public:
		void push(int x){
		q1.push(x);
	    }
	    void pop()
	    {
	    	if(q1.empty())
	    	{
	    		return;
			}
			while(q1.size()!=1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			
			q1.pop();
			swap(q1,q2);
		}
		int top(){
			if(q1.empty())
	    	{
	    		return -1;
			}
			while(q1.size()!=1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			
			int temp=q1.front();
			q1.pop();
			q2.push(temp);
			swap(q1,q2);
			return temp;
		}
		
		int size()
		{
			return q1.size();
		}
};
int main()
{
	stck s;
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
