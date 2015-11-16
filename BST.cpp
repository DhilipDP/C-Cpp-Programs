#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


struct node {
	long long val;
	node * left;
	node * right;
	long long  level;
};

node * insert(node * t, long long x){
	//count++;
	if(t==NULL){
		t = new node();
		t->val = x;
		t->left = NULL;
		t->right = NULL;
	}
	else if(x < t->val)
	
		t->left = insert(t->left,x);
	else 
		t->right = insert(t->right,x);
	return t;
}



void topView (node * root,int hlevel,int vlevel,vector<long long> &t,map<int ,vector<node *> > &m){

	if(root){
		if(root->val==65103349){
			cout<<"65103349 :v "<<vlevel<<" h: "<<hlevel<<endl;
		}
		m[vlevel].push_back(root);
		root->level = hlevel;
		topView(root->left,hlevel+1,vlevel-1,t,m);
		topView(root->right,hlevel+1,vlevel+1,t,m);
	
	}
}

bool compare(const node  *a,const node *b){
	if(a->level == b->level)
		return a->val < b->val;
	return (a->level < b->level);
}
vector<long long> topView (node * root){
	vector<long long> t ;
	map<int , vector<node*> > m ;
	topView(root,0,0,t,m);
	map<int , vector<node *> > :: iterator it;
	vector<node *> :: iterator i;
	for(it = m.begin() ; it!=m.end() ; it++){
	//	cout<<"At vertical level : "<<it->first<<endl;
		vector<node *> v = it->second;
		if(it->first==-8){
		for(i = v.begin() ;  i!=v.end() ; i++){
			node * p= *i;
			cout<<p->val<<" "<<p->level<<endl;
		}
	
		cout<<endl;
	}
		sort(v.begin(),v.end(),compare);
		if(v.size()!=0)
			t.push_back(v[0]->val);
	}
	sort(t.begin(),t.end());
	return t;
}

void inorder(node * root){
	if(root){
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}
int main(){
	struct node * root=NULL;
	int n;
//	cout<<"No of Elements: ";
	cin>>n;
	int i;
//	cout<<"Enter : ";
	for(i=0 ; i<n ; i++)
	{
		long long val;
		cin>>val;
		root = insert(root,val);
	//	cout<<count<<endl;
	}

	vector<long long> v;
	v = topView(root);
	vector<long long> :: iterator it;
	for(it = v.begin() ; it!=v.end() ;it++)
		cout<<*it<<" ";
}
