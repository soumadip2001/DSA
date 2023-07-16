#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
};
struct Node *head=NULL;
void insert(int data){
	struct Node *new_node=(struct Node*) malloc(sizeof(struct Node));
	new_node->data=data;
	new_node->next=NULL;
	if(head==NULL){
		head=new_node;
		return;
	}
	struct Node *temp=head;
	while(temp!=NULL && temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
}
void print(){
	struct Node *temp=head;
	if(temp==NULL){
		cout<<"No element present in the linked list "<<"\n";
		return;
	}
	while(temp!=NULL){
		cout<<temp->data<<"\n";
		temp=temp->next;
	}
}
int main(){
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	print();
	return 0;
}
