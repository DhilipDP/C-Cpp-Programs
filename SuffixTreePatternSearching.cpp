#include<iostream>
#define CHAR_TO_INDEX(c) (int)c - (int)'a'
#define ALPHABET_SIZE 26

using namespace std;

struct trie_node{
	int value ;
	struct trie_node * children[ALPHABET_SIZE];
};

struct trie{
	int count ; 
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

void insert(struct trie * head,char value[]){
//	cout<<endl<<value<<":\n";
	int len = strlen(value);
//	cout<<len<<endl;
	head -> count ++;
	struct trie_node * tra = head->root;
	int i,index;
	for(i=0 ; i<len ; i++)
	{
		index = CHAR_TO_INDEX(value[i]);
//		cout<<value[i]<<": "<<index<<endl;
		if(tra->children[index]==NULL)
			tra->children[index] = getNode();
		tra = tra->children[index];
	}
	tra->value = head->count ;
	cout<<"\n"<<head->count<<": Inserted: "<<value<<endl;
}


int search (char value[],struct trie * head){
	int len = strlen(value);
	struct trie_node * tra = head -> root ;
	int i,index ; 
	for(i=0 ; i<len  ; i++){
		index = CHAR_TO_INDEX(value[i]);
		if(tra->children[index]==NULL)
			return 0;
		tra= tra->children[index];
	}	
	return 1 ;
}

int main(){
	cout<<"Enter a word?:";
	string text;
	cin>>text;
	struct trie * head  = new struct trie;
	initialise(head);
	int len = text.size();
	for(int i=0 ; i<len ; i++){
		char temp[len];
		strcpy(temp,text.substr(i,len-i).c_str());
	    insert(head,temp);
	}
	int j = 5;
	while(j--){
		cout<<"\nEnter a word to be checked : \n";
		char a[1024];
		cin>>a;	
		search(a,head) ? cout<<"\nSubtring!" : cout<<"\nNot a substring\n";
//	cout<<head->count;
	}
}
