#include<bits/stdc++.h>
using namespace std;

//node class used to represnt a node of linked list
class node{
	public:
		int data;
		Node * next;
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
		cout<<"Empty linked list";
		return ;
	}
	while(temp1!=NULL){
		temp1=temp1->next;
		len++;
	}
	if(len<pos){
		cout<<"position exceed";
		return;
	}
	
	if(pos==1){
		head=head->next;
		delete head;
		return;
	}
	
	temp1=head;
	while(len--){
		temp2=temp1;
		temp1=temp1->next;
	}
	temp2->next=temp1->next;
	delete temp1;
	return;
}
void linkedlist::insertNode(int val){
	if(head==NULL){
		head->data=val
	}
}
int main(){
	
}
