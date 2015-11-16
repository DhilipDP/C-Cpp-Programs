#include<iostream>
#include<queue>
#include<stdlib.h>

using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * root = NULL;

queue<struct node *> que;

void insert( int val){
	if(root==NULL){
		root = new node();
		root -> data = val;
		root ->left = root -> right = NULL;
	//	cout<<"Before pushing : "<< root -> data;
		que.push(root);
	//	cout<<"After pushing " << que.front()->data;
	}
	
	else{
		struct node * newnode = new node();
		newnode -> data = val;
		newnode -> left = newnode -> right = NULL;
		struct node * n = que.front();
	//	cout<<endl<<n->data;
		if(n->left==NULL)
			n->left = newnode;
		else if(n->right == NULL)
			n->right = newnode;
		else{
			que.pop();
			struct node * ne = que.front();
			ne -> left = newnode;
		}
		que.push(newnode);
	}
}

void inorder(struct node * t){
	if(t!=NULL){
		inorder(t->left);
		cout<<t->data<<endl;
		inorder(t->right);
	}
}

void levelOrder(struct node * root){
	struct node * t = root ;
	queue<struct node *> q;
	q.push(root);
	while(!q.empty()){
		t=q.front();
		q.pop();
		cout<<t->data<<endl;
		if(t->left)
			q.push(t->left);
		if(t->right)
			q.push(t->right);
		}
}

int main(){
	//Inserting into a Binary tree
	int num;
	cout<<"Number of nodes:\n";
	cin>>num;
	cout<<"\nEnter the values one by one";
	for(int i=1 ; i<=num ; i++){
		insert(i);
	}
	inorder(root);
	levelOrder(root);
}
