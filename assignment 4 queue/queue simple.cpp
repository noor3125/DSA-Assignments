#include<iostream>
using namespace std;
#define maxlen 7
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
			}
			else
			{
				rear++;
				arr[rear]=x;
			}
		}
		void dequeue()
		{
			int x;
			if(isEmpty()){
				cout<<"queue is empty no element left."<<endl;
				return;
			}
			else 
			{ 
				x=arr[front];
				cout<<x<<" element dequeued."<<endl;
			}
			if(front==rear)
			{
				front=rear=-1;
			}
			else 
			{
				front++;
			}
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
					cout<<arr[i]<<endl;
				
				}
			}
		}
};
int main()
{
	Queue q;
	int choice,val;
	do{
		cout<<"............QUEUE MENU............\n";
		cout<<"1.Enqueue\n";
		cout<<"2.Dequeue\n";
		cout<<"3.peek\n";
		cout<<"4.Check if Empty\n";
		cout<<"5.Check if Full\n";
		cout<<"6.Display all Elements\n";
		cout<<"7.Exit\n";
		cout<<"Enter your choice: "<<endl;
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter value to enqueue:"<<endl;
				cin>>val;
				q.enqueue(val);
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.peek();
				break;
			case 4:
				if(q.isEmpty()){
					cout<<"Queue is empty."<<endl;
				}
				else{
					cout<<"No, queue is not empty."<<endl;
				}
				break;
		    case 5:
		    	if(q.isFull()){
					cout<<"Queue is full."<<endl;
				}
				else{
					cout<<"No, queue is empty."<<endl;
				}
		    	break;
		    case 6:
		    	q.display();
		    	break;
		    case 7:
		    	cout<<"Exiting........."<<endl;
		    	break;
		    default:
		    	cout<<"Invalid Input\n";
		    	break;
		}
		
	} while(choice!=7);
	
	return 0;
}
