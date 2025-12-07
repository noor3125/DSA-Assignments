#include<iostream>
using namespace std;
#define maxlen 100
class PriorityQueuemin{
		int heap[maxlen];
	int size;
	
	int parent(int i)
	{
		return(i-1)/2;
	}
	int left(int i)
	{
		return(i*2+1);
	}
	int right(int i)
	{
		return(i*2+2);
	}
void heapifydownmin(int i)
{
	int smallest=i;
	int l=left(i);
	int r=right(i);
	if(l<size&&heap[l]<heap[smallest])
	{
		smallest=l;
	}
	if(r<size&&heap[r]<heap[smallest])
	{
		smallest=r;
	}
	if(smallest!=i)
	{
	    swap(heap[i],heap[smallest]);
	    heapifydownmin(smallest);
	}
}
void heapifyupmin(int i)
{
	while(i!=0&&heap[parent(i)]>heap[i])
	{
		swap(heap[i],heap[parent(i)]);
		i=parent(i);
	}
}
public:
	PriorityQueuemin(){
		size=0;
	}
		int getmin()
	{
		if(size==0)
		{
			cout<<"Queue is empty."<<endl;
			return -1;
		}
		return heap[0];
	}
	int insert(int val){
		if(size==maxlen)
		{
			cout<<"Priority Queue is maxed out!!!"<<endl;
			return -1;
		}
		heap[size]=val;
		heapifyupmin(size);
		size++;
	}
		int extractmin()
	{
		if(size==0)
		{
			cout<<"Queue is empty."<<endl;
			return -1;
		}
		
	    int minval=heap[0];
		heap[0]=heap[size-1];
		size--;
		heapifydownmin(0);
		return minval;
	}
	void display()
	{
		if(size==0)
		{
			cout<<"Queue is empty."<<endl;
		}
		cout<<"Priority Queue (min heap):";
		for(int i=0;i<size;i++)
		{
			cout<<heap[i]<<" ";
		}
		cout<<endl;
	}
};
class PriorityQueue{
	int heap[maxlen];
	int size;
	
	int parent(int i)
	{
		return(i-1)/2;
	}
	int left(int i)
	{
		return(i*2+1);
	}
	int right(int i)
	{
		return(i*2+2);
	}
	void heapifydown(int i)
{
	int largest=i;
	int l=left(i);
	int r=right(i);
	if(l<size&&heap[l]>heap[largest])
	{
		largest=l;
	}
	if(r<size&&heap[r]>heap[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
	    swap(heap[i],heap[largest]);
	    heapifydown(largest);
	}
}	
void heapifyup(int i)
{
	while(i!=0&&heap[parent(i)]<heap[i])
	{
		swap(heap[i],heap[parent(i)]);
		i=parent(i);
	}
}
public:
	PriorityQueue(){
		size=0;
	}
	int getmax()
	{
		if(size==0)
		{
			cout<<"Queue is empty."<<endl;
			return -1;
		}
		return heap[0];
	}
	int getmin()
	{
		if(size==0)
		{
			cout<<"Queue is empty."<<endl;
			return -1;
		}
		return heap[0];
	}
	int insert(int val){
		if(size==maxlen)
		{
			cout<<"Priority Queue is maxed out!!!"<<endl;
			return -1;
		}
		heap[size]=val;
		heapifyup(size);
		size++;
	}
	int extractmax()
	{
		if(size==0)
		{
			cout<<"Queue is empty."<<endl;
			return -1;
		}
		
	    int maxval=heap[0];
		heap[0]=heap[size-1];
		size--;
		heapifydown(0);
		return maxval;
	}
	
	void display()
	{
		if(size==0)
		{
			cout<<"Queue is empty."<<endl;
		}
		cout<<"Priority Queue (max heap):";
		for(int i=0;i<size;i++)
		{
			cout<<heap[i]<<" ";
		}
		cout<<endl;
	}
};
int main(){
	PriorityQueue pq;
	PriorityQueuemin pq2;
	pq.insert(30);
	pq2.insert(40);
	pq.insert(60);
	pq.insert(90);
	pq2.insert(70);
	pq.insert(38);
	pq.insert(45);
	pq.insert(50);
	pq2.insert(20);
	pq.insert(32);
	pq2.insert(41);
	pq.insert(64);
	pq2.insert(92);
	pq2.insert(33);
	pq2.insert(60);
	pq2.insert(80);
	pq2.display();
	pq.display();
	cout<<"Max element:"<<pq.getmax()<<endl;
	cout<<"Min element:"<<pq2.getmin()<<endl;
	cout<<"Extracting max element:"<<pq.extractmax()<<endl;
	cout<<"Extracting min element:"<<pq2.extractmin()<<endl;
	cout<<"Max element:"<<pq.getmax()<<endl;
	cout<<"Min element:"<<pq2.getmin()<<endl;
	pq.display();
	pq2.display();
	return 0;
}
