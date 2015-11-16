#include<iostream>
#define SIZE 26
#define TO_INT(c) (char)c - 97
using namespace std ;

//using a trie

struct TrieNode{
	int val ;
	TrieNode * children[SIZE] ;
};


TrieNode * getNode()
{
	TrieNode * newnode = new TrieNode() ;
	newnode -> val = 0 ;
	for(int i=0 ; i<SIZE ; i++)
		newnode -> children[i] = NULL ;
	return newnode ;
}

TrieNode * insert(TrieNode * root,string str)
{
//	cout<<endl<<str;
		TrieNode * crawl =  root ;
		for(int i=0 ; i<str.length() ; i++)
		{
			int index = TO_INT(str[i]) ;
			if(crawl->children[index]==NULL)
				crawl->children[index] = getNode();
			crawl -> children[index]-> val++;
			crawl = crawl->children[index] ;
		}
//	cout<<"insertion "<<str;
	return root ;
}



void compute_prefix(TrieNode * root,string &ans,string &s, int &index)
{
//	cout<<ans<<endl;
	if(root==NULL)
	{
		ans ="" ;
		return ;
	}
	ans += s[index];
	if(root->val==1)
		return ;
	index++;
	compute_prefix(root->children[TO_INT(s[index])] , ans , s , index);
}

string prefix(TrieNode * root , string s)
{
		string ans = "" ;
		int index = 0;
		compute_prefix(root->children[TO_INT(s[0])] , ans , s ,index) ;	
		return ans ;
}

int main()
{
	

	struct TrieNode * root = getNode() ;
	string s[] = {"zebra", "dog", "duck","dove"} ;

	int n  = sizeof(s) / sizeof(s[0]) ;	
	for(int i=0 ; i<n ; i++)
		root = insert(root,s[i]);

	for(int i=0 ; i<n ; i++)
		cout<<s[i]<<" : "<<prefix(root,s[i])<<endl ;
}
