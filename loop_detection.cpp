/* detect loop*/
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
void create_loop(struct node *head)
{
	struct node *traverse=head;
	while(traverse->next!=NULL)
	{
		traverse=traverse->next;
	}
	traverse->next=head->next->next;
}
void detect_loop(struct node *head)
{
	struct node *fast,*slow;
	fast=slow=head;
	while(slow &&fast&&fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			printf("\n LOOP DETECTED");
			break;
		}
	}
}
int main()
{
	struct node *head=NULL;
	for(int i=1;i<=7;i++)
	{
		insert(head,i);
	}
	print(head);
	create_loop(head);
	detect_loop(head);
	
}
