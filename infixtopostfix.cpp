#include<iostream>
#include<string>
#include<stack>
using namespace std;

int precedence(char c)
{
	if(c=='^')
	return 3;
	else if(c=='/'||c=='*')
	return 2;
	else if(c=='+'||c=='-')
	return 1;
	else
	return 0;
}
string infixtopostfix(string s)
{
  stack<char>st;
  	string result;
  	for(int i=0;i<s.length();i++)
  	{
  		if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9'){
  			result+=s[i];
		  }
		 else if(s[i]=='['|| s[i]=='('|| s[i]=='{')
		{
			st.push(s[i]);
		}
		else if(s[i]==']'|| s[i]==')'|| s[i]=='}')
		{
			while(!st.empty()&&!(st.top()=='('||st.top()=='{'||st.top()=='['))
			{
				result+=st.top();
				st.pop();
			}
			if(!st.empty())
			{
				st.pop();
			}	
	}
	    
			else {
			if(!st.empty()&&(precedence(s[i])<=precedence(st.top())))
			{
				result+=st.top();
				st.pop();
			}
			st.push(s[i]);
	}
		
		}

		while(!st.empty())
		{
			result+=st.top();
			st.pop();
		}
		return result;
}
int main()
{
	string expr;
	cout<<"provide an expession:"<<endl;
	getline(cin,expr);
	cout<<endl;
	cout<<"postfix :"<<infixtopostfix(expr)<<endl;
	return 0;
}
