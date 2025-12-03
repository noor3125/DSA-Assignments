#include<iostream>
using namespace std;
class stck{
	int top;
	int *arr;
	int maxlen;
	public:
		stck(int max)
		{
			maxlen=max;
			arr=new int[maxlen];
			top=-1;
		}
		 int peek()
		{
			if(arr[top]==-1)
			{
				cout<<"stack is empty";
			}
			else{
			return arr[top];
		}
		}
		bool isEmpty()
		{
			return(top == -1);
		}
		bool isfull()
		{
            cout<<"stack is full";
			return(top ==maxlen-1);
		}
		void push(int x)
		{
			if(top==maxlen-1)
			{
				cout<<"stack overflow"<<endl;
			}
			else
			{
			  top=top+1;
			  arr[top]=x;
			  cout<<"element pushed is:"<<arr[top]<<endl;	
			}
		}
			void pop()
		{
			if(top==-1)
			{
				cout<<"stack underflow"<<endl;
			}
			else
			{
				int x=0;
			  x=arr[top];
			  top=top-1;
			  cout<<"element popped is: "<<x<<endl;	
			}
		}
		void display()
		{
			int i;
			for(i=top;i>=0;--i)
			{
			    cout << arr[i] << " ";
			}
		}
};
int main()
{
	stck S(10);
	S.peek();
	S.push(4);
	S.push(3);
    S.push(2);
    S.push(6);
	S.pop();
	S.push(5);
	cout<<"current stack:"<<endl;
	S.display();
	S.push(32);
	S.push(16);
	S.push(11);
	S.push(0);
	S.push(1);
	S.push(9);
	S.push(8);
	S.pop();
	S.pop();
	S.pop();
	S.pop();
	cout<<"current stack:"<<endl;
	S.display();
	cout<<"top element:"<<S.peek()<<endl;
	S.pop();
	S.pop();
	S.pop();
	S.pop();
	S.pop();
	S.pop();
	S.pop();
return 0;
}
