#include<algorithm>
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



int diameter(struct node * root,int &height)
{
	if(!root){
		height = 0;
		return 0;
	}
	int lh = 0,rh=0;
	int l = diameter(root->left,lh) ;
	int r = diameter(root->right,rh ) ;
	height = max(lh,rh) + 1 ;
	return max(max(l,r) , lh+rh+1);
}

bool isBalanced(struct node * root,int &height)
{
	if(root==NULL)
	{
		height = 0;
		return true ;
	}
	int lh=0,rh=0;
	bool l = isBalanced(root->left,lh) ;
	bool r = isBalanced(root->right,rh ) ;
	height = lh > rh ? lh + 1 : rh+ 1 ;
	return (l && r && abs(lh-rh) < 2) ;
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
                  		 \
                  		14
                  		\
                  		 14
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
//	 root -> left -> right -> right -> right= new node(14); 
//	  root -> left -> right -> right ->right -> right= new node(14); 
    struct node * root1 = new node(10) ;
    root1 -> left = new node(8) ;
    root1 -> right = new node(2) ;
    root1 -> left ->left = new node(3) ;
    root1 -> left -> right = new node(5);
    root1 -> right -> right = new node(2) ;
   int height = 0;
   cout<<isBalanced(root,height)<<endl;
	height = 0;
   cout<<diameter(root,height) ;	
}
