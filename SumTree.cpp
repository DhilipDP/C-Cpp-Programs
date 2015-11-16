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
			cout<<root->val<<" ";
			inorder(root->right) ;
		}
}



bool isSumTree(struct node * root,int &sum)
{
		if(root==NULL)
		{	
			sum = 0;
			return true;
		}
		if(root -> left == NULL && root->right==NULL) //leaf
		{
			sum = root -> val ;
			return true ;
		}
		int lSum = 0,rSum = 0;
		bool l = isSumTree(root->left,lSum) ;
		bool r = isSumTree(root->right,rSum) ;
		sum = root->val + lSum + rSum ;
		return (l && r && (root->val == lSum+rSum) );
}



struct node * convert(struct node * root,int &sum)
{
	if(root==NULL)
	{
		sum=0;
		return NULL ;
	}
	int lsum = 0,rsum = 0;
	root->left = convert(root->left,lsum) ;
	root -> right = convert(root->right,rsum) ;
	sum = 	root->val + lsum + rsum ;
	root->val = lsum + rsum ;
	return root ;
	
}

int main()
{
	struct node * root = NULL ;
	/*
	
    	  26
        /   \
      10     3
    /    \     \
  4      6      3    */
   
    root = new node(10);
    root -> left = new node(-2) ;
    root -> right = new node(6);
    root -> right -> right = new node(5);
    root -> right -> left = new node(7) ;
    root -> left -> left = new node(8) ;
    root -> left -> right = new node(-4) ;
  	int sum = 0;
  	inorder(root) ;
	if(isSumTree(root,sum)){
		cout<<"\nSum Tree "<<sum<<endl;
	}
	else{
		cout<<"Not Sum Tree"<<endl;
		int sum=0;
		root = convert(root,sum) ;
		cout<<endl ;
		inorder(root) ;
		cout<<endl;
	
	}
	struct node *root1  = new node(-1);
    root1->left         = new node(-1);
    root1->right        = new node(0);
     root1->right->left  = new node(-2);
    root1->right->right = new node(3);
    inorder(root1) ;
 	if(isSumTree(root1,sum)){
		cout<<"\nSum Tree "<<sum<<endl;
	}
	else{
		cout<<"Not Sum Tree"<<endl;
		int sum=0;
		root1 = convert(root1,sum) ;
		cout<<endl;
		inorder(root1);
	}
}
