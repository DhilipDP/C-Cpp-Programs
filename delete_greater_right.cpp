/*Delete nodes which have a greater value on right side*/
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
struct node * delete_greater(struct node *& head1)
{
	int max_till_here=head1->data;
	struct node *traverse;
	traverse=head1;
	while(traverse->next!=NULL)	
	{
		if(max_till_here>traverse->next->data)
		{
			traverse->next=traverse->next->next;
			traverse=traverse->next;		
			
		}
		else
		{
			max_till_here=traverse->next->data;
			traverse=traverse->next;
		}	
	}
	
	return(head1);
}
int main()
{
	struct node *head=NULL,*head1=NULL,*head2,*head3;
	for(int i=1;i<6;i++)
	{
		insert(head,i);
	}
	print(head);
	head1=reverse1(head);
	printf("\n");
	head2=delete_greater(head1);
	print(head2);
	printf("\n");
	printf("\n The required list is");
	head3=reverse1(head2);
	print(head3);
}
