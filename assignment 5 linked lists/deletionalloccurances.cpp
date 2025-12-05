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
	void insertend(Node* head,int val)
		{
			Node* temp=new Node(val);
			
			if(head==nullptr)
			{
			     head=temp;
			}
				Node* skip=head;
				while(skip->next!=nullptr)
				{
					skip=skip->next;
				}
				skip->next=temp;
				temp->prev=skip;
		}
		Node* deletealloccurances(Node* head,int key)
		{
			int count=0;
			while(head!=nullptr&&head->data==key){
				Node* temp=head;
				head=head->next;
				if(head!=nullptr)
				head->prev=nullptr;
				delete temp;
				count++;
			}
			if(head==nullptr){
				return count;
			}
			Node* curr=head;
			while(curr->next!=nullptr)
			{
				if(curr->next->data==key)
				{
					Node* temp=curr->next;
					curr->next=curr->next->next;
					delete temp;
					count++;
				}
				else
				{
					curr=curr->next;
				}
			}
			return count;	
		}
	void display(Node* head)
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
int main(){
	Node* head;
	insertend(head, 1);
    insertend(head, 2);
    insertend(head, 1);
    insertend(head, 2);
    insertend(head, 1);
    insertend(head, 3);
    insertend(head, 1);

int	key=1;
	cout<<"Original Linked List:";
	display(head);
	
	int count=deletealloccurances(head,key);
	
	cout<<"count:"<<count<<endl;
	
	cout<<"Updated Linked List:";
	display(head);
	return 0;
}

