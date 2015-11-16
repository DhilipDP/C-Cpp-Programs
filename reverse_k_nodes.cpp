/*Reverse alternate K nodes in a Singly Linked List
Given a linked list, write a function to reverse every alternate k nodes (where k is an input to the function) in an efficient way. Give the complexity of your algorithm.

Example:
Inputs:   1->2->3->4->5->6->7->8->9->NULL and k = 3
Output:   3->2->1->4->5->6->9->8->7->NULL. */
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
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
void print(struct node * &head)
{
	struct node *traverse;
	traverse=head;
	while(traverse!=NULL)
	{
		printf("%d\t",traverse->data);
		traverse=traverse->next;
	}
}
struct node * reverse1(struct node *& head)
{
	struct node *rev,*temp;
	rev=NULL;
	
	while(head!=NULL)
	{	
		temp=head;
		head=head->next;
		temp->next=rev;		
		rev=temp;
	}
	return rev;
}
int main()
{
	struct node *head=NULL,*head1=NULL,*traverse,*traverse1;
	int k;
	for(int i=1;i<6;i++)
	{
		insert(head,i);
	}
	print(head);
	printf("\nEnter the number of nodes to be swapped");
	scanf("%d",&k);	
	traverse=head;
	traverse1=head;
	for(int i=0;i<k-1;i++)
	{
		head=head->next;
		traverse1=traverse1->next;
		
	}
	head=head->next;
	traverse1->next=NULL;
	head1=reverse1(traverse);
	traverse1=head1;
	while(traverse1->next!=NULL)
	{
		traverse1=traverse1->next;
	}
	traverse1->next=head;
	printf("\n\n");
	printf("The required node is\n");
	print(head1);
}
