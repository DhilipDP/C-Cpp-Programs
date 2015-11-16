#include<iostream>
#include<vector>
using namespace std ;


struct node{
	int val ;
	int lis ;
	struct node * left ;
	struct node * right ;
	vector<node *> v;
	node(int x) : val(x),lis(0),left(NULL),right(NULL){}
};


int LISS(struct node * root){
	if(root == NULL)
		return 0;

	int size_excl =  LISS(root->left) + LISS(root->right);
	int size_incl =1 ;
	if(root->left)
		size_incl +=  LISS(root->left->left) + LISS(root->left->right);
	if(root->right)
		size_incl += LISS(root->right->left) + LISS(root->right->right);
	return max(size_excl,size_incl);
		

}


int liss(struct node * root){
	
	if(root==NULL)
		return 0;
	if(root->lis)
		return root->lis ;
	if(root->left==NULL && root->right ==NULL)
	{
		root->lis = 1;
		root->v.push_back(root);
		//root->inc = true ;
		return 1 ;
	}
	int size_excl = liss(root->left) + liss(root->right);
	int size_incl =1 ;
	if(root->left)
		size_incl +=  LISS(root->left->left) + LISS(root->left->right);
	if(root->right)
		size_incl += LISS(root->right->left) + LISS(root->right->right);
	root-> lis = max(size_incl,size_excl);
//	cout<<root->val<<" "<<root->lis<<endl;
	if(size_incl > size_excl){
		root->v.push_back(root);
		if(root->left){
			root->v.push_back(root->left->left);
			root->v.push_back(root->left->right);
		}
		if(root->right){
			root->v.push_back(root->right->left);
			root->v.push_back(root->right->right);
		}
	}
	else{
		root->v.push_back(root->left);
		root->v.push_back(root->right);
	
	}
	return root->lis;
	

}


void inorder(struct node * root){
	if(root){
	inorder(root->left);
	cout<<root->val<<" "<<root->lis<<endl;
	inorder(root->right);
	}	
}


void print(struct node * root){
	if(root){
		vector<node *> vec ;
		vec = root->v ;
		vector<node *> :: iterator it ;
		for(it = vec.begin() ; it!=vec.end() ; it++)
			{
				if(*it == root)
					cout<<root->val<<endl;
				else
				print(*it);
			}
	}
}


int  main(){
	 struct node *root         = new node(10);
    root->left                = new node(20);
    root->left->left          = new node(40);
    root->left->right         = new node(50);
    root->left->right->left   = new node(70);
    root->left->right->right  = new node(80);
    root->right               = new node(30);
    root->right->right        = new node(60);
	cout<<endl<<LISS(root);
	cout<<endl<<liss(root);
	cout<<endl;
	print(root);
}
