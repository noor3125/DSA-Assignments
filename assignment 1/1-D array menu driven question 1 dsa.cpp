#include<iostream>
#include<stdio.h>
using namespace std;
struct array
{
	int *a;
	int l;
};
void create(struct array *arr)
{
	cout<<"enter length of array:";
	cin>>arr->l;
	arr->a=new int [arr->l];
	cout<<"enter elements of array:";
	for (int i=0;i<arr->l;i++)
	{
		cin>>arr->a[i];
	}
}
void display(struct array *arr)
{
	int i;
	for (i=0;i<arr->l;i++)
	{
		cout<<arr->a[i]<<" ";
	}
	cout<<"\n";
}
void insert (struct array *arr,int index, int element)
{
	int i;
	for (i=arr->l;i>=index;i--)
	{
		arr->a[i]=arr->a[i-1];
	}
	arr->a[index-1]=element;
	arr->l++;
}
void Delete (struct array *arr,int index)
{
	int i;
	for (i=index;i<arr->l;i++)
	{
		arr->a[i-1]=arr->a[i];
	}
	arr->l--;
}
int search(struct array *arr,int element)
{
	int i;
	for (i=0;i<arr->l;i++)
	{
		if (arr->a[i]==element)
		{
			return i+1;
		}
	}
}
void remove(struct array *arr)
{
	int i,j;
	for (i=0;i<arr->l;i++)
	{
		for (j=i+1;j<arr->l;j++)
		{
			if (arr->a[i]==arr->a[j])
			{
				Delete(arr,j+1);
				i--;
			}
		}
	}
}
void swap(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
void reverse(struct array *arr)
{
	int i;
	int j=arr->l-1;
	for (i=0;i<arr->l/2;i++)
	{
		swap(arr->a[i],arr->a[j]);
		j--;
	}
}
int main()
{
	struct array a;
	int x;
	int e,p;
	while(x<8)
	{
		cout<<"press 1 for create\npress 2 for display\npress 3 for insert\npress 4 for delete\n";
		cout<<"press 5 for linear search\npress 6 to exit\n";
		cin>>x;
		switch(x)
		{
			case 1:
				create(&a);
				break;
			case 2:
				display(&a);
				break;
			case 3:
				cout<<"enter element to insert:";
				cin>>e;
				cout<<"enter position:";
				cin>>p;
				insert(&a,p,e);	
				break;
			case 4:
				cout<<"enter position to delete:";
				cin>>e;
				Delete(&a,e);	
				break;
			case 5:
				cout<<"enter element to search:";
				cin>>e;
				p=search(&a,e);
				cout<<"element found at position: "<<p<<"\n";
				break;
			case 6:
				exit(0);
			default:
			cout<<"wrong choice!!";	
		}
	}
}
