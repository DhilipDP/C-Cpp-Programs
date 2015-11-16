#include<iostream>

using namespace std ;


struct node {
	int data ;
	struct node * pre ;
	struct node * next ;
};


void insert(struct node *&head , int val){
	
	struct node * newnode = new node ;
	newnode -> data = val ;
	newnode -> pre  = newnode->next = NULL ;
	
	if(head == NULL){
		head = newnode ;
		return ;
	}
	
	struct node * tra = head;
	while(tra->next)
		tra=tra->next ;
	tra->next = newnode ;
	newnode ->pre = tra;
}

void traverse_forward(struct node * t){
	if(t==NULL)
		return ;
	while(t)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
}

void traverse_backward(struct node * t){
	if(t==NULL)
		return ;
	while(t){
		cout<<t->data<<" ";
		t = t-> pre ;
	}
}

void reverse(struct node * &head){
	struct node * current = head ;
	struct node * temp ;
	
	while(current){
		temp = current -> pre ;
		current -> pre = current->next;
		current -> next = temp;
		current = current-> pre;
	}
	
	if(temp!=NULL)
		head = temp->pre ;
}

void delete_a_node(struct node * p,struct node *&head){
	
	if(p==NULL || head==NULL)
		return ;
	if(p==head)
		head = p->next ;
	if(p->pre)
		p->pre->next = p->next ;
	if(p->next)
		p->next->pre = p->pre ;
	delete p;
			
}


void delete_alternate(struct node * &head){
	if(head == NULL)
		return ;
	if(head->next==NULL)
		return ;
	struct node * current = head,* del_node,*next_node ;
	while(current && current->next){
		del_node = current->next ;
		next_node = del_node->next ? del_node->next : NULL ;
		current -> next = next_node ;
		if(next_node)
			next_node -> pre = current ;
		current =  next_node ;
		delete del_node;
	}
}
int main(){
	
	struct node * head = NULL;
	insert(head,3);
	insert(head,5);
	insert(head,7);
	insert(head,9);
	insert(head,1);
	insert(head,12);
	cout<<"Forward:\n";
	traverse_forward(head);
	cout<<"\nDelete Alternate:\n";
	delete_alternate(head);
		traverse_forward(head);
	cout<<"\nBackward\n";
	traverse_backward(head->next->next);
	
	cout<<"\nReversing \n";
	reverse(head);
	cout<<"\ntraversing forward now\n";
	traverse_forward(head);
	
	cout<<"\ntraversing backward now\n";
	traverse_backward(head->next->next);
	
	cout<<"\ndeleting 3rd node\n";
	cout<<"\ndeleting 1st node\n";
	
	
	delete_a_node(head->next->next,head);
	delete_a_node(head,head);
	
	traverse_forward(head);
}
