/* Reverse a doubly linked list*/
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
void insert(struct node*&head,int data) 
{
	struct node *newnode=new node;
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	struct node *traverse;
	traverse=head;
	while(traverse->next!=NULL)
	{
		traverse=traverse->next;
	}
	traverse->next=newnode;
	newnode->prev=traverse;	
}
void print(struct node *head)
{
	struct node *traverse;
	traverse=head;
	while(traverse)
	{
		printf("%d\t",traverse->data);
		traverse=traverse->next;
	}
}
void reverse(struct node *&head)
{
	struct node *traverse=head;
	struct node *temp;
	while(traverse!=NULL)
	{
		temp=traverse->prev;
		traverse->prev=traverse->next;
		traverse->next=temp;
		traverse=traverse->prev;
	}
	head=temp->prev;

}

int main()
{
	struct node *head=NULL;
	for(int i=1;i<=6;i++)
	{
		insert(head,i);
	}
	print(head);
	reverse(head);
	printf("\n");
	print(head);
}
