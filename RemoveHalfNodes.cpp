#include<iostream>
#include<stdlib.h>
using namespace std ;



struct TreeNode{
	int val ;
	struct TreeNode * left;
	struct TreeNode * right ;
	TreeNode(int x) : val(x) , left(NULL) , right(NULL){}
};


void inorder(TreeNode * root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}

TreeNode * removeHalf(TreeNode * root){
	if(root == NULL)
		return NULL;
	root -> left = removeHalf(root->left);
	root -> right = removeHalf(root->right);
	if((root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)) {
		TreeNode * temp;
		if(root->left){
			temp = root->left;
			free(root);
			return temp;
		}
		else{
				temp = root->right;
			free(root);
			return temp;
		}
	}
	return root;
}


int main(){
	TreeNode * root = new TreeNode(2);
	root -> left = new TreeNode(7);
	root -> right = new TreeNode(5);
	root -> left -> right = new TreeNode(6);
	root -> left->right->left = new TreeNode(1);
	root -> left -> right -> right = new TreeNode(11);
	root -> right -> right = new TreeNode(9);
	root -> right->right->left = new TreeNode(4);
	inorder(root);
	root = removeHalf(root);
	cout<<endl;
	inorder(root);
}
