#include<iostream>
#include<queue>
#include<vector>
using namespace std ;


struct node{
	string val ;
	int freq ;
	struct node * left , * right ;
	node(string c,int v) : val(c) , freq(v) , left(NULL) , right(NULL) {}

};

struct comp{
	bool operator()(node* & a,node* &b)
	{
		return a->freq > b->freq ;
	}
};


void printHuffManCodes(node * root,string code)
{
	if(root==NULL)
		return ;
	printHuffManCodes(root->left,code +"0") ;
	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->val<<" : "<<code<<endl;
		return ;
	}
	printHuffManCodes(root->right,code+"1") ;
	
}
void huffMan(string val[], int freq[] ,int n)
{
	vector<node *> arr ;
	for(int i=0 ; i<n ; i++)
		arr.push_back( new node(val[i],freq[i]) ) ;
	priority_queue<node *, vector<node *> ,  comp> heap;
	for(int i=0 ; i<n ; i++)
		heap.push(arr[i]) ;
	
	while(heap.size() != 1){
		node * l_child = NULL ;
		node * r_child = NULL ;
		l_child = heap.top() ;
		heap.pop();
		r_child = heap.top();
		heap.pop() ;
		struct node * temp = new node("dummy",l_child->freq + r_child->freq ) ;
		temp->left = l_child ;
		temp->right = r_child ;
		heap.push(temp);
	}
	
	printHuffManCodes(heap.top(),"");
}

int main()
{
	string val[] = {"a","b","c","d","e","f"};
	int freq[] = {5,9,12,13,16,45};
	int n = sizeof(freq) / sizeof(freq[0]) ;
	huffMan(val,freq,n) ;
}
