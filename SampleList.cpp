#include<iostream>
#include<stdlib.h>
using namespace std ;
struct node * reverse (struct node * );

struct node {
	int data;
	struct node * next;
	node(int x) : data(x), next(NULL) {}
};


struct node * delete_alternate(struct node * head){
	struct node * t = head;
	struct node *p= head;
	if(head==NULL)
		return NULL ;
	
	while(t && t->next){
		p = t->next;
		t->next=p->next;
		free(p);
		t=t->next;
	}
	return head;
}




void traverse(struct node * t){
	while(t){
		cout<<t->data<<" ";
		t=t->next;
	}
}


bool check(struct node * head){
	struct node * t=head;
	if(head==NULL)
		return true;
	struct node * slow=head;
	struct node * fast = head->next;
	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	struct node *mid = slow;
//	cout<<mid->data;
	struct node * p = reverse(mid->next);
//	traverse(p);
	while( head!=slow && p)
	{
		if(head->data != p->data)
		
			return false;
		
		head=head->next;
		p=p->next;
		
	//	//return true;
	
	}
	return true;
}

struct node * reverse (struct node * p)
{
	struct node * prev = NULL;
	struct node * current = p;
	struct node * next;
	while(current)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	p=prev;
	return p;
}
int main(){
	struct node * head = new node(3);
	head->next = new node(2);
	head->next->next=new node(4);
	head->next->next->next = new node(2);
	head->next->next->next->next = new node(3);
//	traverse(head);
	
/*	cout<<endl;
//	head	= delete_alternate(head);
//	traverse(head);*/
	if(check(head))
		cout<<"PALINDROME!";
	else
		cout<<"Not a Palindrome!";
}
