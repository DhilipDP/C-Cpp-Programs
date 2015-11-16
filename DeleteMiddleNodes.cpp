
#include<stdlib.h>
#include<iostream>
using namespace std ;


struct node{
	int x,y ;
	struct node * next ;
	node(int a,int b) : x(a) , y(b) , next(NULL) {}
};




void print(struct node * head){
	struct node * temp = head;
	while(temp)
	{
		cout<<temp->x<<" "<<temp->y<<"    ";
		temp = temp -> next;
	}
	cout<<endl;
}


struct node * makeitstraight(struct node * head)
{
	if(head==NULL || head->next==NULL || head->next->next==NULL)
		return head;
	struct node * Next = head->next;
	struct node * NextNext = Next->next ;
	if(head->x == Next->x)
	{
		while(NextNext && NextNext -> x == Next->x)
		{
			head->next = NextNext;
			free(Next);
			Next = NextNext ;
			NextNext = Next->next;
		}
	}
	else if(head->y==head->next->y)
	{
		while(NextNext && NextNext->y == Next->y)
		{
			head->next = NextNext ;
			free(Next);
			Next = NextNext ;
			NextNext = Next-> next;
			
		}
	}
	makeitstraight(head->next);
	return head;
	
}


struct node * straight(struct node * head)
{
	struct node * cur = head;
	
	if(head==NULL || head->next==NULL || head->next->next==NULL)
		return head;

	while(cur && cur->next)
	{
		struct node * Next = cur->next;
	struct node * NextNext = Next->next ;
	if(cur->x == Next->x)
	{
		while(NextNext && NextNext -> x == Next->x)
		{
			cur->next = NextNext;
			free(Next);
			Next = NextNext ;
			NextNext = Next->next;
		}
	}
	else if(cur->y==Next->y)
	{
		while(NextNext && NextNext->y == Next->y)
		{
			cur->next = NextNext ;
			free(Next);
			Next = NextNext ;
			NextNext = Next-> next;
			
		}
	}
	cur = cur->next;
	}
	return head;
}

int main()
{
/*	Given Linked List:
(0,10)-> (1,10)-> (3,10)-> (10,10)-> (10,8)-> (10,5)-> (20,5)-> (40,5)->
*/
	struct node * head = 	 new node(0,10);
	head -> next = new node(1,10);
	head -> next -> next = new node(3,10);
	head -> next -> next -> next= new node(10,10);
	head -> next -> next -> next-> next= new node(10,8);
	head -> next -> next -> next-> next-> next= new node(10,5);
	head -> next -> next -> next-> next-> next->next= new node(20,5);
	head -> next -> next -> next-> next-> next->next->next= new node(40,5);
		print(head);	
	head  = straight(head);
//	head = makeitstraight(head);
	print(head);
}
