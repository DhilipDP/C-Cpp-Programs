#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std ;


/*
eg: array:{1,2,3,4,5,6,7}   n=3
            1
    2      3     4
5   6  7

*/
struct node{
	int data;
	int degree;
	struct node ** children;
};

void insert(struct node *&root,int val,int n,queue<node *> &q){
	cout<<"Inserting "<<val<<" ";
	int i;
	struct node * newnode = new node ;
	newnode -> data = val ;
	newnode -> degree = n;
	newnode -> children = new struct node* [n];
	for(i =0 ; i<n ; i++)
		newnode->children[i]=NULL;
	if(root==NULL)
	{
			root = newnode ;
			q.push(root);
			cout<<"at root"<<endl ;
			return ;
	}
	struct node * f = q.front();
	for( i=0 ; i<f->degree ; i++){
		if(f->children[i]==NULL){
			cout<<"as child of "<<f->data<<endl;
			f->children[i]=newnode ;
			break;
		}
	}
	if(i==f->degree)
	{
		q.pop();
		f = q.front();
		f->children[0]=newnode ;
		cout<<"as child of "<<f->data<<endl;
	}
	q.push(newnode);
}

void levelOrder(struct node * t,int n){

	int level = 0;
	int count = 0;
	if(t==NULL){
		cout<<"The Tree is EMPTY"<<endl;
		return ;
	}
	struct node *  temp ;
	queue<node *> q ;
	q.push(t);
	while(!q.empty()){
		temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		count++;
		if(count == pow(n,level))
			cout<<endl,level++,count=0;
		for(int i=0 ; i<n ; i++){
			if(temp->children[i])
				q.push(temp->children[i]);
		}
	}		
}

int main(){
	int n;
	struct node * root = NULL ;
	queue<node *> q ;
	cout<<"\nNumber of nodes: ";
	int number_of_nodes ;
	cin>>number_of_nodes ;
	while(number_of_nodes--){
		int val,deg ;
		cin>>val ;
		cin>>deg;
		insert(root,val,deg,q);
	}
	cout<<"\nBuilt:\n";
//	levelOrder(root,n);
}
