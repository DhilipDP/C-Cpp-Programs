#include<iostream>
#include<limits.h>
using namespace std ;


struct Node{
	char val ;
	struct Node * left ;
	struct Node * right ;
	Node(char x) : val(x) , left(NULL) , right(NULL) {}
	
};


int traverse(struct Node * root , char key, bool &visited, int &res)
{
	if(root ==  NULL)
		return 10000 ;	
	if(root->left == NULL && root ->right==NULL){
		if(root->val == key)
			res = 0;
		return 1;
	}
	bool left_visit = false ;
	int ld = traverse(root->left , key,visited,res) ;
	if(visited )
		left_visit = true ; 
	int rd = traverse(root->right , key , visited , res) ;
	
	int cur_min = min(ld,rd) ;
	
	if(root->val == key){
		visited  = true ;
		res =  min(ld,rd);
		return 1;
	}
	if(visited){
		res = min(res,ld+rd) ;
		if(left_visit)
			return ld+1 ;
		else
			return rd+1 ;
	}
	return cur_min + 1;
}

int findClosest(struct Node * root,char key)
{
	int res = INT_MAX; 
	bool key_visited = false ;
	traverse(root,key,key_visited,res) ;
	return res;
}

int main()
{
	// Let us construct the BST shown in the above figure
	struct Node *root        = new Node('A');
	root->left               = new Node('B');
	root->right              = new Node('C');
	root->right->left        = new Node('E');
	root->right->right       = new Node('F');
	root->right->left->left  = new Node('G');
	root->right->left->left->left  = new Node('I');
	root->right->left->left->right = new Node('J');
	root->right->right->right      = new Node('H');
	root->right->right->right->left = new Node('K');
 
	char k = 'H';
	cout << "Distace of the closest key from " << k << " is "
		<< findClosest(root, k) << endl;
	k = 'C';
	cout << "Distace of the closest key from " << k << " is "
		<< findClosest(root, k) << endl;
	k = 'E';
	cout << "Distace of the closest key from " << k << " is "
		<< findClosest(root, k) << endl;
	k = 'B';
	cout << "Distace of the closest key from " << k << " is "
		<< findClosest(root, k) << endl;
 
	return 0;
}
