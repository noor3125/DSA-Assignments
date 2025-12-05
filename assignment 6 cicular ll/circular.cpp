#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* prev=nullptr;
		Node* next=nullptr;
};
void insertfront(Node* head)
{
	cout<<"Enter data for new node:"<<endl;
	
	Node* temp=new Node;
	cin>>temp->data;
	
	if(head==nullptr)
	{
		temp->next=temp;
		temp->prev=temp;
		head=temp;
	}
	else{
		
		temp->next=head;
		temp->prev=(head)->prev;
		((head)->prev)->next=temp;
		(head)->prev=temp;
		head=temp;
	}
	
}
void insertend(Node* head)
{
	cout<<"Enter data for new node:"<<endl;
	
	Node* temp=new Node;
	cin>>temp->data;
	Node* curr=head;
	if(curr==nullptr)
	{
		temp->next=temp;
		temp->prev=temp;
		curr=temp;
	}
	while(curr->next!=head)
	{
		curr=curr->next;
			
	}
	temp=curr->next;
	temp->prev=curr;
	temp->next=head;
	
}
void insertbefore(Node* head)
{
	cout<<"Enter data for new node:"<<endl;
	
	Node* temp=new Node;
	cin>>temp->data;
		Node* curr=head;
	if(curr==nullptr)
	{
		cout<<"No element in the list creating new node";
		temp->next=temp;
		temp->prev=temp;
		curr=temp;
	}
	cout<<"Enter the value: "<<endl;
	int val;
	cin>>val;
	while(curr->next!=head&&curr->next->data!=val)
	{
		curr=curr->next;
	}
	if(curr->next==head)
	{
		cout<<"value not found"<<endl;
	}
	temp->next=curr->next;
	curr->next=temp;
	temp->prev=curr;
}
void insertafter(Node* head){
cout<<"Enter data for new node:"<<endl;
	
	Node* temp=new Node;
	cin>>temp->data;
	cout<<"Enter the value: "<<endl;
	int val;
	cin>>val;
	Node* curr=head;
	if(curr==nullptr)
	{
		cout<<"No element in the list creating new node";
		temp->next=temp;
		temp->prev=temp;
		curr=temp;
	}
	while(curr->next!=head&&curr->data!=val)
	{
		curr=curr->next;
	}
	if(curr->next==head)
	{
		cout<<"value not found"<<endl;
	}
	temp->next=curr->next;
	curr->next=temp;
	temp->prev=curr;
}
void deletefront(Node* head){
	if(head==nullptr)
	{
		cout<<"No element in the list."<<endl;
	}
	else if(head->next==head)
	{
		delete head;
		head=nullptr;
	}
	Node* curr=new Node;
	curr->next=(head)->next;
	curr->prev=(head)->prev;
	(head)->prev->next=curr;
	delete head;
	head=nullptr;
}
void delete_end(Node* head){
    if(head==nullptr)
	{
		cout<<"No element in the list."<<endl;
	}
	Node* curr=head;
	while(curr->next!=head)
	{
		curr=curr->next;
	}
	curr->prev->next=curr->next;
	curr->next->prev=curr->prev;
	delete curr;
}
void deletespecific(Node* head)
{
	cout<<"Enter the value: "<<endl;
	int val;
	cin>>val;
	Node* curr=head;
	while(curr->next!=head&&curr->data!=val)
	{
		curr=curr->next;
	}
	if(curr->next==head){
		cout<<"Node not found"<<endl;
	}
	curr->prev->next=curr->next;
	curr->next->prev=curr->prev;	
	delete curr;
}
void search(Node* head)
{
	int count=0;
    if(head==nullptr)
	{
		cout<<"No element in the list, "<<"count="<<count<<endl;
	}
	Node* curr=head;
	cout<<"Enter element to be searched."<<endl;
	int val;
	cin>>val;
	while(curr->next!=head&&curr->next->data!=val)
	{
		count++;
		curr=curr->next;
	}
	if(curr->next==head)
	{
		cout<<"element not found "<<"count="<<count<<endl;
	
	}
	if(curr->data==val)
	{
		cout<<"Element found at position: "<<count<<" "<<endl;
	}
}
void reverse(Node* head)
{
	if(head==nullptr)
	{
		cout<<"No element in the list."<<endl;
	}
	Node* curr=head;
	Node* temp=nullptr;
	while(curr->next!=head)
	{
		temp=curr->next;
		curr->next=curr->prev;
		curr->prev=temp;
		curr=temp;
	}
	temp=curr->next;
	curr->next=curr->prev;
	curr->prev=temp;
	
	head=curr;
}
void display(Node* head)
{
	if(head==nullptr)
	{
		cout<<"No element in the list."<<endl;
	}
	Node* curr=head;
	cout<<"Linked list:"<<endl;
	while(curr!=head)
	{
		cout<<curr->data<<"->";
		curr=curr->next;
	}
}
int main()
{
	Node* head;
	int choice;
	cout<<"......MENU....."<<endl;
	cout<<"1.Insert at front"<<endl;
	cout<<"2.Insert at end"<<endl;
	cout<<"3.Insert before an element"<<endl;
	cout<<"4.Insert after an element"<<endl;
	cout<<"5.Delete at front"<<endl;
	cout<<"6.Delete at end"<<endl;
	cout<<"7.Delete a specific node"<<endl;
	cout<<"8.Search an element"<<endl;
	cout<<"9.Reverse the list."<<endl;
	cout<<"10.EXIT"<<endl;
	cout<<"Enter your choice from the menu:"<<endl;
	cin>>choice;
	switch (choice){
		case 1:
		     insertfront(head);
		     display(head);
		     break;
	    case 2:
	    	 insertend(head);
	    	 display(head);
		     break;
	    case 3:
	    	 insertbefore(head);
	    	 display(head);
	    	 break;
	    case 4:
	    	 insertafter(head);
	    	 display(head);
	    	 break;
	    case 5:
	    	 deletefront(head);
	    	 display(head);
	    	 break;
	    case 6:
	    	 delete_end(head);
	    	 display(head);
	    	 break;
	    case 7:
	    	 deletespecific(head);
	    	 display(head);
	    	 break;
	    case 8:
	    	 search(head);
	    	 display(head);
	    	 break;
	    case 9:
	    	 reverse(head);
	    	 display(head);
	    	 break;
	    case 10:
	    	 cout<<".....Exiting....."<<endl;
	    	 return 0;
	    default:
	    	 cout<<"Wrong choice entered"<<endl;
	    	 
	}
}
