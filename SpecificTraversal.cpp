#include<iostream>
#include<queue>
using namespace std ;

struct node{
	int val ;
	struct node * left ;
	struct node * right ;
	node(int x) : val(x) , left(NULL) , right(NULL) {}
};


struct node * insert(struct node * root,queue<node*> &q,int val)
{
	struct node * newnode = new node(val) ;
	if(root==NULL)
		root = newnode ;
	else {
		struct node * t = q.front() ;
		if(!t->left)
			t->left = newnode ;
		else if(!t->right)
			t->right = newnode ;
		else{
			q.pop() ;
			q.front()->left = newnode ;
		}
	}
	q.push(newnode) ;
	return root ;
}

void inorder(struct node * root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
		
	}
}


void supertraversal(struct node * root){
	queue<node *> q ;
	if(!root)
		return ;
	cout<<root->val<<endl;
	if(!root->left && !root->right)
		return ;
	q.push(root->left) ;
	q.push(root->right ) ;
	q.push(NULL);
	int c=0;
	while(!q.empty())
	{
		if(q.front()==NULL)
		{
			c++;
			if(c==2)
				break;
			cout<<endl;
			q.pop();
			q.push(NULL);
			continue;
		}
		
		c=0;
		struct node * t1 = q.front() ;
		q.pop() ;
		struct node * t2 = q.front() ;
		q.pop() ;
		cout<<t1->val<<" "<<t2->val<<" ";
		if(t1->left)
			q.push(t1->left);
		if(t2->right)
			q.push(t2->right);
		if(t1->right)
			q.push(t1->right);
		if(t2->left)
			q.push(t2->left);
	
	}
	
}

int main()
{
	struct node * root=NULL ;
	queue<node*> q;
	for(int i=1 ; i<32 ; i++)
		root = insert(root,q,i) ;
	inorder(root);
	cout<<endl;
	supertraversal(root) ;
}
