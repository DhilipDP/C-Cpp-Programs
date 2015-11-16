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


void bottomView(struct node * root , int lev,int hor,map<int , node *> &m,map<node *,int> &level)
{
	if(root)
	{
	
			struct node * t = m[hor];
			if(lev >= level[t] )
				m[hor] = root ;
		
		level[root] = lev;	
		bottomView(root->left,lev+1,hor-1,m,level) ;
		bottomView(root->right,lev+1,hor+1,m,level) ;	
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
	cout<<"Bottom View: "<<endl;
	map<node*,int> level;
	map<int , node *> bot ;
	bottomView(root,0,0,bot,level) ;
	map<int,node *> :: iterator it ;
	for(it = bot.begin() ; it!=bot.end() ; it++)
	{
		struct node * t = it->second ;
		cout<<t->val<<" ";
	}
}
