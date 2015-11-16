#include<stack>
#include<utility>
#include<algorithm>
#include<map>
#include<vector>
#include<iostream>
using namespace std ;

struct node{
	int val ;
	struct node * left ;
	struct node * right ;
	node(int x) : val(x) , left(NULL) , right(NULL) {}
};


struct node * insert(struct node * root,int val)
{

	if(root == NULL)
		root = new node(val) ;
	else if(root->val > val)
		root->left = insert(root->left,val);
	else
		root->right = insert(root->right,val);
	return root ;
}

void inorder(struct node * root)
{	if(root){
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}


void preorder(struct node * root)
{
	if(root){
		cout<<root->val<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}


void postorder(struct node * root)
{
	if(root){
		postorder(root->left);
		postorder(root->right);
		cout<<root->val<<" ";
	}
}

void Inorder(struct node * root)
{
	if(!root)
		return  ;
	stack<node *> s ;
	struct node * cur = root ;
	while(1)
	{
		if(cur !=NULL){
			s.push(cur) ;
			cur = cur -> left ;
		}
		else{
			if(!s.empty()){
				cout<<s.top()->val<<" ";
				cur = s.top() -> right ;
				s.pop() ;
				
			}
			else
				break;
		}
		
	}
	
}


void Preorder(struct node * root)
{
	if(!root)
		return ;
	struct node * cur = root ;
	stack<node *> s ;
	s.push(root);
	while(!s.empty()){
			struct node * temp = s.top() ;
			cout<<temp->val<<" ";
				s.pop();
			if(temp->right)
				s.push(temp->right);
			if(temp->left)
				s.push(temp->left);
		
	}
}


void Postorder(struct node * root)
{
	if(!root)
		return ;
	struct node * cur = root ;
	stack<node *> s ;
	s.push(root);
	vector<int> v ;
	while(!s.empty()){
			struct node * temp = s.top() ;
		v.push_back(temp->val);
				s.pop();
		
			if(temp->left)
				s.push(temp->left);
		if(temp->right)
				s.push(temp->right);
	}
	reverse(v.begin(),v.end());
	vector<int> :: iterator it ;
	for(it = v.begin() ; it!=v.end() ; it++)
		cout<<*it<<" ";
	cout<<endl;
}

int main()
{
	struct node * root = NULL ;
	root = insert(root,7);
	root = insert(root,4) ;
	root = insert(root,11);
	root = insert(root,5) ;
	root = insert(root,9) ;
	root = insert(root,15) ;
	root = insert(root,1);
	cout<<"Inorder"<<endl;
	inorder(root);
	cout<<endl<<"Preorder"<<endl;
	preorder(root);
	cout<<endl<<"Postorder"<<endl;
	postorder(root);
	cout<<"\nWithout Recursion!"<<endl ;
		cout<<"Inorder"<<endl;
	Inorder(root);
	cout<<endl<<"Preorder"<<endl;
	Preorder(root);
	cout<<endl<<"PostOrder"<<endl ;
	Postorder(root);
}
