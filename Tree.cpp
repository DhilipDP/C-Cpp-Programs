#include<iostream>
#include<vector>
#include<limits.h>
using namespace std ;

int *arr;
int maxi = INT_MIN;
       int mini = INT_MAX ;

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
  
  void postorder(TreeNode * root){
  	if(root){
  		postorder(root->left);
  		postorder(root->right);
  		cout<<root->val<<" ";
	}
  }
  TreeNode * build(vector<int> inorder,vector<int> postorder,int ins,int ps,int no){
  	TreeNode * root = NULL;
  	if(no<=0)
  		return root;
  	if(no==1){
  		root = new TreeNode(postorder[ps]);
  		return root;
	}
	int index = arr[postorder[ps+no-1]+mini];
	root = new TreeNode(postorder[ps+no-1]);
	root->left = build(inorder,postorder,ins,ps,index - ins );
	root->right = build(inorder,postorder,index+1,ps+index - ins ,no - index + ins  -1);
	return root;	
  		
  }
   TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
       
        for(vector<int> :: iterator it = inorder.begin() ; it!=inorder.end() ; it++)
        {
            if(maxi < *it)
                maxi = *it;
            if(mini > *it)
            	mini = *it;
        }
        mini = -mini;
        arr = new int[maxi+mini+1];
        int i=0; 
        vector<int> v;
        for(vector<int> :: iterator it = inorder.begin() ; it!=inorder.end() ; i++,it++)
        {
           arr[*it + mini]=i;
        }
        return build(inorder,postorder,0,0,postorder.size());
    }
int main(){
	vector<int> in;
	vector<int> post;
	in.push_back(2);
	in.push_back(1);
	in.push_back(3);
	/*in.push_back(1);
	in.push_back(6);
	in.push_back(3);
	in.push_back(7);*/
	post.push_back(2);
	post.push_back(3);
	post.push_back(1);
/*	post.push_back(6);
	post.push_back(7);
	post.push_back(3);
	post.push_back(1);	*/
	TreeNode * root = buildTree(in,post);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	
}
