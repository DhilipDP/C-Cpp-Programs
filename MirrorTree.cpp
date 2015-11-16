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


void inorder(struct node * root)
{
	if(root)
	{
		inorder(root->left) ;
		cout<<root->val <<" " ;
		inorder(root->right) ;
	}
	
}


struct node * mirror(struct node * root)
{
	if(root==NULL)
		return NULL ;
	root -> left = mirror(root->left) ;
	root -> right = mirror(root->right);
	struct node * temp = root->left ;
	root -> left = root -> right ;
	root -> right = temp ;
	return root ;
}


int main()
{
	struct node * root = NULL ;
	/*
	
	     		 
                      20
                    /    \
                  8       22
                /   \    /   \
              5      3 4     25
                    / \      
                  10    14 
    */
   
    root = new node(20);
    root -> left = new node(8) ;
    root -> right = new node(22);
    root -> right -> left = new node(4);
    root -> left -> left = new node(5) ;
    root -> left -> right = new node(3) ;
    root -> right -> right = new node(25) ;
    root -> left->right->left = new node(10); 
    root -> left -> right -> right = new node(14); 
 /*   root = new node(1) ;
    root -> left = new node(2) ;
    root -> right = new node(3) ;
    root -> left -> right = new node(4) ;
    root -> left -> right -> right = new node(5) ;
    root -> left -> right->right ->right =  new node(6) ;*/
    inorder(root) ;
	root = mirror(root);
	cout<<endl;
	inorder(root) ;
}

