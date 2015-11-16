#include<stdio.h>
#include<iostream>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void insert(struct node * &head,int data)
{
	struct node *newnode=new node;
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		newnode->next=head;
		return;
	}
	struct node *traverse=head;
	while(traverse->next!=head)
	{
		traverse=traverse->next;
	}
	traverse->next=newnode;
	newnode->next=head;
}
void print(struct node *head)
{
	struct node *traverse;
	traverse=head->next;
	printf("%d",head->data);
	while(traverse!=head)
	{
		printf("\t%d",traverse->data);
		traverse=traverse->next;
	}
}
struct node *split_circular(struct node *head)
{
	struct node *slow,*fast,*temp1,*temp2;
	slow=head;
	fast=head->next;
	while(fast!=head&&fast->next!=head)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	temp1=slow->next;
	temp2=temp1;
	slow->next=head;
	while(temp1->next!=head)
	{
		temp1=temp1->next;
	}
	temp1->next=temp2;
	return temp2;
}
int main()
{
	struct node *head=NULL,*head1=NULL;
	for(int i=1;i<=5;i++)
	{
		insert(head,i);
	}
	print(head);
	head1=split_circular(head);
	printf("\n");
	print(head);
	printf("\n");
	print(head1);
}
