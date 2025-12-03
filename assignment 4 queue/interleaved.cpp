#include<iostream>
using namespace std;
#define maxlen 8
class Queue{
	int arr[maxlen];
    int front ,rear;
	public:
		Queue()
		{
		    front = rear=-1;
		}
		bool isEmpty(){
			return (front==-1);
		}
		bool isFull(){
			return (rear==maxlen-1);
		}
		void enqueue(int x)
		{
			if(isFull())
			{
				cout<<"queue is full elt can not be enqueued."<<endl;
				return;
			}
			else if(front==-1)
			{
				front =0;
				rear=0;
				arr[rear]=x;
			}
			else
			{
				rear++;
				arr[rear]=x;
			}
		}
		int dequeue()
		{
			int x;
			if(isEmpty()){
				cout<<"queue is empty no element left."<<endl;
				return 0;
			}
			else 
			{ 
				x=arr[front];
				//cout<<x<<" element dequeued."<<endl;
			}
			if(front==rear)
			{
				front=rear=-1;
			}
			else 
			{
				front++;
			}
			return x;
		}
		void peek()
		{
			if(isEmpty())
			{
				cout<<"Queue is empty, nothing to peek."<<endl;
			}
			else
			{
				cout<<"front element of the queue is:"<<arr[front]<<endl;
			}
		}
		void display()
		{
			if(isEmpty())
			{
				cout<<"queue is empty, nothing to display. "<<endl;
			}
			else
			{
				cout<<"queue elements:"<<endl;
				for(int i=front; i<=rear;i++)
				{
					cout<<arr[i]<<" ";
				
				}
				cout<<endl;
			}
		}
		int size(){
			if(isEmpty())
			{
				return 0;
			}
			return ((rear-front)+1);
		}
};
int main(){
	Queue q, q3,q1;
	q.enqueue(4);
	q.enqueue(7);
	q.enqueue(11);
	q.enqueue(20);
	q.enqueue(5);
	q.enqueue(9);
	   q.display();
	   int n=q.size();
	   if(n%2!=0)
	   {
	   	cout<<"Queue must be of even size.\n";
	   	return 0;
	   }
	   for(int i=0;i<n/2;i++)
	   {
		   q1.enqueue(q.dequeue()) ; //half elts from queue are fitted in queue1
	   }
	   cout<<"queue first half"<<endl; q.display();
	   cout<<"queue second half"<<endl; q1.display();
	   while(!q1.isEmpty())
	   {
	   	q3.enqueue(q1.dequeue());   // 1 elt from queue 1
	   	q3.enqueue(q.dequeue());    // 2nd elt from queue
	   }
	   
	   cout<<"Interleaved queue: ";
	   while(!q3.isEmpty())
	   {
	   	cout<<q3.dequeue()<<" ";
	   }
	   return 0;
}
