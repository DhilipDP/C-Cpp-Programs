
#include<iostream>
using namespace std ;


struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
  
  bool path(TreeNode *root,int sum,int target){
  	if(root==NULL)
  		return false;
  	if(root->left==NULL && root->right==NULL)
  	{
  		sum += root->val;
  		if(sum==target)
  			return true;
  		return false;
  	}
  	return path(root->left,sum+root->val,target) || path(root->right,sum+root->val,target);
  
  }
  bool hasPathSum(TreeNode *root, int sum) {
    	int s = 0;
		return path(root,s,sum);    
	}
	
	void inorder( TreeNode * root){
		if(root){
		
		}
	}
int main()
{
	/*
           	  5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
	*/
	TreeNode * root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
		root->right->right->right = new TreeNode(1);
	cout<<hasPathSum(root,22);
}

