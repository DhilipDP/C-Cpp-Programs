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
    int ino[100],pre[100] ;
    int in_index = 0;
    inorder(root,ino,in_index);
	int pre_index = 0;
	preorder(root,pre,pre_index);
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
    inorder(root2,ino,in_index);
	 pre_index = 0;
	preorder(root2,pre,pre_index);
		cout<<endl<<"--------------"<<endl;
	cout<<"After Constructing:\n"<<endl;
	for(int i=0 ;i<in_index ; i++)
		cout<<ino[i]<<" ";
	cout<<endl;
		for(int i=0 ;i<pre_index ; i++)
		cout<<pre[i]<<" ";
	cout<<endl;

}

