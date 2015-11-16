#include<limits.h>

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

bool isBst(struct node * root,int min,int max)
{
	if(!root)
		return true ;
	if(root->val < min || root->val > max)
		return false ;
	return (isBst(root->left,min,root->val-1) && isBst(root->right,root->val+1,max));
}

int main()
{
	struct node * root = NULL ;
    root = new node(7) ;
    root -> left = new node(3) ;
    root -> right = new node(9) ;
    root -> left -> right = new node(5) ;
    root -> left -> right -> right = new node(18) ;
    inorder(root) ;
    cout<<endl<<isBst(root,INT_MIN,INT_MAX) ;
//	inorder(root) ;
}

