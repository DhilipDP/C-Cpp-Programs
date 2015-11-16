#include<iostream>
#include<queue>
#include<stdlib.h>

//children sum property
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

bool isSumProperty(struct node * t){
	int ld=0,rd=0;
	if(t==NULL || (t->left==NULL && t->right==NULL) )
		return true;
	if(t->left!=NULL)
		ld = t->left -> data;
	if(t->right!=NULL)
		rd = t->right->data;
	if(t->data == (ld+rd) && isSumProperty(t->left) && isSumProperty(t->right))
		return true;
	return false;
}

void increment(struct node * t,int diff){
//	cout<<endl<<diff;
	if(t->left)
	{
		t->left->data += diff;
		increment(t->left,diff);
	}
	else if(t->right){
		t->right->data += diff;
		increment(t->right,diff);
	}
}


void convertCS(struct node * t){
	int ld=0,rd=0,diff;
	if(t==NULL || (t->left==NULL && t->right==NULL))
		return ;
	convertCS(t->left);
	convertCS(t->right);
	if(t->left)
		ld =  t->left ->data;
	if(t->right)
		rd =  t->right -> data;
	diff =  ld + rd - t->data ;
	if(diff > 0)
		t->data += diff;
	if(diff < 0)
		increment(t,-diff);
}

void levelOrder(struct node * t){
	queue<struct node *> q;
	while(t){
		cout<<t->data<<endl;
		if(t->left)
			q.push(t->left);
		if(t->right)
			q.push(t->right);
		if(q.empty())
			t=NULL;
		else{
			t = q.front();
			q.pop();
		}
	}
}
int main(){
	//Inserting into a Binary tree
	int num;
	cout<<"Number of nodes:\n";
	cin>>num;
	cout<<"\nEnter the values one by one:\n";
	for(int i=1 ; i<=num ; i++){
		int val;
		cin>>val;
		insert(val);
	}
	cout<<"The inorder traversal is : \n";
	inorder(root);
	cout<<"The level Order traversal is : \n";
	levelOrder(root);
	if(isSumProperty(root))
		cout<<"\nYeah!!!The given binary tree possesses Children Sum Property!"<<endl;
	else{
		cout<<"\nNope!!The given tree doesnt possess Children Sum Property!"<<endl;
		cout<<"\nSo lets convert!!\n";
		convertCS(root);
		inorder(root);
		cout<<"\n";
		levelOrder(root);
	}
	return 0;
}
