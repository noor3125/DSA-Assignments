#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter the number of elements:";
	cin>>n;
	int A[n];
	int i,j,k;
	for(i=0;i<=n-1;i++)
    {
    	cin>>A[i];
	}
	for(i=0;i<=n-1;i++)
	{
		for(j=i+1;j<=n-1;j++)
		{
			if(A[i]==A[j])
			{
				for(k=j;k<=n-1;k++)
				{
					A[k]==A[k+1];
				}
				j--;
				n--;
			}
		}
	}
	for(i=0;i<=n-1;i++)
    {
    	cout<<"new array"<<A[i];
	}
}
