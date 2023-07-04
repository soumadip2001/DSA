#include<bits/stdc++.h>
using namespace std;

//node class used to represnt a node of linked list
class Node{
	public:
		int data;
		Node *next;
		Node(){
			data=0;
			next=NULL;
		}
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
};

//linked list class to implement a linkedlist
class linkedlist{
	Node* head;
	public:
		linkedlist(){
			head=NULL;
		}
		//data to be entered
		void insertNode(int);
		//position to be entered
		void deleteNode(int);
		void printList();
		void reverse_linked_list();
		void middle_element1();		//middle element by approach 1
		void middle_element2();		//middle element by approach 2 by slow and fast pointer
};
void linkedlist::deleteNode(int pos){
	Node *temp1=head,*temp2=NULL;
	int len=0;
	if(head==NULL){
		cout<<"Empty linked list"<<"\n";
		return ;
	}
	while(temp1!=NULL){
		temp1=temp1->next;
		len++;
	}
	if(len<pos){
		cout<<"index out of range "<<"\n";
		return;
	}
	
	if(pos==1){
		head=head->next;
		delete temp1;
		return;
	}
	
	temp1=head;
	while(pos-- > 1){
		temp2=temp1;
		temp1=temp1->next;
	}
	temp2->next=temp1->next;
	delete temp1;
}
void linkedlist::insertNode(int val){
	Node* n1=new Node(val); 
	if(head==NULL){
		head=n1;
		return;
	}
	Node* temp1=head,*temp2=NULL;
	while(temp1!=NULL){
		temp2=temp1;
		temp1=temp1->next;
	}
	temp2->next=n1;
	cout<<"\n";
//	return ;
}
void linkedlist::printList(){
	Node *temp1=head;
	if(head==NULL){
		cout<<"NO node is present "<<"\n";
		return;
	}
	while(temp1!=NULL){
		cout<<temp1->data<<" ";
		temp1=temp1->next;
	}
	cout<<"\n";
}
void linkedlist::reverse_linked_list(){
	Node *temp=head;
	if(head==NULL){
		cout<<"no element in the list "<<"\n";
		return;
	}
	Node *curr=head,*prev=NULL;
	while(temp!=NULL){
		curr=temp;
		temp=temp->next;
		curr->next=prev;
		prev=curr;
	}
	head=curr;
	while(curr!=NULL){
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<"\n";
}
void linkedlist::middle_element1(){
	if(head==NULL){
		cout<<"no element found "<<"\n";
		return ;
	}
	Node *temp=head;
	int len=0;
	while(temp!=NULL){
		temp=temp->next;
		len++;
	}
	temp=head;
	int mid=(len/2)+(len%2);
	if(mid%2){
		mid+=1;
	}
	while(mid-->1){
		temp=temp->next;
	}
	cout<<"middle element "<<temp->data;
}
void linkedlist::middle_element2(){
	Node *slow=head,*fast=head;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	cout<<"middle element by tortoise method "<<slow->data;
}
int main(){
	linkedlist list;	//object- list
	list.insertNode(1);
	list.insertNode(2);
	list.insertNode(3);
	list.insertNode(4);
	list.insertNode(5);
	list.insertNode(6);
	list.insertNode(7);
	list.printList();
	list.deleteNode(3);
	list.printList();
	list.reverse_linked_list();	//reversed linked list
	list.reverse_linked_list();
	list.middle_element1();
	list.middle_element2();
	return 0;
	
}
