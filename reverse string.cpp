#include<iostream>
#include<string>
#include<stack>
using namespace std;

void reversestring(string s)
{
	stack<string>st;
	string word;
	for(int i=s.length()-1;i>=0;i--)
	{
		word+=s[i];
	}
	st.push(word);
	
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
}
int main()
{
	string s="DATASTRUCTURES";
	reversestring(s);
	return 0;
}
