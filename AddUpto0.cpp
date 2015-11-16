#include<iostream>
#include<stdlib.h>
using namespace std ;


struct node{
	int val ;
	struct node * next ;
	node(int x) : val(x) , next(NULL) {}
};



void print(struct node * head){
	struct node * temp = head;
	while(temp)
	{
		cout<<temp->val<<" ";
		temp = temp -> next;
	}
	cout<<endl;
}


struct node * rearrange(struct node * head)
{
	if(head==NULL)
		return NULL ;
	int cur_sum = 0 ;struct node *tra = head , *pre = NULL;
	while(tra)
	{
		if(tra -> val == 0 && cur_sum !=0)
		{
			pre = !pre ? head : pre->next ;
			pre -> val = cur_sum ;
			cur_sum = 0;
		}
		cur_sum += tra->val;
		tra = tra -> next ;
	}
	
	if(cur_sum !=0){
		pre =  !pre ? head : pre->next ;
		pre->val = cur_sum ;
	}
	
	// optional 
	struct node * temp = pre ? pre -> next : head;
	while(temp)
	{
		node * t = temp->next ;
		cout<<"deleting "<<temp->val<<endl;
		delete temp;
		temp = t;
	}
	// handle case for all 0s
	if(pre) pre->next = NULL; 
	else head = NULL;
	return head;
}

int main()
{
	struct node * head = 	 new node(1);
	head -> next = new node(2);
	head -> next -> next = new node(0);
	head -> next -> next -> next= new node(4);
	head -> next -> next -> next-> next= new node(5);
	head -> next -> next -> next-> next-> next= new node(3);
	print(head);
	head = rearrange(head);
	print(head);	 
	
}
