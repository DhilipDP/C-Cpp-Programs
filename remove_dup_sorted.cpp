/* remove duplicates from a sorted linked list*/
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
void remove_dup(struct node *head)
{
	struct node *traverse=head->next;
	struct node *prev=head;
	while(traverse)
	{
		if(prev->data==traverse->data)
		{
			prev->next=traverse->next;
			traverse=traverse->next;
		}
		else
		{
			prev=prev->next;
			traverse=traverse->next;
		}
	}
//	printf("%d",traverse->data);
}
int main()
{
	struct node *head=NULL;
	insert(head,1);
	insert(head,1);
	insert(head,2);
	insert(head,2);
	insert(head,2);
	insert(head,3);				
	insert(head,3);
	insert(head,3);
	print(head);
	remove_dup(head);
	printf("\n");
	print(head);
	
}
