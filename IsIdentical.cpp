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

bool  isIdentical(struct node * root1,struct node * root2)
{
	if(root1 == NULL && root2 ==NULL)
		return true ;
	if(root1 == NULL || root2 == NULL)
		return false ;
	return ((root1->val==root2->val) && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right));
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
    struct node * root1 = new node(1) ;
    root1 -> left = new node(2) ;
    root1 -> right = new node(3) ;
    root1 -> left -> right = new node(4) ;
    root1 -> left -> right -> right = new node(5) ;
    root1 -> left -> right->right ->right =  new node(6) ;
	struct node * root2 = new node(20);
    root2 -> left = new node(8) ;
    root2 -> right = new node(22);
    root2 -> right -> left = new node(4);
    root2 -> left -> left = new node(5) ;
    root2 -> left -> right = new node(3) ;
    root2 -> right -> right = new node(25) ;
    root2 -> left->right->left = new node(10); 
    root2 -> left -> right -> right = new node(14);     
	cout<<endl<<isIdentical(root,root1) ;
	cout<<endl<<isIdentical(root,root2) ;
}

