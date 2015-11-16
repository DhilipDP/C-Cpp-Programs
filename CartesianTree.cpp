#include<utility>
#include<windows.h>
#include<map>
#include<vector>
#include<iostream>
#include<limits.h>

using namespace std ;

struct node{
	int val ;
	struct node * left ;
	struct node * right ;
	node(int x) : val(x) , left(NULL) , right(NULL) {}
};


int findMax(vector<int> v,int st,int ed,int &m)
{
	int maxi = INT_MIN ;
	for(int i= st ; i<=ed ; i++)
	{
		if(v[i] > maxi)
		
		{
			m =  i;
			maxi = v[i] ;
		}
	}
	return maxi ;
}
struct node * build(struct node * root,vector<int> v,int st,int end)
{
	if(st > end)
		return NULL ;
	if(st==end)
	{
		root =  new node(v[st]) ;
		return root ;
	}
	int maxi ,maxi_index ;
	maxi = findMax(v,st,end,maxi_index) ;
	root = new node(maxi) ;
	root -> left = build(root->left,v,st,maxi_index-1) ;
	root -> right = build(root->right,v,maxi_index+1,end) ;
	return root ;

}



void inorder(struct node * root)
{
		if(root)
		{
			inorder(root->left) ;
			cout<<root->val<<" ";
			inorder(root->right) ;
		}
}

struct node * buildTree(vector<int> v)
{
	struct node * root = NULL ;
	return build(root,v,0,v.size()-1) ;
}

int main()
{

	vector<int> v; 
	v.push_back(4) ;
	v.push_back(3) ;
	v.push_back(6) ;
		v.push_back(7) ;
	v.push_back(2) ;
	v.push_back(1) ;
		v.push_back(5) ;
	node * root = buildTree(v) ;
	inorder(root) ;
}
