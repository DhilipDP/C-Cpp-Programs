
#include<iostream>

using namespace std ;


struct node{
	int data ;
	node * next ;
};

void insert(struct node *&head , int val){
	
	cout<<"\nInserting: ";
	struct node * newnode = new node ;
	newnode -> data = val ;
	newnode -> next = NULL ;
	if(!head){
		cout<<val<<" at head"<<endl;
		head = newnode ;
		return ;
	}
	struct node * p = head ;
	while(p->next)
		p = p->next ;
	cout<<val<<endl;
	p->next = newnode ;
}

void traverse(struct node * head){

	struct node * p = head ;
	while(p){
		cout<<p->data<<" ";
		p= p->next;
	}
		
}


struct node * reverse(struct node * head)
{
	struct node * pre = NULL, *temp ;
	struct node * t = head ;
	while(t){
		temp = t->next;
		t->next = pre ;
		pre = t ;
		t = temp ;
	}	
	return pre ;
}


//recursive
struct node * rev(struct node * t ,struct node * pre){

	if(t==NULL){
//		cout<<"returningL: "<<pre->data<<endl;	
		return pre ;
}
	struct node * temp = t->next;
	t->next = pre ;
	
	return rev(temp,t);
}


void merge_list(struct node * l1,struct node *l2,struct node *& l3){
	
	if(!l1)
		return ;
	if(!l2)
		return ;
	while(l1 && l2 ){
		if(l1->data <= l2->data){
			insert(l3,l1->data);
			l1 = l1->next ;
		}
		else
		{
			insert(l3,l2->data);
			l2=l2->next;
		}
	}
	while(l1)
		insert(l3,l1->data),l1=l1->next;
	while(l2)
		insert(l3,l2->data),l2=l2->next;
	
}


struct node * reverse_size(struct node * p,int size){
	if(p==NULL)
		return NULL;
	struct node * current = p;
	struct node * next , *pre =NULL ;
	int count = 0;	
	while(current && count < size){
		next = current -> next ;
		current -> next = pre ;
		pre = current ;
		current = next ;
		count++;
	}
	
	p->next = reverse_size(current,size);
	
	return pre ;
		
}


struct node * reverse_alternate(struct node * p,int size){
	if(p==NULL)
		return NULL;
	struct node * current = p ;
	struct node * next , *pre = NULL ;
	int count = 0 ;
	while(current &&  count<size){
		next= current ->next ;
		current -> next = pre ;
		pre = current ;
		current = next ;
		count++ ;
	}
	
	p->next = current ;
	count = 0;
	struct node * temp;
	while(current && count < size){
		temp = current ;
		current = current -> next ;
		count++;
	}
	if(temp)
	
	temp -> next = reverse_alternate(current,size);
	
	return pre ;
}

void delete_node(struct node *&head,struct node * n){
	struct node * p = head , * m;
	if(!p)
		return ;
	while(p){
		if(p==n){
			if(p==head){
				head = p->next ;
				delete  p ;
			}
			else{
				m->next = p->next;
				delete p;
			}
			break;
		}
		else{
			m=p;
			p=p->next ;
		}
	}
//	cout<<"\nNo such node \n";
}

void delete_in_middle(struct node * p ){
	
	if(!p){
		cout<<"\nno node exists\n";
		return ;
	}
	struct node * temp = p -> next ;
	if(!temp){
		cout<<"\nLast node .. cant delete\n";
		return ;
	}	
	p->data = temp->data ;
	p->next = temp->next ;
	delete temp;	
}


void remove_duplicates(struct node * head){
	struct node * p = head ;
	struct node * q ;
	while(p){
		cout<<"\nChecking for: "<<p->data<<endl;
		q = p->next ;
		while(q){
			cout<<"\n\nChecking: "<<q->data<<endl;
			if(p->data == q->data){
				cout<<"\ndeleting "<<q->data<<endl;
				delete_node(head,q);
				q=q->next;
			}
			else{
				q = q->next ;
			}
		}
		p=p->next;
	}	
}

int main(){
	struct node * head = NULL ;
	
	insert(head,7);
	insert(head,2);
	insert(head,5);
	insert(head,3);
	insert(head,12);
	insert(head,14);
	insert(head,1);
	
	cout<<"\nthe linked list is: "<<endl;

	traverse(head);
	
	struct node * rev_head = rev(head,NULL);
	
	cout<<"\n\nthe reverse linked list is: "<<endl;
	
	
	traverse(rev_head);
	
	cout<<"\nAgain Reversing: \n"<<endl;
	head = reverse(rev_head);
	
	traverse(head);
	
	cout<<"\nMerging two sorted lists:\n"<<endl;
	
	struct node * list_1=NULL;
	
	insert(list_1,5);
	insert(list_1,10);
	insert(list_1,15);
	
	cout<<"\nFirst list\n";
	
	traverse(list_1);
	
	struct node * list_2=NULL;
	
	insert(list_2,2);
	insert(list_2,6);
//	insert(list_2,);
	
	cout<<"\nSecond list\n";
	
	traverse(list_2);
	
	cout<<"\nMerging:\n";
	
	struct node * merge = NULL ;
	
	merge_list(list_1,list_2,merge);
	
	traverse(merge);
	
	cout<<"\nReversing nodes of size 2:\n";
	merge = reverse_size(merge,2);
	traverse(merge);
	
	cout<<"\nOriginal list: \n";
	traverse(head);
	cout<<"\nReversing nodes of size 3:\n";
	
	head = reverse_size(head,3);
	
	traverse(head);
	
	cout<<"\nReversing alternate nodes of size 2\n";
	
	head = reverse_alternate(head,2);
	traverse(head);
	
	cout<<"\nDeleting a middle node directly!(4th node) \n";
	
	delete_in_middle(head->next->next->next);
	
	traverse(head);
	
	cout<<"\nCreating new list\n";
	// 12->11->12->21->41->43->21
	
	struct node * list = NULL;
	insert(list,12);
	insert(list,11);
	insert(list,12);
	insert(list,21);
	insert(list,41);
	insert(list,43);
	insert(list,21);
	
	traverse(list);
	
	cout<<"\nRemoving duplicates\n";
	
	remove_duplicates(list);
	//insee
	traverse(list);
}
