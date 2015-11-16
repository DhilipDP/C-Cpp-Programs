#include<iostream>
#include<map>
#include<stdlib.h>
using namespace std ;



struct node{
	int data;
	struct node * left,*right ;
	struct node * parent ;
};


struct node * buildtree(struct node *root,string tree,int &index,int len){
	if(index < len){
		if(tree[index]=='(' && index+1 < len && tree[index+1]==')')
			return NULL ;
		if(isdigit(tree[index])){
			string num ="";
			while(isdigit(tree[index]))
			{
				num+=tree[index];
				index++;
				
			}
			index--;
			root = new node ;
			root -> data = atoi(num.c_str());
			root -> left = root->right = NULL;
			if(index + 1< len && tree[index+1] == ')')
				return root ;
			index++;
			root -> left = buildtree(root->left,tree,index,len);
			index++;
			root -> right = buildtree(root->right,tree,index,len);
		}
		else{
			index++;
			return buildtree(root,tree,index,len);
		}
	}
	return root;
}

void inorder(struct node * t){
	
	if(t){
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
}


void count(struct  node * root,int &c){
	if(root){
		count(root->left,c);
		c++;
		count(root->right,c);
	}
}



void setParent(struct node *root){
	if(root){
	if(root->left)
		root->left->parent = root ;
	if(root -> right)
		root -> right -> parent = root ;
	setParent(root->left);
	setParent(root->right);
}	
}

void printParent(struct node * t){
	if(t){
		printParent(t->left);
		cout<<t->data;
		if(t->parent)
			cout<<" parent : "<<t->parent->data<<endl;
		else
			cout<<" Parent: "<<t->parent<<endl;
		printParent(t->right);
	}
}

void getValues(struct node * m,int k,int *&values,int &v,map<node *,bool> &ma){
	if(m!=NULL && !ma[m]){
		ma[m] = true;
		if(k==0){
			values[v] = m->data;
			v++;
		}
		getValues(m->left,k-1,values,v,ma);
		getValues(m->right,k-1,values,v,ma);
		getValues(m->parent,k-1,values,v,ma);
	}
}

void setmapfalse(struct node * root,map<struct node *,bool> &m){
	if(root){
		setmapfalse(root->left,m);
		m[root]=false;
		setmapfalse(root->right,m);
	}
}
int main(){
	string tree = "7()(8(9)(10))" ;
	struct node * root = NULL;
	int index = 0;
	root = buildtree(root,tree,index,tree.length());
	inorder(root);
	int n = 0;
	count(root,n);
	setParent(root);
	cout<<endl;
	printParent(root);
	
	//get m and k to print values which are at a distance k from m
	struct node * m = root->right;
	int k = 1 ;
	int *values = new int[n] ;
	int v = 0; 
	map<struct node *,bool> ma;
	setmapfalse(root,ma);
	getValues(m,k,values,v,ma);
	cout<<endl;
	for(int i=0 ; i<v ; i++)
		cout<<values[i]<<" ";
	cout<<endl;

}
