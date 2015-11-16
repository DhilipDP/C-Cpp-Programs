#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<stdio.h>
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
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


void preorder(TreeNode * t){
	if(t!=NULL){
		cout<<t->val<<" ";
		preorder(t->left);
		
		preorder(t->right);
	}	
}

int main()
{
	int n;
	s(n);
	while(n--){
		int no ,k=0;
		s(no);
		vector<int> v;

		while(no--){
			int val;
			s(val);
			v.push_back(val);
			//root = insert(root,val);
		}
		sort(v.begin(),v.end());
		TreeNode * root = NULL;
		root =sortedArrayToBST(v);
		preorder(root);
		printf("\n");
	}
  return 0;
}
