#include<iostream>
using namespace std;
int main()
{
	char a[20];
	gets (a);
	int i,j;
	for (i=0;a[i]!='\0';i++)
	{
		if (a[i]>=65 && a[i]<=90)
		{
			j=a[i];
			j=j+32;
			a[i]=j;
			cout<<a[i];
		}
		else
		{
			cout<<a[i];
		}
	}
}
