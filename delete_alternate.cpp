//Delete alternate nodes of a Linked List
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
struct node
{ 
	int data;
	struct node *next;
};
void insert(struct node *&head,int dat)
{
	struct node *newnode=new node;
	struct node *traverse;
	newnode->data=dat;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	traverse=head;
	while(traverse->next!=NULL)
	{
		traverse=traverse->next;
	}
	traverse->next=newnode;

}
void print(struct node *&head)
{
	struct node *traverse;
	traverse=head;
	while(traverse!=NULL)
	{
		printf("%d\t",traverse->data);
		traverse=traverse->next;
	}
	
}
void delete_alternate(struct node *&head)
{
	struct node *traverse,*temp;
	traverse=head;
	while(traverse&&traverse->next)
	{
		temp=traverse->next;
		traverse->next=traverse->next->next;
		//free(temp);
		traverse=traverse->next;
	}
}

int main()
{
	struct node *head=NULL;
	for(int i=1;i<=5;i++)
	{
		insert(head,i);
	}
		print(head);
		delete_alternate(head);
		printf("\n\n");
		print(head);
}
