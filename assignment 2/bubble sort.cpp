#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;	
}
void bubble_sort(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (a[i]>a[j])
			{
				swap(&a[i],&a[j]);
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		cout<<a[i]<<"\n";
	}
}
int main()
{
	int n;
	cout<<"enter size of array:";
	cin>>n;
	int a[n];
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bubble_sort(a,n);
}
