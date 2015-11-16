#include<iostream>
#include<queue>

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

int height(struct node * t){
	if(t==NULL)
		return 0;
	int lheight = height(t->left);
	int rheight = height(t->right);
	return lheight > rheight ? (lheight+1) : (rheight+1) ;
}

void printLevel(int level , struct node * t){
	if(level==1)
		cout<<t->data<<" ";
	else{
		printLevel(level-1,t->left);
		printLevel(level-1,t->right);
	}
}
void printlevelOrder(struct node * root){
	if(root==NULL){
		cout<<"Tree is empty"<<endl;
		return ;
	}
	for(int h=1 ; h<=height(root) ; h++){
		printLevel(h,root);
	}
}
int main(){
	//Inserting into a Binary tree
	int num;
	cout<<"Number of nodes:\n";
	cin>>num;
	cout<<"\nEnter the values one by one";
	for(int i=1 ; i<=num ; i++){
		int val;
		cin>>val;
		insert(val);
	}
	cout<<"\nLevel Order traversal!\n";
	printlevelOrder(root);
	cout<<endl;
}
