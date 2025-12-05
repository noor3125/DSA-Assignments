#include<iostream>
using namespace std;
class Node{
    public:
	int data;
	Node* next;
	Node* prev;
	Node(int new_data)
	{
		this->next=nullptr;
		this->prev=nullptr;
		this->data=new_data;
	}
};
Node *reverselist(Node *head)
{
	Node* curr=head;
	Node* next=nullptr;
	Node* prev=nullptr;
	while(curr!=nullptr)
	{
		next=curr->next;
		curr->next=prev;
		
		prev=curr;
		curr=next;
	}
	return prev;
}
void printlist(	Node*temp){
	while(temp!=nullptr)
	{
		cout<<temp->data;
		if(temp->data){
		    cout<<"->";
		}
		temp=temp->next;
	}
}
int main(){
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
	head=reverselist(head);
	printlist(head);
	return 0;
}
