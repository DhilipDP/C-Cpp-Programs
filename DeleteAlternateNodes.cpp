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


struct node * delete_alternate(struct node * head)
{
	if(head==NULL || head->next==NULL)
		return head;
	struct node * temp = head->next;
	head->next = delete_alternate(temp->next) ;
	free(temp);
	return head ;
}

int main()
{
	struct node * head = 	 new node(5);
	head -> next = new node(3);
	head -> next -> next = new node(6);
	head -> next -> next -> next= new node(6);
	head -> next -> next -> next-> next= new node(3);
	head -> next -> next -> next-> next-> next= new node(5);
	head = delete_alternate(head);
	print(head);	 
	
}
