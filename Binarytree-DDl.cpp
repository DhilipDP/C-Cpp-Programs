#include<iostream>
#include<queue>
using namespace std ;

struct node {
	int data ;
	struct node * left ;
	struct node * right ;
};



struct node * get_node(int val){
	struct node * newnode = new node ;
	if(newnode){
		newnode -> data = val;
		newnode->left = newnode->right = NULL ;
		return newnode ;
	}	
	return NULL;
}

struct node * convertBTtoDDl(struct node * root){
	if(root == NULL)
		return NULL;
	if(root->left){
		struct node * left = convertBTtoDDl(root->left);
		while(left && left->right){
			left = left->right;
		}
		left -> right = root ;
		root -> left = left ;
	}
	if(root->right){
		struct node * right = convertBTtoDDl(root->right);
		while(right && right->left)
			right = right->left;
		right -> left = root ;
		root -> right = right ;
	}
	return root ;
}

void traverse(struct node * t){
	while(t){
		cout<<t->data<<" ";
		t = t->right;
	}
}

void fixPrev(struct node * t){
	static struct node * pre = NULL;
	if(t!=NULL){
//		cout<<"hi"<<t->data<<endl;
		fixPrev(t->left);
	//	cout<<t->data<<" left = "<<pre->data<<endl;
		t->left = pre ;
		pre = t ;
		fixPrev(t->right);
	}
}

struct node * fixNext(struct node * t){
	struct node * temp = NULL;
	while(t && t->right)
		t=t->right ;
	while(t && t->left){
		temp = t  ;
		t = t -> left ;	
		t -> right = temp;
	}	

	return t ;
}

struct node * convert(struct node * t){
	fixPrev(t);
	return fixNext(t);	
}
void inorder(struct node * t){
	if(t){
		inorder(t->left);
		cout<<t->data<<endl;
		inorder(t->right);
	}
}

int main(){
	struct node * root = get_node(10) ;
	root->left = get_node(12);
	root->right = get_node(15);
	root->left->left = get_node(25);
	root->left->right = get_node(30);
	root->right->left = get_node(36);
		inorder(root);
	struct node * head = convertBTtoDDl(root);
	while(head && head->left)
		head = head->left;
	traverse(head); 
	struct node * head2 = convert(root);
	cout<<endl;
	traverse(head2);
}
