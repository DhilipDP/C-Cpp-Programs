#include<utility>
#include<windows.h>
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
/*	if(root)
	cout<<root->val<<" "<<val<<endl;
	else
		cout<<root<<" "<<val<<endl; */
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

void print(map<node * , pair<int,int> > dist,int mini,int maxi)
{
	map<node *,pair<int,int> > :: iterator it ;
	string h[maxi+1][100];

	int col = -1;
	for(it = dist.begin() ; it!=dist.end() ; it++)
		{
			struct node * t = it->first ;
			pair<int,int> p = it -> second ;
			char a[100] ;
			itoa(t->val,a,10);
			string temp(a);
			h[p.first][p.second+mini] += (' ' + temp); 
			if(p.second+mini > col)
				col = p.second+mini ;
		}
	for(int i=0;i<=maxi ; i++){
		for(int j=0 ; j<=col ; j++){
			if(h[i][j] != " "){
				cout<<h[i][j];
			}
			cout<<"    ";
		}
		cout<<endl;
	}
}


void fill(struct node * root, 	map<node * , pair<int,int> > &dist ,int lev,int dis ,int &mini,int &maxi) 
{
	if(root)
	{
		pair<int,int> p = make_pair(lev,dis) ;
		dist[root] = p;
		if(dis < mini)
			mini = dis;
		if(lev > maxi)
			maxi = lev;
		fill(root->left,dist,lev+1,dis-1,mini,maxi) ;
		fill(root->right,dist,lev+1,dis+1,mini,maxi);
	}
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
	map<node* , pair<int,int> > dist ;
	int mini = 9999 ;
	int maxi = -9999 ;
	fill(root,dist,0,0,mini,maxi);
	cout<<endl;
	print(dist,-mini,maxi) ;
}
