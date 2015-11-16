#include<stdio.h>
#include<iostream>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *newNode(int data)
{
	struct node *newnode=new node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct node *insert(struct node *root,int data)
{
	struct node *temp=newNode(data);
	if(root==NULL)
	{
		root=temp;
	}
	else if(data>root->data)
	{
		root->right=insert(root->right,data);
	}
	else if(data<root->data)
	{
		root->left=insert(root->left,data);
	}
	return root;
}
void inorder(struct node *root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
struct node *succ(struct node *root,int data)
{
	static int flag;
		if(flag==1)
	return root;

	if(root==NULL)
		return root;
	if(root->data==data)
	 flag=1;
	succ(root->left,data);
	
	succ(root->right,data);
}
int main()
{
	struct node *root=NULL;
	struct node *succe=NULL;
	root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  	inorder(root);
  	succe=succ(root,50);
  	printf("\n%d",succe->data);
}
