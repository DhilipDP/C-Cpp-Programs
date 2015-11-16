#include<stack>
#include<iostream>
using namespace std ;

struct node{
	int val ;
	struct node * left ;
	struct node * right ;
	node(int x) : val(x) , left(NULL) , right(NULL) {}
};

struct node * head ;

void convert(struct node * root){

	static struct node * pre = NULL ;
	if(root==NULL)
		return  ;
	convert(root->left);
	
	root->left = pre ;
	if(pre==NULL)
		head = root ;
	else
		pre -> right = root ;
	
	pre = root;
	convert(root->right);
}


void print_list(struct node * head)
{
	struct node * t = head ;
	while(t){
		cout<<t->val <<" ";
		
		if(t->left)
			cout<<t->left->val;
		cout<<endl;
		t = t->right;
	}
}


void print_tree(struct node * root)
{
	if(root)
	{
		print_tree(root->left) ;
		cout<<root->val<<" ";
		print_tree(root->right) ;
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
    
	print_tree(root) ;
	
	convert(root) ;

cout<<endl;
	print_list(head) ;
}
