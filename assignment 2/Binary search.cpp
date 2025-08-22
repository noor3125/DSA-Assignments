#include<iostream>
using namespace std;
void bin_search (int n,int a[],int x)
{
	int l=0;
	int h=n-1;
	int m;
	while(l<=h)
	{
		m=(l+h)/2;
		if(x==a[m])
		{
			cout<<"element found at "<<m<<" index";
			return;
		}
		else if (x>a[m])
		{
			l=m+1;
		}
		else
		{
			h=m-1;
		}
	}
	if (l>h)
	{
		cout<<"element not found";
	}
}
int main()
{
	int n;
	cout<<"enter size of array:";
	cin>>n;
	int arr[n];
	cout<<"enter elements of array:";
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int key;
	cout<<"enter element to search in array:";
	cin>>key;
	bin_search(n,arr,key);
}
