#include<iostream>
using namespace std ;


struct node{
	int val;
	struct node * left ;
	struct node * right ;
	node(int x) :  val(x) ,left(NULL) ,right(NULL) {}
};


void inorder(struct node * root){
	if(root)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}


void preorder(struct node * root){
	if(root)
	{
		cout<<root->val<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}


void postorder(struct node * root){
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->val<<" ";
		
	}
}

int main()
{
	struct node * root = new node(4);
	root->left = new node(3);
	root->right = new node(7);
	root->left->left = new node(10);
	root->left->right = new node(12);
	root->right->left = new node(5);
	root->right->right= new node(6);
	
	cout<<"Inorder : ";inorder(root);cout<<endl;
	cout<<"Preorder : ";preorder(root);cout<<endl;
	cout<<"Postorder : ";postorder(root);cout<<endl;
}
