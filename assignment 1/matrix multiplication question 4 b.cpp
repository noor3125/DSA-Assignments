#include<iostream>
using namespace std;
int main()
{
	int m,n,p,q;
	cout<<"enter rows in 1st matrix:";
	cin>>m;
	cout<<"enter columns in 1st matrix:";
	cin>>n;
	cout<<"enter rows in 2nd matrix:";
	cin>>p;
	cout<<"enter columns in 2nd matrix:";
	cin>>q;
	int a[m][n],b[p][q];
	if (n==p)
	{
		int s[m][q];
		int i,j;
		int k=0;
		int l=0;
		cout<<"enter elements of matrix 1:";
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		cout<<"enter elements of matrix 2:";
		for (i=0;i<p;i++)
		{
			for (j=0;j<q;j++)
			{
				cin>>b[i][j];
			}
		}
		for (i=0;i<m;i++)
		{
			for (j=0;j<q;j++)
			{
				s[i][j]=0;
				for (k=0;k<n;k++)
				{
					s[i][j]=s[i][j]+a[i][k]*b[k][j];
				}
			}
		}
		for (i=0;i<m;i++)
		{
			for (j=0;j<q;j++)
			{
				cout<<s[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	else
	{
		cout<<"invalid dimensions of matrix!";
	}
}
