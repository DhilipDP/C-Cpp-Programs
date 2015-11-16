#include<iostream>
#include<stdio.h>
using namespace std ;

struct node{
	int val;
	struct node *next ;
};

struct node * insert_at_front(struct node * head,int val)
{
	struct node * newnode = new node;
	newnode -> val = val;
	newnode -> next = NULL;
	
	if(head==NULL){
		head = newnode;
		return head;
	}
	else{
	newnode -> next = head;
	head = newnode;
	return head;
}
}


void print(struct node * head){
	//struct node * head = head;
	while(head != NULL){
		cout<<head->val<<" "<<"\n";
		head = head->next;
	}
	cout<<endl;

}


struct node * insert_at_back(struct node * head,int val){
	struct node * newnode = new node;
	newnode -> val = val;
	newnode -> next = NULL;
	
	if(head==NULL){
		head = newnode;
		return head;
	}
	struct node * last = head;
	while(last -> next !=NULL)
	last = last -> next;
	last -> next = newnode;
	return head;

}
int main(){
struct node * head = NULL;
	for(int i=1; i<=5 ; i++)
		head = insert_at_front(head,i);
	print(head);
	struct node * head1 = NULL;
	for(int i=1;i<=5;i++)
		head1 = insert_at_back(head1,i);
		

	print(head1);

}
