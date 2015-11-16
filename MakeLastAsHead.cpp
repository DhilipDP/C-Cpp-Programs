
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


struct node * make_last_as_head(struct node * head)
{
	struct node * sec_last = NULL ,*last = head ;
	while(last -> next )
	{
		sec_last = last ;
		last = last -> next ;
	}
	sec_last -> next = NULL ;
	last -> next = head ;
	head = last ;
	return head ;
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
	head = make_last_as_head(head) ;
	print(head);
}
