
#include<iostream>

using namespace std ;


struct node {
	 int data ;
	 struct node * npx ;
};

struct node * XOR(struct node * a ,struct node * b){
	return (struct node *)((unsigned int)a ^ (unsigned int)b);
}


void insert(struct node *&head,int val){
		struct node * newnode = new node ;
		newnode -> data = val ;
		newnode -> npx = XOR(head,NULL);
		cout<<val<<" : "<<newnode->npx<<endl;
		if(head){
			head -> npx = XOR(newnode,head->npx) ;
		}
		head  = newnode ;
}

void traverse(struct node * head){

	struct node * current = head ;
	struct node * pre=NULL, * next ;
	while(current){
		cout<<current->data<<" ";
		next = XOR(pre,current->npx);
		pre = current ;//l
		current = next ;
	//	cout<<current->npx;

	}	
}

int main(){

	struct node * head = NULL ;
	insert(head,4);
	insert(head,12);
	insert(head,65);
	insert(head,23);
	
	traverse(head);
}
