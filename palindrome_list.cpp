#include<stdio.h>
#include<iostream>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void insert(struct node *&head,int data)
{
	struct node *newnode=new node;
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	struct node *traverse=head;
	while(traverse->next!=NULL)
	{
		traverse=traverse->next;
	}
	traverse->next=newnode;
}
void print(struct node *head)
{
	struct node *traverse=head;
	while(traverse!=NULL)
	{
		printf("%d\t",traverse->data);
		traverse=traverse->next;
	}
}
struct node * reverse(struct node *head)
{
	struct node *traverse=head;
	struct node *reverse=NULL;
	while(head!=NULL)
	{
		traverse=head;
		head=head->next;		
		traverse->next=reverse;
		reverse=traverse;
		
	}
	return reverse;
}
void palindrome(struct node *head)
{
	struct node *fast,*slow,*temp,*mid;
	int flag;
	fast=slow=head;
	while(slow&&fast&&fast->next)
	{
		temp=slow;
		slow=slow->next;
		fast=fast->next->next;
		
	}
	if(fast==NULL)
	mid=temp;
	else
	mid=slow;
	temp=NULL;
//	printf("%d",mid->data);
	temp=reverse(mid->next);
	mid->next=temp;
	temp=head;
	mid=mid->next;
	while(mid!=NULL)
	{
		if(temp->data==mid->data)
		flag=1;
		else
		flag=0;
		temp=temp->next;
		mid=mid->next;
	}
	if(flag==1)
	{
		printf("\nPALINDROME");
	}
	else
	{
		printf("\nNOT A PALINDROME");
	}
	
}
int main()
{
	struct node *head=NULL;
	insert(head,1);
	insert(head,2);
	insert(head,3);
	insert(head,1);
	print(head);
	palindrome(head);
	printf("\n");
	print(head);
}
