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



string convert(int num)
{
	string s ;
	if(num==0)
		return "0";
	while(num > 0)
	{
		s += (num%10 +'0') ;
		num/=10;
	}
	reverse(s.begin() ,s.end());
	return s ;
}

void printRootToLeafPath(struct node * root,string s)
{
	if(root)
	{
		string t;
		t = convert(root->val);
		s += (t) + ' '  ;
		if(root -> left == NULL && root -> right == NULL)
			cout<<s<<endl;
		printRootToLeafPath(root->left,s);
		printRootToLeafPath(root->right,s);
	}
}


bool doesPathExist(struct node *root,int k,int sum,string s)
{
	if(root)
	{
		sum += root->val ;
		s += convert(root->val) + ' ' ;
		if(root->left==NULL && root->right==NULL && sum==k)
		{
			cout<<s<<endl;
			return true ;
		}
		return (doesPathExist(root->left,k,sum,s) || doesPathExist(root->right,k,sum,s));
		
	}
	return false ;
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
    string s = "";
    printRootToLeafPath(root,s);
    cout<<doesPathExist(root,5,0,s) ;
}
