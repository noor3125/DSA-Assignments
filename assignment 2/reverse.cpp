#include<iostream>
using namespace std;
int main()
{
	char a[20];
	gets(a);
	char b[20];
	int i,k=0;
	for (i=0;a[i]!='\0';i++)
	{
	}
	for (int j=i-1;j>=0;j--)
	{
		b[k]=a[j];
		k++;
	}
	b[k]='\0';
	for (i=0;b[i]!='\0';i++)
	{ 
		cout<<b[i];
	}
}
