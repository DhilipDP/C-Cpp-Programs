

#include<iostream>
#include<stdlib.h>
using namespace std;
 // Definition for binary tree
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 
 void path(TreeNode * root,string s,int &sum){
 	if(root){
 		s += (root->val + '0');
 		if(root->left==NULL && root->right==NULL){
 		//	cout<<"hi";
 			sum += atoi(s.c_str());
 		}
 		path(root->left,s,sum);
 		path(root->right,s,sum);
 	}
 }
    int sumNumbers(TreeNode *root) {
        string s="";
        int sum = 0;
        path(root,s,sum);
        return sum;
    }


int main(){
	TreeNode * root = new TreeNode(1);
	TreeNode * n = new TreeNode(2);
	root->left = n;
	root -> right = new TreeNode(3);
	root->left->left = new TreeNode(5);
	cout<<sumNumbers(root);
}
