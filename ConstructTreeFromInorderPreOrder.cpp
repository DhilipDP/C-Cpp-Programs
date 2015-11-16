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

void inorder(struct node * root,int *in,int &index)
{	if(root){
		inorder(root->left,in,index);
		in[index++] = root->val ;
		inorder(root->right,in,index);
	}
}


void preorder(struct node * root,int *in,int &index)
{
	if(root){
		in[index++] = root->val ;
		preorder(root->left,in,index);
		preorder(root->right,in,index);
	}
}


void postorder(struct node * root,int *a,int &index)
{
	if(root){
		postorder(root->left,a,index);
		postorder(root->right,a,index);
		a[index++] = root -> val; 
	}
}


int search(int *arr,int s,int e,int val)
{
	for(int i=s ; i<=e ; i++)
		if(arr[i] == val)
			return i;
}

struct node * buildTree(struct node * root,int *in,int *pre,int inS,int inE)
{
	static int index ;
	if(inS > inE)
		return NULL ;
	root = new node(pre[index++]) ;
	if(inS==inE)
		return root ;
	int in_index = search(in,inS,inE,root->val);
	root -> left = buildTree(root->left,in,pre,inS,in_index-1) ;
	root -> right = buildTree(root->right,in,pre,in_index+1,inE) ;
	return root ;
	
}



struct node * build(struct node * root,int *in,int *post,int inS,int inE)
{
	static int ind = inE;
	if(inS > inE)
		return NULL ;
	root = new node(post[ind--]) ;
	if(inS == inE)
		return root ;
	int in_index = search(in,inS,inE,root->val) ;
	root -> right = build(root -> right , in ,post,in_index+1,inE );
	root -> left = build(root -> left , in ,post,inS,in_index-1);
	return root ;
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
   
  /*  root = new node(20);
    root -> left = new node(8) ;
    root -> right = new node(22);
    root -> right -> left = new node(4);
    root -> left -> left = new node(5) ;
    root -> left -> right = new node(3) ;
    root -> right -> right = new node(25) ;
    root -> left->right->left = new node(10); 
    root -> left -> right -> right = new node(14);  */
    
    struct node * root1 = new node(1) ;
    root1 -> left = new node(2) ;
    root1 -> left->right = new node(3) ;
    /*root1 -> left -> right = new node(4) ;
    root1 -> left -> right -> right = new node(5) ;
    root1 -> left -> right->right ->right =  new node(6) ;*/
    int ino[100],pre[100] ;
    int in_index = 0;
    inorder(root1,ino,in_index);
	int pre_index = 0;
	preorder(root1,pre,pre_index);
	cout<<"Before Constructing:\n"<<endl;
	for(int i=0 ;i<in_index ; i++)
		cout<<ino[i]<<" ";
	cout<<endl;
		for(int i=0 ;i<pre_index ; i++)
		cout<<pre[i]<<" ";
	cout<<endl;
	struct node * root2 = NULL;
	root2 = buildTree(root2 ,ino , pre,0,in_index-1) ;
	 in_index = 0;
    inorder(root1,ino,in_index);
	 pre_index = 0;
	preorder(root1,pre,pre_index);
	cout<<"After Constructing:\n"<<endl;
	for(int i=0 ;i<in_index ; i++)
		cout<<ino[i]<<" ";
	cout<<endl;
		for(int i=0 ;i<pre_index ; i++)
		cout<<pre[i]<<" ";
	cout<<endl;
	cout<<endl<<"--------------"<<endl;
	int post[100];
	in_index = 0;
    inorder(root1,ino,in_index);
	 int post_index = 0;
	postorder(root1,post,post_index);
	cout<<"Before Constructing:\n"<<endl;
	for(int i=0 ;i<in_index ; i++)
		cout<<ino[i]<<" ";
	cout<<endl;
	for(int i=0 ;i<post_index ; i++)
		cout<<post[i]<<" ";
	struct node * root3 = build(root3,ino,post,0,in_index-1);
	cout<<"After Constructing:\n"<<endl;
		in_index = 0;
    inorder(root3,ino,in_index);
	  post_index = 0;
	postorder(root3,post,post_index);
	for(int i=0 ;i<in_index ; i++)
		cout<<ino[i]<<" ";
	cout<<endl;
		for(int i=0 ;i<post_index ; i++)
		cout<<post[i]<<" ";
	cout<<endl;
}

