#include<iostream>

using namespace std;
 
  //Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

    void swap(TreeNode *&x,TreeNode *&y){
 //      	cout<<"Swapping: "<<x->val<<" "<<y->val<<endl;
	    int temp = x->val;
        x->val = y->val;
        y->val = temp;
        //cout<<x->val<<endl;
    }
    void build(TreeNode * root,TreeNode *&first,TreeNode *&middle,TreeNode *&last,TreeNode *&pre){
        if(root){
        build(root->left,first,middle,last,pre);
        if(pre && root->val < pre->val){
            if(!first){
                first = pre ;
                middle = root;
            }
            else
                last = root;
        }
        pre = root;
        build(root->right,first,middle,last,pre);
        }
    }
    void recoverTree(TreeNode *&root) {
        TreeNode * first=NULL,*middle=NULL,*last=NULL,*pre=NULL;
        build(root,first,middle,last,pre);
        if(first && last)
            swap(first,last);
        else if(first,middle){
        //	cout<<first->val<<endl;
			    swap(first,middle);
		//	cout<<first->val<<endl;
        
		}
    }

int main(){
	TreeNode * root = new TreeNode(0);
	root->left = new TreeNode(1);
	recoverTree(root);
	cout<<root->val;
}
