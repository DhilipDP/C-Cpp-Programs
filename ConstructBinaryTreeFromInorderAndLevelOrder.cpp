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
	return -1;
}

int * extract(int in[],int level[],int size,int len){

	int *arr = new int[size],j=0;
	for(int i=0 ; i<len ; i++){
		if(search(in,0,size-1,level[i])!=-1)
			arr[j++] = level[i];
	}

	return arr;
}

struct node * buildTree(int inorder[],int levelorder[],int inS , int inE,int len){
	if(inS > inE)
		return NULL;
	struct node * t = new node ;
	t -> data = levelorder[0];
	t->left = t->right = NULL;

	if(inS == inE)
		return t;
	int inindex = search(inorder,inS,inE,t->data);
	int *leftLevel = extract(inorder,levelorder,inindex,len);

	int *rightLevel = extract(inorder+inindex+1,levelorder,len-inindex-1,len);

	t->left = buildTree(inorder,leftLevel,inS,inindex-1,len);
	t->right = buildTree(inorder,rightLevel,inindex+1,inE,len);
	
	delete []leftLevel ;
	delete []rightLevel ; 
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
	int levelorder[] = {1,2,3,4,5,6,7};
	int len = sizeof(inorder)/sizeof(inorder[0]);
	struct node * root = new node ;
	root  = buildTree(inorder,levelorder,0,len-1,len);
	levelOrder(root);
}
