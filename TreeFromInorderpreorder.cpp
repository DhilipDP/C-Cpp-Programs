#include<iostream>
#include<vector>
#include<limits.h>
using namespace std ;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  void inorder(TreeNode * root){
  	if(root){
  		inorder(root->left);
  		cout<<root->val<<" ";
  		inorder(root->right);
	}
  }
  
  void preorder(TreeNode * root){
  	if(root){
  		cout<<root->val<<" ";
  		preorder(root->left);
  		preorder(root->right);
  		
	}
  }
  
  
int *arr;
int maxi = INT_MIN;
       int mini = INT_MAX ;
  TreeNode * build(int inOrder[],int preOrder[],int ins,int ps,int no){
  		if(no <=0)
  			return NULL;
  		TreeNode * root = new TreeNode(preOrder[ps]);
  		if(no==1)
  			return root;
  		int index = arr[root->val+mini];
  		int ls =  index-ins;
  		int rs = no-ls-1;
  		root -> left = build(inOrder,preOrder,ins,ps+1,ls);
  		root -> right = build(inOrder,preOrder,index+1,ps+ls+1,rs);
  		return root;
  }
   TreeNode *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        int inOrder[n],preOrder[n];
        vector<int> :: iterator it;
        int i=0,p=0;
        for(it = inorder.begin() ; it!=inorder.end() ; it++){
        	inOrder[i++] = *it;
        	if(*it > maxi)
        		maxi = *it;
        	if(*it < mini)
        		mini = *it;
		}
		for(it = preorder.begin() ; it!=preorder.end() ; it++){
			preOrder[p++] = *it;
		}
		if(mini < 0)
			mini = -mini;
		else
			mini = 0;
		arr = new int[maxi+mini+1];
		for(int j=0 ; j<n ; j++)
			arr[inOrder[j]+mini]= j;
		cout<<"hi";
		return build(inOrder,preOrder,0,0,n);
    }
int main(){
	vector<int> in;
	vector<int> pre;
	in.push_back(5);
	in.push_back(4);
	in.push_back(1);
	in.push_back(2);
	in.push_back(3);
/*	in.push_back(3);
	in.push_back(7);*/
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(3);
	pre.push_back(4);
	pre.push_back(5);
/*	post.push_back(3);
	post.push_back(1);	*/
	TreeNode * root = buildTree(in,pre);
	cout<<endl;
	inorder(root);
	cout<<endl;
	preorder(root);
	
}
