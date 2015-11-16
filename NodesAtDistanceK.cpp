#include<iostream>

using namespace std ;


struct TreeNode {
	int val ;
	TreeNode * left ;
	TreeNode * right ;
	TreeNode(int x) : val(x) , left(NULL) , right(NULL) {}
	
};


void printDown(TreeNode * root,int k)
{
	if(root== NULL || k<0)
		return ;
	if(k==0)
		cout<<root->val<<" ";
	printDown(root->left , k-1) ;
	printDown(root->right,k-1) ;
}
int printKthnode(TreeNode * root, TreeNode * node ,int k)
{
	
	if(root == NULL)
		return -1;
	//cout<<root->val <<endl;
	if(root ==  node)
	{
	//	cout<<"Print DOwn"<<endl;
		printDown(root,k) ;
		return 1;
	}
	int ld = printKthnode(root->left,node,k);
	if(ld != -1){
		if(k == ld)
			cout<<root->val<<" ";
		printDown(root->right,k-ld-1) ;
		return ld+1;
	}
	int rd = printKthnode(root->right,node,k) ;
	if( rd != -1){
	//	cout<<"hey"<<root->val<<" "<<k-rd-1<<endl;
		if(k==rd)
			cout<<root->val<<" ";
		printDown(root->left,k-rd-1) ;
		return rd+1;
	}
	return -1;
}
int main()
{
	
	TreeNode * root = new TreeNode(1) ;
	root -> right = new TreeNode(2) ;
	root -> right -> left = new TreeNode(3) ;
	root -> right -> left  -> left =  new TreeNode(9);
	root -> right -> left  -> right =  new TreeNode(12);
	root -> right -> right = new TreeNode(4) ;
	root -> right -> right -> right = new TreeNode(5) ;
	root -> right -> right -> right -> left = new TreeNode(6);
	root -> right -> right -> right -> right = new TreeNode(7);	
	root -> right -> right -> right -> right ->right = new TreeNode(10) ;
	printKthnode(root,root->right->right,3) ;	
}
