/* reverse a linked list */
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
int main()
{
	struct node *head=NULL;
	for(int i=1;i<=7;i++)
	{
		insert(head,i);
	}
	print(head);
	head=reverse(head);
	printf("\n");
	print(head);
	
}
