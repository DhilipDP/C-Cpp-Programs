#include<iostream>
#include<queue>
#include<math.h>
#include<stdlib.h>
using namespace std ;
// construct a binary tree from inorder and preorder traversals

struct node{
	int data ;
	struct node * left ;
	struct node * right ; 
};



int search(int arr[],int st,int end,int num){
	for(int i=st ; i<=end ; i++)
		if(arr[i] ==  num)
			return i;
}
int preindex = 0;
struct node * buildTree(int inorder[],int preorder[],int inS , int inE){
	if(inS > inE)
		return NULL ;
	struct node * t = new node;
	t->data =  preorder[preindex++];
	t->left = t->right = NULL;
	if(inS == inE)
		return t;
	int inindex = search(inorder,inS,inE,t->data);
	t->left = buildTree(inorder,preorder,inS,inindex-1);
	t->right = buildTree(inorder,preorder,inindex+1,inE);
	return t;
}

void levelOrder(struct node * root){
	int count = 0,i=0;
	queue<struct node *> q;
	q.push(root);
	struct node * t = root;
	while(!q.empty()){
		cout<<t->data<<" ";
		count++;
		if(count==pow(2,i)){
			cout<<endl;
			count = 0;
			i++;
		}
		q.pop();
		if(t->left)
			q.push(t->left);
		if(t->right)
			q.push(t->right);
		t = q.front() ;
	}
}

int main(){
	int inorder[] = {4,2,5,1,6,3,7};
	int preorder[] = {1,2,4,5,3,6,7};
	int len = sizeof(inorder)/sizeof(inorder[0]);
	struct node * root = new node ;
	root  = buildTree(inorder,preorder,0,len-1);
	levelOrder(root);
}
