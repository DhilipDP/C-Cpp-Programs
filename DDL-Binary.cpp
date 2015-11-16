#include<iostream>

using namespace std ;


struct node{
	int data ;
	struct node * pre ;
	struct node * next ;
};


void insert(struct node *&head,int val){
	struct node * newnode = new node ;
	newnode -> data = val ;
	newnode -> pre = newnode -> next = NULL;
	if(!head){
		head = newnode ;
		return ;
	}
	struct node * tra = head ,*prev = NULL;
	while(tra && tra->data < val){
		prev = tra;
		tra = tra->next ;
	}
	if(!prev){
		newnode -> next = head ;
		head->pre = newnode;
		head=newnode ;
		return ;
	}
	newnode -> next = tra;
	if(tra) 
		tra->pre = newnode ;
	prev->next = newnode ;
	newnode -> pre = prev; 
}

void print(struct node * t){
	while(t){
		cout<<t->data<<" ";
		t = t->next ;
	}
}


int count(struct node * t){
	int c = 0;
	while(t){
		c++;
		t=t->next ;
	}
	return c ;
}

struct node * convertDDLtoBT(struct node *&head,int n){
	if(n<=0)
		return NULL;
	struct node * left =  convertDDLtoBT(head,n/2);
	struct node * root = head ;
	root -> pre = left ;
	head = head->next ;
	root -> next = convertDDLtoBT(head,n-n/2-1);
	return root;
}
struct node * convertDDLtoBT(struct node * head){
	int c = count(head);
	return convertDDLtoBT(head,c);
}

void inorder(struct node * t){
	if(t){
		inorder(t->pre);
		cout<<t->data<<endl;
		inorder(t->next);
	}
}
int main(){
	struct node * head = NULL ;
	insert(head,2);
	insert(head,3);
	insert(head,5);
	insert(head,1);
	print(head);
	struct node * root ;
	root = convertDDLtoBT(head);
	cout<<endl;
	inorder(root);
}

