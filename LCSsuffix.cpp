#include<iostream>
#include<stdio.h>
#define CHAR_TO_INDEX(c) (int)c - (int)'a'
#define ALPHABET_SIZE 26
using namespace std;

bool second = false;
int maxlen,len ;

struct trie_node{
	int value ;
	struct trie_node * children[ALPHABET_SIZE];
};
struct trie{
	int count;
	struct trie_node * root ;
};


struct trie_node * getNode(){
	struct trie_node * p;
	p = new struct trie_node;
	if(p){
		p->value = 0;
		for(int i=0 ; i<ALPHABET_SIZE ; i++)
			p->children[i] = NULL;
	}
	return p;
}


void initialise(struct trie * h){
	h->count = 0;
	h->root =	getNode();	
}

void insert(struct trie * head,string value){
	
		int length = value.size();
	//	cout<<len<<endl;
		head -> count ++;
		struct trie_node * tra = head->root;
		int i,index;
		for(i=0 ; i<length ; i++)
		{
			index = CHAR_TO_INDEX(value[i]);
	//		cout<<value[i]<<": "<<index<<endl;
			if(tra->children[index]==NULL)
				tra->children[index] = getNode();
			else if(second)
				len++;
			tra = tra->children[index];
		}
		if(len > maxlen)
			maxlen = len ;
		len=0;
		tra->value = head->count ;
	//	cout<<"\n"<<head->count<<": Inserted: "<<value<<endl;
}


int main(){
	struct trie * head = new struct trie ;
	initialise(head);
	string text,pattern;
	cin>>text>>pattern;
	int i,j;
	int len1 = text.size();
	int len2 = pattern.size();
	for(i=0 ; i<len1 ; i++)
		insert(head,text.substr(i,len1-i));
	second = true ;
	for(j=0 ; j<len2 ; j++)
		insert(head,pattern.substr(j,len2-j));
	cout<<maxlen;
}
