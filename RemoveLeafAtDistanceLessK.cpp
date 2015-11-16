#include<stdlib.h>
#include<iostream>
using namespace std ;

struct node{
	int val ;
	struct node * left ;
	struct node * right ;
	node(int x) : val(x) , left(NULL) , right(NULL) {}
};

void MorrisTraversal(struct node * root)
{
	if(!root)
		return ;
	struct node * cur = root;
	while(cur)
	{
		//cout<<cur->val<<endl;
		if(cur->left==NULL)
		{
			cout<<cur->val<<" ";
			cur = cur -> right ;
		}
		else{
			struct node * t = cur->left ;
			while(t->right!=NULL && t->right!=cur)
				t = t->right ;
			if(t->right==NULL)
			{
				t->right = cur ;
				cur = cur -> left ;
			}
			else{
				t->right = NULL ;
				cout<<cur->val<<" ";
				cur = cur -> right ;
			}
		}
	}
}

struct node * removeLeaflessK(struct node * root,int level,int k)
{
	if(root==NULL)
		return NULL ;
	root -> left = removeLeaflessK(root->left,level+1,k) ;
	root -> right = removeLeaflessK(root->right,level+1,k) ;
	if(root->left==NULL && root-> right==NULL && level < k)
	{
		free(root) ;
		return NULL ;
	}
	return root;

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
 
    MorrisTraversal(root);
	root = removeLeaflessK(root,1,4);
	cout<<endl;
	MorrisTraversal(root);

}
