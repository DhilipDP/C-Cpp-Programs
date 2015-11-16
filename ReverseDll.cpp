#include<iostream>

using namespace std;

struct node{
	int val ;
	struct node * prev;
	struct node * next ;
	node(int x) :   val(x) , prev(NULL) , next(NULL) {}

};


void print(struct node * head)
{
	struct node * t = head ;
	while(t){
		cout<<t->val<<" ";
		if(t->prev)
			cout<<t->prev->val;
		cout<<endl;
		t = t->next;
	}
}

struct node * insert(struct node * head,int val)
{
	struct node * newnode = new node(val) ;
	if(!head)
	{
		head = newnode ;
		return head ;
	}
	struct  node * tra = head ;
	while(tra->next)
		tra = tra->next;
	tra -> next = newnode ;
	newnode->prev = tra ;
	return head ;
}


struct node * reverse(struct node * head)
{
	struct node * cur = head,*temp = NULL ;
	
	while(cur)
	{
		 temp = cur -> prev ;
		cur -> prev = cur -> next;
		cur -> next = temp ;
		cur = cur->prev ;
	}
	if(temp)
	return temp -> prev ;
	else
	return head ;
}

struct node * Reverse(struct node * head)
{
	if(head==NULL ) 
		return head ;
	struct node * rest = head->next ;
	if(head->next==NULL){
		head->prev=NULL;
		return head;
	}
		
	rest = Reverse(rest);
	head -> next -> next = head ;
	head -> prev = head -> next ;
	head -> next = NULL ;
	return rest ; 
}

struct node * delete_node(struct node * head,struct node * t)
{
	if(t==head)
		head = head->next ;
	if(t->next)
		t->next->prev = t->prev;
	if(t->prev)
		t->prev->next = t-> next;
	return head;
}


int main()
{
	struct node *  head = NULL ;
	for(int i=1 ; i<=5	 ; i++)
		head = insert(head,i);
	print(head);
	
	head  = reverse(head);
	
	print(head);

	head = Reverse(head);
	cout<<endl;
	print(head);
	
head =	delete_node(head,head->next->next);
	print(head);
}

