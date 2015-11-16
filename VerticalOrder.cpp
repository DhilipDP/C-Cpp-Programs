
#include<map>
#include<iostream>
using namespace std ;

struct node{
	int val ;
	struct node * left ;
	struct node * right ;
	node(int x) : val(x) , left(NULL) , right(NULL) {}
};


map<int , int> m ;
void verticalOrder(struct node * root , int hor)
{
	if(root)
	{
		m[hor] += root -> val; 	
		verticalOrder(root->left,hor-1) ;
		verticalOrder(root->right,hor+1) ;	
	}
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
	
	verticalOrder(root,0);
	map<int,int > :: iterator it ;
	for(it = m.begin() ; it!=m.end() ; it++)
	{
		cout<< it->second <<endl;
		
	}
}
