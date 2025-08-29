#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter size of array:";
	cin>>n;
	int a[n];
	cout<<"enter elements:";
	int i,j;
	for (i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int c=0;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (i<j &&a[i]>a[j])
			{
				c++;
			}
		}
	}
	cout<<c;
}
