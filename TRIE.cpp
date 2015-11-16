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
	if(tra->value!=0)
		return 1 ;
	return  0;
}

void printAllPaths(struct trie_node * t,int index,char arr[],int len,char values[]){
	if(t==NULL)
		return ;
	arr[len]= (char)(index+97);
	//cout<<arr[len];
	len++;
	if(t->value!=0){
		arr[len]='\0';
		cout<<values;
		for(int i=1 ; i<strlen(arr) ; i++)
			cout<<arr[i];
		cout<<endl;
	}
	
	for(int i=0 ; i<ALPHABET_SIZE ; i++){
		if(t->children[i]){
		//	cout<<"i : "<<i;
			printAllPaths(t->children[i],i,arr,len,values);
		}
	}
	
}

void T9(struct trie * head,char value[]){
	int len = strlen(value) ;
	int i,index ;
	bool flag=true ;
	struct trie_node * tra = head->root;
	for(i=0 ; i<len ; i++){
		index  = CHAR_TO_INDEX(value[i]);
		if(tra->children[index]==NULL){
			flag = false;
			break;
		}
		tra= tra->children[index];
	}
	if(flag){
		cout<<"\nThe word(s)  starting with : "<<value<<" are :\n";
		char arr[1000];
	//	cout<<index;
		printAllPaths(tra,index,arr,0,value);
	}
	else
		cout<<"\nThere are no words starting with "<<value<<endl;
	
}
int main(){
	char keys[][8] = {"nandu","nijin","na","vishal","vim"};
	struct trie * head  = new struct trie;
	initialise(head);
	int len = sizeof(keys)/sizeof(keys[0]);
	for(int i= 0 ; i<len  ; i++)
		insert(head,keys[i]);
	if(	search("nandu",head)  )
		cout<<"\nPresent";
	else
		cout<<endl<<"NOt Present";
	T9(head,"na");
//	cout<<head->count;
}
