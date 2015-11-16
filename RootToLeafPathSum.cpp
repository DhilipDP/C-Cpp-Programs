#include<iostream>
using namespace std ;


struct node{
	int val;
	struct node * left;
	struct node * right;
	node(int x) : val(x),left(NULL),right(NULL){};
};



bool isLeaf(struct node * root){
		if(root->left==NULL && root->right==NULL)
			return true;
		return false;
	}


void find(struct node * root,int sum,int &t_sum){
	
	if(root==NULL)
		return ;
	sum = sum*10+root->val;
	if(isLeaf(root))
		t_sum += sum;
	find(root->left,sum,t_sum);
	find(root->right,sum,t_sum);
}
int findSum(struct node * root){
	int sum = 0,t_sum=0;
	find(root,sum,t_sum);
	return t_sum ;
}


int main(){
	
	struct node * root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	root -> left -> right = new node(5);
	cout<<findSum(root);
	
}
