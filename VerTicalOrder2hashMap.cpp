#include<iostream>
#include<queue>
#include<map>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

using namespace std;

//print Binary Tree in Vertical Order 
//USING HASHMAP!!

struct Bnode {
	int data ;
	struct Bnode * left;
	struct Bnode * right;
};

queue<struct Bnode *> que ;
struct Bnode * root;
void insert( int val){
	if(root == NULL){
		root = new Bnode ;
		root->data = val;
		root->left = root->right = NULL;	
		que.push(root);
	}
	else{
//		cout<<"hi";
		struct Bnode * nn = new Bnode;
		nn -> data = val ;
		nn ->left = nn->right = NULL;
		struct Bnode * front = que.front();
		if(front->left==NULL)
			front->left = nn;
		else if(front->right==NULL)
			front->right = nn;
		else{
			que.pop();
			que.front()->left = nn;
		}
		que.push(nn);
	}

}

void levelOrder(struct Bnode * root){
	int count = 0,i=0;
	queue<struct Bnode *> q;
	q.push(root);
	struct Bnode * t = root;
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

void getVerticalOrder(struct Bnode * t,int hd,map<int , vector<int> > &m ){
	if(t==NULL)
		return ;
	m[hd].push_back(t->data);
	getVerticalOrder(t->left,hd-1,m);
	getVerticalOrder(t->right,hd+1,m);
}

void verticalOrder(struct Bnode * root){
	map<int , vector<int> > m ;
	getVerticalOrder(root,0,m);
	
	map<int, vector<int> > :: iterator it ;
	for(it = m.begin() ; it!=m.end() ; it++){
		for(int i=0 ; i<it->second.size() ; i++)
			cout<<it->second[i]<<" ";
		cout<<endl;
	}
}

int main(){
	root = NULL;
	int n;
	cin>>n;
    int i ;
	for(i=0 ; i<n ; i++){
		int val;
		cin>>val;
		insert(val);
	}	
	cout<<"Level Order:\n";
	levelOrder(root);
	cout<<"\nVertical Order\n";
	verticalOrder(root);
}
