#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int r,c;
	cout<<"enter number of rows:";
	cin>>r;
	cout<<"enter number of columns:";
	cin>>c;
	int a[r][c];
	cout<<"enter elements of matrix:";
	int i,j;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
	for (i=0;i<c;i++)
	{
		for (j=0;j<r;j++)
		{
			cout<<a[j][i]<<" ";
		}
		cout<<"\n";
	}	
}
