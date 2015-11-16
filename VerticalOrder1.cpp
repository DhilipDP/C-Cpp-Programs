#include<iostream>
#include<queue>
#include<stdlib.h>
#include<math.h>
using namespace std ;

//print Binary Tree in Vertical Order

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

void findMaxMin(struct Bnode * t,int &max,int &min,int hd){
	if(t==NULL)
		return ;
	if(hd < min)	
		min = hd;
	else if(hd > max)
		max = hd;
	findMaxMin(t->left,max,min,hd-1);
	findMaxMin(t->right,max,min,hd+1);
}

void printVertical(struct Bnode * t,int cur_lin ,int hd){
	if(t==NULL)	
	 return;
	if(cur_lin == hd)
		cout<<t->data<<" ";
	printVertical(t->left,cur_lin-1,hd);
	printVertical(t->right,cur_lin+1,hd);
}

void verticalOrder(struct Bnode * root){
	int max=0,min=0;
	findMaxMin(root,max,min,0);
	for(int l = min ; l<=max ; l++){
		printVertical(root,0,l);
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
