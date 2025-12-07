#include<iostream>
using namespace std;
void maxheapify(int arr[],int i,int n)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n&&arr[left]>arr[largest])
	{
		largest=left;
	}
	if(right<n&&arr[right]>arr[largest])
	{
		largest=right;
	}
	if(largest!=i)
	{
	    swap(arr[i],arr[largest]);
	    maxheapify(arr,largest,n);
	}
}
void minheapify(int arr[],int i,int n)
{
	int smallest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n&&arr[left]<arr[smallest])
	{
		smallest=left;
	}
	if(right<n&&arr[right]<arr[smallest])
	{
		smallest=right;
	}
	if(smallest!=i)
	{
	    swap(arr[i],arr[smallest]);
	    minheapify(arr,smallest,n);
	}
}
void heapsortincre(int arr[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		maxheapify(arr,i,n);
	}
	for(i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		maxheapify(arr,0,i);
	}
}
void heapsortdecre(int arr[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		minheapify(arr,i,n);
	}
	for(i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		minheapify(arr,0,i);
	}
}
int printarr(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int arr[]={4,8,6,42,95,31,3,24,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Original Array:";
	printarr(arr,n);
	
	heapsortincre(arr,n);
	cout<<"heapsort increasing order:";
	printarr(arr,n);
	
	int arr2[]={4,8,6,42,95,31,3,24,1};	
	heapsortdecre(arr2,n);
	cout<<"heapsort decreasing order:";
	printarr(arr2,n);
	return 0;
}
