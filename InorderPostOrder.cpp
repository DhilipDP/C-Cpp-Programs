#include<iostream>
#include<vector>
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
  
  void postorder(TreeNode * root){
  	if(root){
  		postorder(root->left);
  		postorder(root->right);
  		cout<<root->val<<" ";
	}
  }
  int find(vector<int> v,int val,int low,int high){
  	for(int i=low  ; i<=high ; i++){
  		if(v[i]==val)
  			return i;
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
	int rt = postorder[ps+no-1];
	int index = find(inorder,rt,0,inorder.size()-1);
	root = new TreeNode(rt);
	int ls = index - ins ;
	int rs = no - ls -1;
	root->left = build(inorder,postorder,ins,ps,ls);
	root->right = build(inorder,postorder,index+1,ps+ls,rs);
	return root;	
  		
  }
  
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder,postorder,0,0,postorder.size());
    }
int main(){
	vector<int> in;
	vector<int> post;
	in.push_back(4);
	in.push_back(2);
/*	in.push_back(5);
	in.push_back(1);
	in.push_back(6);
	in.push_back(3);
	in.push_back(7);*/
	post.push_back(4);
//	post.push_back(5);
	post.push_back(2);
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
