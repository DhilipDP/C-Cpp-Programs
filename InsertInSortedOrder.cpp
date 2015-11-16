#include<iostream>
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

struct node * SortedInsert(struct node * head,int data)
{
	struct node * newnode = new  node(data);
	if(head==NULL)
	{
		head = newnode ;
		return head;
	}
	struct node * tra = head,*pre=NULL;
	while(tra && tra->val < data)
	{
			pre = tra;
			tra = tra->next ;
	}
	
	newnode->next = tra;
	if(pre==NULL)
		head=newnode;
	else
		pre->next = newnode;
	return head;
}


int main()
{
	
	struct node * head = NULL ;
	head = SortedInsert(head,3);
		print(head);
	head = SortedInsert(head,4);
		print(head);
	head = SortedInsert(head,1);
		print(head);
	head = SortedInsert(head,6);
		print(head);
	head = SortedInsert(head,2);
		print(head);
	head = SortedInsert(head,7);
	print(head);
}
