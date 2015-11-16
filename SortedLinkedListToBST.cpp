#include<iostream>

using namespace std;


struct l_node{
	int data ;
	struct l_node * next ;
};


struct t_node{
	int data ;
	struct t_node * left ;
	struct t_node * right ;
};


int count(struct l_node * t){
	int count = 0;
	while(t){
		count++;
		t = t->next ;
	}
	return count ;
}

struct t_node* sortedLinkedListToBST(struct l_node *&head,int n){
	if(n<=0)
		return NULL;
	struct t_node * left = sortedLinkedListToBST(head,n/2);
	struct t_node * root =  new t_node();
	root->data = head->data;
	root->left = left;
	head =  head->next;
	root -> right = sortedLinkedListToBST(head,n-n/2-1);
	return root ; 
}

struct t_node* sortedLinkedListToBST(struct l_node * head){
	int n = count(head);
	return sortedLinkedListToBST(head,n);
}

struct l_node * get_node (int val){
	struct l_node * newnode = new l_node ;
	if(newnode){
		newnode->data = val;
		newnode->next = NULL;
		return newnode ;
	}
	return NULL;
}


void print(struct l_node * head){
	while(head){
		cout<<head->data<<" ";
		head =  head -> next ;
	}
}
void insert_sorted(struct l_node *&head,int val){
	struct l_node * newnode = get_node(val);
	if(head==NULL){
		head=newnode ;
		return ;
	}
	struct l_node * tra = head,*pre = NULL;
	while(tra && tra->data < val){
		pre = tra;
		tra = tra->next ;
	}
	if(!pre){
		newnode -> next = head;
		head = newnode;
		return ;
	}
	pre->next = newnode ;
	newnode -> next = tra;
}

void inorder_traversal(struct t_node * t)
{
	if(t){
		inorder_traversal(t->left);
		cout<<t->data<<endl;
		inorder_traversal(t->right);	
	}	
}

int main(){
	struct l_node * head = NULL ;
	//inserting in a sorted linked list
		insert_sorted(head,7);
		insert_sorted(head,2);
		insert_sorted(head,3);
		insert_sorted(head,1);
		insert_sorted(head,5);
		insert_sorted(head,4);
		print(head);
		struct t_node * root ;
		root = sortedLinkedListToBST(head);
		cout<<endl;
		inorder_traversal(root);
}
