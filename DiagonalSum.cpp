#include<iostream>
#include<queue>
#include<map>
using namespace std ;


struct node{
	int val ;
	int vd ;
	struct node * left, * right ;
	node(int x) : val(x),vd(0),left(NULL),right(NULL){};
};


void diagonalSum(struct node * root){
//	cout<<"jmlj";
	queue<node *> q ;
	q.push(root);
	map<int ,int> m;
//	cout<<"hi" ;
int i=0 ;
	while(!q.empty()){
		node * t = q.front() ;
		q.pop() ;
		int d = t->vd ;
		while(t!=NULL){
			m[d] = m.count(d)==0 ?  t->vd : m[d] + t->val;
			if(t -> left){
				t->left->vd = d+1 ;
				q.push(t->left);
			}
			t = t->right ; 
	
		}
	}
	while(m.count(i)!=0)
		cout<<m[i++]<<endl ;
	
}


int main() {
	struct node * root = new node(1) ;
	root -> left = new node(2) ;
	root-> right = new node(3) ;
       root->left->left = new node(9);
        root->left->right = new node(6);
        root->right->left = new node(4);
        root->right->right = new node(5);
        root->right->left->left = new node(12);
        root->right->left->right = new node(7);
        root->left->right->left = new node(11);
        root->left->left->right = new node(10);
      diagonalSum(root);
}

