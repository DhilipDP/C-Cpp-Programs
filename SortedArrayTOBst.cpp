#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



TreeNode * sortedArrayToBST(vector<int> &num,int n,int &index){
	if(n <=0 )	
		return NULL;
	TreeNode * left = sortedArrayToBST(num,n/2,index);
	TreeNode * root = new TreeNode(num[index]);
	root -> left = left ;
	index++;
	root -> right = sortedArrayToBST(num,n-n/2-1,index);
	return root;
	
}

TreeNode * sortedArrayToBST(vector<int> &num){
	int index = 0;
	return 	sortedArrayToBST(num,num.size(),index);
}


void inorder(TreeNode * t){
	if(t!=NULL){
		inorder(t->left);
		cout<<t->val<<endl;
		inorder(t->right);
	}	
}

int main(){
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
		num.push_back(4);
			num.push_back(5);
		num.push_back(6);
	TreeNode * root = NULL;
	root = sortedArrayToBST(num);
	inorder(root);
}
