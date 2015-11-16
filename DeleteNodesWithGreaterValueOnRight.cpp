#include<stdlib.h>

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

struct node * reverse(struct node * head)
{
	struct node * cur = head,*pre=NULL ;
	while(cur)
	{
		struct node * temp = cur->next ;
		cur -> next = pre ;
		pre = cur ;
		cur = temp ;
	}
	return pre ;
}

struct node * deleteRightNodes(struct node * head)
{
	if(head==NULL || head->next==NULL)
		return head ;
		
	struct node * rev = reverse(head) ;
	struct node * tra = rev  ;
	int max = tra->val ;
	while(tra)
	{
		
		
	}
}
int main()
{
	struct node * head = 	 new node(5);
	head -> next = new node(3);
	head -> next -> next = new node(6);
	head -> next -> next -> next= new node(2);
	head -> next -> next -> next-> next= new node(1);
	head -> next -> next -> next-> next-> next= new node(4);
	print(head);	
	head = deleteRightNodes(head);
	print(head);
}
