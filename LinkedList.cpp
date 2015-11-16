#include<iostream>
#include<stdlib.h>
using namespace std;


struct node {
	int data;
	struct node * next;
};


void insert(struct node * L,int x){
	//cout<<"hello";
	struct node * newnode = new node();
	struct node * p;
	newnode -> data = x;
	newnode -> next = NULL;
	if(L->next==NULL){
//	cout<<"first\n";
		L->next = newnode;
	}
	else{
	 p = L->next;
	while(p->next)
		p=p->next;
	p->next = newnode;
		}
}

void insert_front(struct node * L,int x){
	struct node * newnode = new node();
	struct node * p;
	newnode -> data = x;
	newnode -> next = NULL; 
	if(L->next==NULL)
		L->next = newnode;
	else{
		newnode -> next = L->next;
		L->next = newnode;
	}
}
void traverse(struct node * L){
	struct node * p = L->next;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
}

void insert_after(struct node * L,int x,int y){
	struct node * newnode = new node();
	struct node * p=L->next;
	newnode -> data = y;
	newnode -> next = NULL;
	while(p){
	//	cout<<p->data<<" ";
		if(p->data==x)
			break;
		p=p->next;
	}
	//cout<<p->data<<endl;
	if(p!=NULL){
		newnode ->next = 	p->next;
		p->next = newnode;
	}	
}


void reverse_alternate(struct node * L){
	struct node * oddhead = new node();
	struct node * evenhead = new node();
	oddhead->next = NULL;
	evenhead->next = NULL;	
	int count = 1;
	struct node * p = L->next;
	while(p){
		if(count%2)
			insert(oddhead,p->data);
		else
			insert_front(evenhead,p->data);
		p=p->next;
		count++;
	}
	p=evenhead->next;
	struct node * q=oddhead->next;
	while(q->next){
		q=q->next;
	}
	q->next = p;
	cout<<"\nReverse alternate list: \n";
	traverse(oddhead);
}

bool isEmpty(struct node * L){
	return L->next;
}

void pair_wise_swap_data(struct node * L){
	struct node * p = L->next;
	if(!isEmpty(L)){
		cout<<"Sorry,the list is empty..\n";
		return;
	}	
	while(p && p->next){
		int temp = p->data;
		p->data = p->next->data;
		p->next->data = temp;
		p=  p->next->next;
	}
	cout<<"After swapping PairWise(data): \n";
	traverse(L);
}

void pair_wise_swap_link(struct node * L){
	if(!isEmpty(L)){
		cout<<"Sorry,the list is empty..\n";
		return;
	}
	struct node * head, *pre, *cur;
	head = L->next;
	if(head->next==NULL)
		return ;
	pre = head ;
	cur = head -> next;
	L->next = cur;
	while(1){
		struct node * q = cur->next;
		cur -> next = pre;
		if(q==NULL || q->next==NULL){
			pre->next = q;
			break;
		}
		pre->next = q->next;
		pre = q;
		cur = pre ->  next;
	}
	cout<<"After swapping PairWise(link): \n";
	traverse(L);
}

void merge(struct node * L,struct node * S){
//	cout<<"Merging: ";
	struct node * p = L->next;
	struct node * q = S->next;
	struct node * M = new node();
	M->next = NULL;
	while(p && q){
	//	cout<<p->data<< " " << q->data<<endl;
		insert(M,p->data);
		insert(M,q->data);
		p=p->next;
		q=q->next;
	}
	while(p){
		insert(M,p->data);
		p=p->next;
	}
	S->next = q;
	cout<<endl<<"After Merging: FIrst and Second"<<endl;
	traverse(M);
//	traverse(S);
	
}

void delete_alt (struct node * L){
	cout<<"\nDeleting N nodes after M nodes:\n";
	cout<<"\nEnter M and N\n";
	int m,n;
	cin>>m>>n;
	struct node * D = new node();
	D->next = NULL;
	struct node * p = L->next;
	whil
}
int main(){
	struct node * L = new node();
	L->next = NULL;
	for(int i=1; i<=10 ; i++)
	{
		insert(L,i)	;
		cout<<"Inserted\n";
	}
	traverse(L);
	cout<<"\nAdding 6 after 3:\n";
	insert_after(L,3,6);
	traverse(L);
	reverse_alternate(L);
//	cout<<L->next->data;
	pair_wise_swap_data(L);
	pair_wise_swap_link(L);
	struct node * S = new node();
	S->next = NULL;
	for(int i=50 ; i<=60 ; i++)
	{
		insert(S,i);
		cout<<"Inserted\n";
	}	merge(L,S);
	delete_alt(L);

	return 0;
}
