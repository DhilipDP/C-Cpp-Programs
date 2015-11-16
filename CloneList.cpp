#include<map>
#include<iostream>
using namespace std ;


struct node{
	int val ;
	struct node * next ;
	struct node * arbit ;
	node(int x) : val(x) , next(NULL) ,arbit(NULL){}
};



void print(struct node * head){
	struct node * temp = head;
	while(temp)
	{
		cout<<temp->val<<" "<<temp->arbit->val<<endl;
		temp = temp -> next;
	}
	cout<<endl;
	
}

struct node * clone(struct node * head)
{
	struct node * copyList ,*tra=NULL;
	map<node *,node *> hash ;
	struct node * t = head ;
	while(t)
	{
		hash[t] = t->next;
		struct node * newnode = new node(t->val);
		if(!tra)
			copyList = newnode ;
		else
			tra->next = newnode ;
		tra = newnode;
		t = t->next ;
	}
	struct node * t1 = head,*t2 = copyList ;
	while(t1)
	{
		struct node * temp = t1->next;
		t1 -> next = t2;
		t2 -> arbit = t1 ;
		t1 = temp;
		t2 = t2 -> next ;
	}
	t2 = copyList ;
	while(t2)
	{
		t2 -> arbit = t2 -> arbit -> arbit ->next;
		 t2 = t2 -> next ;
	}
	map<node * , node *> :: iterator it ;
	for(it = hash.begin() ; it!=hash.end() ; it++)
	{
		struct node * t = it->first;
		t->next =it->second;
	}
	cout<<"after cloning: original list : "<<endl;
	print(head);
	return copyList;
}



void insert_after(struct node * t)
{
	struct node * newnode = new node(t->val) ;
	newnode-> next = t->next;
	t->next = newnode;
}


struct node * clone_again(struct node  * head)
{
	
	struct node * t =head;
	struct node * copyList = NULL;
	while(t){
	insert_after(t);
	t = t->next ->next;
	}

	t=head;
	while(t)
	{
		t -> next -> arbit = t->arbit->next;
		t = t->next->next;
	}
	t = head ;
	copyList = head->next;
	struct node *  t2 = copyList;
	while(t)
	{
		t2 = t->next;
		t->next = t2->next ;
		if(!t->next)
			t2->next = NULL;
		else
			t2->next = t->next->next;
		t = t->next;	
	}

	print(head);
	return copyList;
}

int main()
{
	struct node * head = 	 new node(1);
	head -> next = new node(2);
	head -> next -> next = new node(3);
	head -> next -> next -> next= new node(4);
	head -> next -> next -> next-> next= new node(5);
	head -> arbit = head -> next -> next ;
	head -> next -> arbit =head ;
	head -> next -> next -> arbit = head -> next -> next -> next-> next;
	head -> next -> next -> next->arbit = head -> next -> next ;
	head -> next -> next -> next -> next -> arbit = head -> next;
	struct node * copy ;
	print(head);

	copy  =  clone(head);
	cout<<"Cloned List:" <<endl;
	print(copy) ;
	struct node * copy2 = clone_again(head);
	print(copy2) ;
	

}
