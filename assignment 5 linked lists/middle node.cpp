#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(int new_data)
		{
			this->prev=nullptr;
			this->data= new_data;
			this->next= nullptr;
		}
};
int getlength(Node* head){
	int length=0;
	
	while(head)
	{
		length++;
		head=head->next;
	}
	return length;
}
int getmid(Node* head)
{
	int length=getlength(head);
	
	int  midIndex=length/2;
	while(midIndex--)
	{
		head=head->next;
	}
	return head->data;
}
int main()
{
	Node* head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	head->next->next->next->next->next=new Node(60);
	head->next->next->next->next->next->next=new Node(70);
	head->next->next->next->next->next->next->next=new Node(80);
	head->next->next->next->next->next->next->next->next=new Node(90);
	head->next->next->next->next->next->next->next->next->next=new Node(100);
	head->next->next->next->next->next->next->next->next->next->next=new Node(110);
	cout<<getmid(head);
	return 0;
	
}
