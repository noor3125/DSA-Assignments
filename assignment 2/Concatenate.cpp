#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[20];
	gets(a);
	char b[20];
	gets(b);
	int i;
	for (i=0;a[i]!='\0';i++)
	{
	}
	int t=i;
	for (i=0;b[i]!='\0';i++)
	{
		a[t+i]=b[i];
	}
	cout<<a;
}
