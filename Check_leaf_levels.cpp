#include<iostream>

using namespace std ;

struct node{
	int data : 4;
	struct node * left ;
	struct node * right ;
};


struct node * newnode(int data){
	struct node * p = new node ;
	p->data =  data ;
	p->left = p->right = NULL ;
	return p;
}


bool check_leaf_levels(struct node * root,int &leaf,int level){
	if(root== NULL)
		return true ;
	if(root->left==NULL && root->right==NULL ){
		if(leaf==-1){
			leaf = level ;
			return true ;
		}
		return level==leaf ? true : false ;
	}
	return check_leaf_levels(root->left,leaf,level+1) && check_leaf_levels(root->right,leaf,level+1);
}

int main(){
	struct node * head = newnode(12);	
	head->left = newnode(5);
//	head->right = newnode(7);
	head->left->left = newnode(3);
	head->left->right =  newnode(9);
	head->left->right->left = newnode(2);
	head->left->left->left = newnode(1);
	int leaf = -1 ;
	
	cout<<check_leaf_levels(head,leaf,0);
}
