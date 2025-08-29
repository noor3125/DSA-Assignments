#include<iostream>
using namespace std;
struct diagonal
{
	int a[10];
	int n;
};
void create(struct diagonal *d1)
{
	int i,j,x;
	for (i=0;i<d1->n;i++)
	{
		for (j=0;j<d1->n;j++)
		{
			if (i==j)
			{
				cin>>d1->a[i];
			}
			else
			{
				cin>>x;
			}
		}
	}
}
void display(struct diagonal d1)
{
	int i,j;
	for (i=0;i<d1.n;i++)
	{
		for (j=0;j<d1.n;j++)
		{
			if (i==j)
			{
				cout<<d1.a[i]<<" ";
			}
			else
			{
				cout<<"0 ";
			}
		}
		cout<<"\n";
	}
}
int main()
{
	struct diagonal d;
	cout<<"enter order of matrix:";
	cin>>d.n;
	cout<<"enter non-zero elements:";
	create(&d);
	display(d);
}
