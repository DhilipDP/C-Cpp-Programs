#include<stack>
#include<iostream>
using namespace std ;

struct node{
	int val ;
	struct node * left ;
	struct node * right ;
	node(int x) : val(x) , left(NULL) , right(NULL) {}
};

void spiralOrder(struct node * root)
{
	if(!root)
		return ;
	stack<node *> s1 ;
	stack<node *> s2 ;
	s1.push(root) ;
	while(!s1.empty() || !s2.empty()){
		cout<<endl;
		while(!s1.empty()){
			struct node * t = s1.top() ;
			cout<<t->val<<" ";
			s1.pop() ;
			if(t->left)
				s2.push(t->left);
			if(t->right)
				s2.push(t->right);
		}
		cout<<endl;
		while(!s2.empty()){
			struct node * t = s2.top() ;
			cout<<t->val<<" ";
			s2.pop() ;
		
			if(t->right)
				s1.push(t->right);
			if(t->left)
				s1.push(t->left);
		}
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
    spiralOrder(root) ;
}
