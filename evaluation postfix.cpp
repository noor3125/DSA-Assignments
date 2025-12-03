#include<iostream>
#include<string>
#include<stack>
#include<math.h>
using namespace std;

int postfixeval(string s)
{
	int op1,op2;
	stack<int>st;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			st.push(s[i]-'0');
		}
		else{
			op2=st.top();
			st.pop();
			op1=st.top();
			st.pop();
			
			switch(s[i]){
				case '+': st.push(op1+op2);
				break;
				case '-': st.push(op1-op2);
				break;
				case '*': st.push(op1*op2);
				break;
				case '/': st.push(op1/op2);
				break;
				case '^': st.push(pow(op1,op2));
				break;
				default: cout<<"Invalid operator!"<<endl;
			}
		}
	}
	return st.top();
}
int main(){
	string exp;
	cout<<"provide postfix expression: "<<endl;
	getline(cin,exp);
	cout<<"evaluated expression: "<<postfixeval(exp)<<endl;
	return 0;
}
