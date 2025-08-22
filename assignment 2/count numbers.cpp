#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter size of array:";
	cin>>n;
	int a[n],i,j,l=0;
	cout<<"enter elements:";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for (i=0;i<n;i++)
	{
		if (a[i]>l)
		{
			l=a[i];
		}
	}
	int h[l+1]={0};
	for (i=0;i<n;i++)
	{
		h[a[i]]++;
	}	
	for (i=0;i<l+1;i++)
	{
		if (h[i]>0)
		{
			cout<<i<<"->"<<h[i]<<"\n";
		}
	}
}
