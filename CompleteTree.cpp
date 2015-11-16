#include<stack>
#include<iostream>
using namespace std ;

struct node{
	int val ;
	struct node * left ;
	struct node * right ;
	node(int x) : val(x) , left(NULL) , right(NULL) {}
};


int count(struct node * root)
{
	if(!root)
		return 0;
	return 1+count(root->left) + count(root->right) ;
}


bool isComplete(struct node * root,int index,int n)
{
	if(root==NULL)
		return true ;
	if(index >= n)
		return false ;
	return (isComplete(root->left,2*index+1,n) && isComplete(root->right,2*index+2,n));
}

bool isComplete(struct node * root)
{
	int n = count(root);
	return isComplete(root,0,n) ;
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
    //root -> right -> left = new node(4);
    root -> left -> left = new node(5) ;
    root -> left -> right = new node(3) ;
    root -> right -> right = new node(25) ;
  //  root -> left->right->left = new node(10); 
    //root -> left -> right -> right = new node(14); 
    if(isComplete(root) )
    	cout<<"Complete  Tree"<<endl;
    else
    	 cout<<"Not complete Tree"<<endl;
}
