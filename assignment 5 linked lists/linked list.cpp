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
			this->data=new_data;
			this->next= nullptr;
		}
};
class Linkedlist{
	Node* head;
	public:
		Linkedlist()
		{
			head=nullptr;
		}
		void insertbegining(int val) //a
		{
			Node* temp=new Node(val);
			temp->next=head;
			head=temp;
		}
		void insertend(int val)//b
		{
			Node* temp=new Node(val);
			
			if(head==nullptr)
			{
				head->prev=nullptr;
				head->data=val;
				head->next=nullptr;
			}
		
				Node* skip=head;
				while(skip->next!=nullptr)
				{
					skip=skip->next;
				}
				skip->next=temp;
		}
		void insertafterval(int val,int d)//c
		{
			Node* newnode=new Node(val);
			if(head==nullptr)
			{
			   cout<<"List is empty.";
			   return;
			}
			Node* temp=head;
			while(temp->next!=nullptr&&temp->data!=d)
			{
				temp=temp->next;
			}
			if(temp->next==nullptr)
			{
				cout<<"value not found.";
			}
			else if(temp->data==d){
				temp->next=newnode;
				newnode->next=temp->next->next;
				
			}
		}
		void insertbeforeval(int val,int value)
		{
			Node* newnode=new Node(val);
			if(head==nullptr)
			{
			   cout<<"List is empty.";
			   return;
			}
			Node* temp=head;
			while(temp->next!=nullptr&&temp->next->data!=value)
			{
				temp=temp->next;
			}
			if(temp->next==nullptr)
			{
				cout<<"value not found.";
			}
			else if(temp->next->data==value){
			  newnode->next=temp->next->next;
				temp->next=newnode;
			}
		}
		void deletebegin(){//d
		    if(head==nullptr)
		    {
		    	cout<<"list is empty nothing to delete.";
			}
			else if(head->next==nullptr)
			{
				delete head;
			}
			Node* temp=head;
			head=head->next;
			delete head;
		}
		void delete_end(){
			if(head==nullptr)
		    {
		    	cout<<"list is empty nothing to delete.";
			}
			else if(head->next==nullptr)
			{
				delete head;
			}
			Node* temp=head;
			while(temp->next!=nullptr)
			{
				temp=temp->next;
			}
			temp->prev->next=nullptr;
			delete temp;
		}
		void deletespecific(int val){
				if(head==nullptr)
		    {
		    	cout<<"list is empty nothing to delete.";
			}
			else if(head->next==nullptr)
			{
				delete head;
			}
			Node* temp;
			while(temp->next->data!=val&&temp->next!=nullptr)
			{
				temp=temp->next;
			}
			if(temp->next==nullptr)
			{
				cout<<"node not found";
			}
		       
			    temp->data=val;
				temp->prev=temp->next;
				delete temp;
			
		}
		void traverse(int val)
		{
		   	if(head==nullptr)
		    {
		    	cout<<"list is empty."<<endl;
			}
			else if(head->next==nullptr)
			{
				cout<<"only one value available in the list, position as head"<<head->data<<endl;
			}
			Node* temp=head;
			int pos=1;
			while(temp->next!=nullptr)
			{
				if(temp->data==val)
			   {
				cout<<"value found at position:"<<pos<<endl;
			    }
				temp=temp->next;
				pos++;
			}
			
				cout<<"value not found"<<endl;
			
		}
		void display()
		{
			if(head==nullptr)
		    {
		    	cout<<"list is empty."<<endl;
			}
			Node* temp=head;
			cout<<"Linked List: ";
			while(temp!=nullptr)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};
int main(){
	Linkedlist list;
	int choice,value,key;
	while(true)
	{
		cout<<"......| MENU |......"<<endl;
		cout<<"1.Insertion at the beginning."<<endl;
		cout<<"2.Insertion at the ending."<<endl;
		cout<<"3.Insertion at before value"<<endl;
		cout<<"4.Insertion at after value"<<endl;
		cout<<"5.Deletion at the beginning."<<endl;
		cout<<"6.Deletion at the end."<<endl;
		cout<<"7.Deletion at specific value."<<endl;
		cout<<"8.Search a node and display its position."<<endl;
		cout<<"9.Display."<<endl;
		cout<<"10.Exit"<<endl;
		cout<<"CHOOSE A VALUE FROM THE MENU PROVIDED:";
		cin>>choice;
	
	switch(choice){
		case 1:
			cout<<"Enter value to insert:";
			cin>>value;
			list.insertbegining(value);
			break;
		case 2:
			cout<<"Enter value to insert:";
			cin>>value;
			list.insertend(value);
			break;
		case 3:
			cout<<"Enter value to insert:";
			cin>>value;
			cout<<"Enter the previous node:";
			cin>>key;
			list.insertbeforeval(value,key);
			break;
		case 4:
			cout<<"Enter value to insert:";
			cin>>value;
			cout<<"Enter the previous node:";
			cin>>key;
			list.insertafterval(value,key);
			break;	
		case 5:
			list.deletebegin();
			break;
		case 6:
			list.delete_end();
			break;
		case 7:
			cout<<"Enter the node:";
			cin>>key;
			list.deletespecific(key);
			break;
		case 8:
			cout<<"Enter the node:";
			cin>>key;
			list.traverse(key);
			break;
		case 9:
			list.display();
			break;
		case 10:
			cout<<"......| Exiting |......"<<endl;
			return 0;
		default:
			cout<<"invalid value entered!!!"<<endl;
			
	}			
  } 
}
