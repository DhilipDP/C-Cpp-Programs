#include<iostream>
using namespace std ;

//right View of a binary tree


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

void rightView (struct Bnode * t,bool arr[],int level){
	if(t==NULL)
		return ;
	if(!arr[level])	{
		cout<<t->data<<endl;
		arr[level]= true;
	}
	rightView(t->right,arr,level+1);
	rightView(t->left,arr,level+1);
}

void rightView(struct Bnode * t){
	int startLevel = 0;
	bool arr[100];
	memset(arr,false,sizeof(arr));
	rightView(t,arr,startLevel); 
	
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
	cout<<"\nRight View :\n";
	rightView(root);
}
