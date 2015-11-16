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
	struct node *prev=head,*temp;
	int arr[100]={0};
	arr[head->data]++;
	while(traverse)
	{
		if(arr[traverse->data]==0)
		{
			arr[traverse->data]++;
			prev=prev->next;
			traverse=traverse->next;
		}
		else
		{
			temp=traverse;
			prev->next=traverse->next;
			traverse=traverse->next;		
			free(temp);
		}
	}
//	printf("%d",traverse->data);
}
int main()
{
	struct node *head=NULL;
	insert(head,12);
	insert(head,11);
	insert(head,12);
	insert(head,21);
	insert(head,41);
	insert(head,43);				
	insert(head,21);
	insert(head,21);
	insert(head,43);
	print(head);
	remove_dup(head);
	printf("\n");
	print(head);
	
}
