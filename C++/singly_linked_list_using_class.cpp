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
	cout<<"insert ";
//	return ;
}
void linkedlist::printList(){
	Node *temp1=head;
	if(head==NULL){
		cout<<"NO node is present ";
		return;
	}
	while(temp1!=NULL){
		cout<<temp1->data<<" ";
		temp1=temp1->next;
	}
}
int main(){
	linkedlist list;	//object- list
	list.insertNode(1);
	list.insertNode(2);
	list.insertNode(3);
	list.insertNode(4);
	list.insertNode(5);
	list.insertNode(6);
	list.printList();
	list.deleteNode(3);
	list.printList();
	return 0;
	
}
