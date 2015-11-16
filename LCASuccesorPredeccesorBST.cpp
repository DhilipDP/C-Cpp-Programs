#include<iostream>
#include<stdlib.h>
#include<queue>
#include<math.h>
using namespace std ;

struct node{
	int data;
	struct node * left ;
	struct node * right ;
};

struct node *  insert(struct node *&t ,int val){
	if(t==NULL){
		t = new node ;
		(t)->data =  val ;
		(t)->left = (t)->right = NULL;
	}	
	else if(val < t->data)
		t->left = insert(t->left,val);
	else 
		t->right = insert(t->right,val);
	return t ;
	
}

void inorder(struct node * t){
	if(t!=NULL){
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
}

struct node * lca (struct node * t ,int n1,int n2){

	if(t==NULL)
		return NULL;
	if(t->data > n1 && t->data > n2)
		return lca(t->left,n1,n2);
	if(t->data < n1 && t->data < n2)
		return lca(t->right,n1,n2);
	return t ;	
}

void findLca(struct node * t,int n1,int n2){
	struct node * temp = lca(t,n1,n2);
	cout<<temp->data<<endl;
}

struct node * getNode(struct node * t,int key){
	if(t==NULL)	
		return NULL ;
	if(t->data==key)
		return t ;
	if(key > t->data)
		return getNode(t->right,key);
	return getNode(t->left,key);
}

int findMin(struct node * t){
	while(t->left){
		t=t->left;
	}
	return t->data ;
}
void findSuccessor(struct node * t,int key){
	struct node * n = getNode(t,key);
	if(n->right)
	{
	cout<<findMin(n->right)<<endl;
	}
	else{
		struct node * succ =NULL ;
		while(t){
			if(key < t->data ){
				succ =t ;
				t=t->left ;
			}
			else if(key > t->data)
				t=t->right ;
			else
				break ;
		}
		if(succ)
			cout<<succ->data<<endl;
		else
			cout<<"No Succesor\n";
	}
}

int findMax(struct node * t){
	while(t->right){
		t =t->right ;
	}
	return t->data;
}


int height(struct node * t){
	if(t==NULL)
		return -1 ;
	int lh = height(t->left);
	int rh = height(t->right);
	
	return lh > rh ? lh + 1: rh+1 ;
}
bool isBalanced(struct node * t){
	if(t==NULL)
		return true ;
	int lh = height(t->left) ;
	int rh = height(t->right) ;
//	cout<<"Checking: "<<lh <<" "<<rh<<endl;
	if(abs(lh-rh) <= 1 && isBalanced(t->left) && isBalanced(t->right))
		return true ;
	return false ; 
}
void findPredecessor(struct node * t,int key){
	struct node * n = getNode(t,key);
	
	if(n->left){
		cout<<findMax(n->left)<<endl;
	}
	else{
		struct node * pre = NULL ;
		while(t){
			if(n->data < t->data)
				t = t->left ;
			else if(n->data > t->data){
				pre= t ;
				t=t->right;
			}
			else
			 break;
		}
		if(pre)
			cout<<pre->data<<endl ;
		else
			cout<<"no predecessor"<<endl;
	}
}

void printGivenLevel(struct node * t,int level){
	if(t==NULL)
		return ;
	if(level==0){
		cout<<t->data<<" ";
	}
	else{
		printGivenLevel(t->left,level-1);
		printGivenLevel(t->right,level-1);
	}
}

void levelOrder(struct node * root){
	if(root == NULL){
		cout<<"The Tree is EMPTY"<<endl;
		return ;
	}
	int h = height(root);
	cout<<"The height is :"<<h<<endl;
	int i;
	for(i=0 ; i<=h ; i++)
		printGivenLevel(root,i),cout<<endl;
}

int main(){
	struct node * root=NULL;
	insert(root,7);
	insert(root,11);
	insert(root,3);
	insert(root,8);
	insert(root,2);
	insert(root,1);
	insert(root,9);

	
	inorder(root);
	cout<<endl;
	levelOrder(root);
	findLca(root,3,9);
	findLca(root,1,2);
	
	findSuccessor(root,8);
	findSuccessor(root,7);
	findSuccessor(root,11);
	findSuccessor(root,2);
	
	findPredecessor(root,8);
	findPredecessor(root,3);
	findPredecessor(root,1);
	findPredecessor(root,7);
	
	
	if(isBalanced(root))
		cout<<"\nBalanced\n";
	else
		cout<<"\nNot Balanced\n";
		
	insert(root,0);
	insert(root,-1);
	
//	cout<<endl<<height(root->right);
	
	levelOrder(root);
		
	if(isBalanced(root))
		cout<<"\nBalanced\n";
	else
		cout<<"\nNot Balanced\n";
		
	
}
