#include<iostream>
using namespace std;
struct lowertriangular
{
	int a[15];
	int n;
};
void create(struct lowertriangular *d1)
{
	int i,j,x;
	for (i=0;i<d1->n;i++)
	{
		for (j=0;j<d1->n;j++)
		{
			if (i>=j)
			{
				cin>>d1->a[i*(i+1)/2 +j];
			}
			else
			{
				cin>>x;
			}
		}
	}
}
void display(struct lowertriangular d1)
{
	int i,j;
	for (i=0;i<d1.n;i++)
	{
		for (j=0;j<d1.n;j++)
		{
			if (i>=j)
			{
				cout<<d1.a[i*(i+1)/2 +j]<<" ";
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
	struct lowertriangular d;
	cout<<"enter order of matrix:";
	cin>>d.n;
	cout<<"enter non-zero elements:";
	create(&d);
	display(d);
}
