#include<utility>
#include<windows.h>
#include<map>
#include<vector>
#include<iostream>
using namespace std ;

struct node{
	int val ;
	struct node * left ;
	struct node * right ;
	node(int x) : val(x) , left(NULL) , right(NULL) {}
};


struct node * insert(struct node * root,int val)
{
/*	if(root)
	cout<<root->val<<" "<<val<<endl;
	else
		cout<<root<<" "<<val<<endl; */
	if(root == NULL)
		root = new node(val) ;
	else if(root->val > val)
		root->left = insert(root->left,val);
	else
		root->right = insert(root->right,val);
	return root ;
}

void inorder(struct node * root)
{	if(root){
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}


void preorder(struct node * root)
{
	if(root){
		cout<<root->val<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}


void postorder(struct node * root)
{
	if(root){
		postorder(root->left);
		postorder(root->right);
		cout<<root->val<<" ";
	}
}


int findMin(struct node * root)
{
	if(root==NULL)
	{
		cout<<"\nEmpty Tree: "<<endl;
		return -1;
	}
	if(root->left==NULL)
		return root->val;
	return findMin(root->left);
}


struct node * findLCA(struct node * root,struct node * n1,struct node * n2)
{
	if(root==NULL)
		return root ;
	if(root==n1 || root==n2)
		return root ;
	if(root->val > n1->val && root->val > n2->val)
		return findLCA(root->left,n1,n2) ;
	if(root->val < n1->val  && root -> val < n2->val)
		return findLCA(root->right,n1,n2) ;
	return root ;
}

int main()
{
	struct node * root = NULL ;
	root = insert(root,7);
	root = insert(root,4) ;
	root = insert(root,11);
	root = insert(root,5) ;
	root = insert(root,9) ;
	root = insert(root,15) ;
	root = insert(root,1);
	cout<<"Inorder"<<endl;
	inorder(root);
	cout<<endl<<"Preorder"<<endl;
	preorder(root);
	cout<<endl<<"Postorder"<<endl;
	postorder(root);
	cout<<endl<<findMin(root)<<endl;
	cout<<"LCA"<<endl;
	cout<<findLCA(root,root->left->left,root->left)->val<<endl;
}
