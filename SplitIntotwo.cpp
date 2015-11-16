

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



struct node * pairSwap(struct node * head)
{
	if(head==NULL || head->next==NULL)
		return head;
	struct node * pre = NULL ;
	struct  node * cur = head ;
	while(cur && cur->next){
		
		if(pre==NULL)
			head = cur->next ;
		else
			pre -> next = cur->next ;
		struct node * temp = cur->next;
		cur->next = temp->next;
		temp->next = cur;
		
		pre = cur;
		cur = cur->next;
	}
	return head;
}

struct node * pairWiseSwap(struct node * head)
{
	if(head==NULL || head->next==NULL)
		return head;
	struct node * nextPair = head -> next -> next ;
	struct node * newHead =head->next ;
	newHead -> next = head ;
	head -> next = pairWiseSwap(nextPair);
	return newHead ;
}

void split(struct node * head,struct node *&a ,struct node *&b)
{
	if(head==NULL || head->next==NULL)
		return  ;
	a = head ;
	b = head->next ;
	struct node * a_last = a,*b_last = b,*cur = b->next;
	while(cur )
	{
		a_last -> next  = cur ;
		a_last = cur ;
		cur = cur -> next ;
		if(cur)
		{
			b_last -> next = cur ;
			b_last = cur;
			cur = cur->next ;
		}
		
	}
	a_last -> next = NULL ;
	b_last -> next = NULL ;
}

int main()
{
	struct node * head = 	 new node(5);
	head -> next = new node(3);
	head -> next -> next = new node(6);
	head -> next -> next -> next= new node(2);
	head -> next -> next -> next-> next= new node(1);
//	head -> next -> next -> next-> next-> next= new node(4);
	print(head);	
	struct node * a = NULL ,*b=NULL ;
	  split(head,a,b);
	print(a);
	print(b) ;
}
