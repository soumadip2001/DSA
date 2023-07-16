#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int value) : data(value), next(NULL) {}
};
void insert(Node* &head,int data){
//	struct Node *new_node=(struct Node*) malloc(sizeof(struct Node));
	Node *new_node=new Node(data);
//	new_node->data=data;
//	new_node->next=NULL;
	if(head==NULL){
		head=new_node;
		return;
	}
	Node *temp=head;
	while(temp!=NULL && temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
}
void print(Node *head){
	struct Node *temp=head;
	if(temp==NULL){
		cout<<"No element present in the linked list "<<"\n";
		return;
	}
	while(temp!=NULL){
		cout<<temp->data<<"	";
		temp=temp->next;
	}
	cout<<"\n";
}
Node* sorted_linked_list(Node *head1,Node *head2){
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;
	Node *t1=head1,*t2=head2,*curr=t1,*temp=NULL;
	if(t1->data>t2->data){
		swap(t1,t2);
		curr=t1;
	}
	while(t1!=NULL && t2!=NULL){
		temp=t1;
		if(t1->data<=t2->data)
			t1=t1->next;
		else{
			swap(t1,t2);
			temp->next=t1;
			t1=t1->next;	
		}
	}
//	while(curr!=NULL){
//		cout<<curr->data<<" ";
//		curr=curr->next;
//	}
	return curr;
	
}
//Reverse k nodes in a linked list using recursion 
Node* ReverseKNodes(Node *&head,int k,int len){
	
	if(head==NULL ||head->next==NULL ||k==1 ||len<k){
		return head;
	}
	Node *prev=NULL,*cur=head,*nex=NULL;
	int cnt=0;
	while(cur!=NULL && cnt<k){
		nex=cur->next;
		cur->next=prev;
		prev=cur;
		cur=nex;
		cnt++;
	}
	if(nex!=NULL){
		head->next=ReverseKNodes(nex,k,len-k);
	}
	//think of last kth nodes
	head =prev;
	//return that head from 
	return head;
}
Node* ReverseKNodeInGroup(Node *&head,int k){
	Node * temp=head;
	int cnt=0;
	while(temp!=NULL){
		temp=temp->next;
		cnt++;
	}
	cout<<"count "<<cnt<<"\n";
	Node *temp1=ReverseKNodes(head,k,cnt);
	return temp1;
}
int main(){
	
	Node *head1=NULL,*head2=NULL;
	insert(head1,4);
	insert(head1,3);
	insert(head1,2);
	insert(head1,1);
	insert(head1,9);
	insert(head1,10);
	insert(head1,7);
	insert(head2,8);
	insert(head2,6);
	insert(head2,7);
	insert(head2,5);
	print(head2);
	print(head1);
	Node *temp=sorted_linked_list(head1,head2);
	print(temp);
	Node *temp1=ReverseKNodeInGroup(head1,3);	//reversed k linked list using recursion
	cout<<"Reversed linked list in group "<<"\n";
	print(temp1);
	return 0;
}
