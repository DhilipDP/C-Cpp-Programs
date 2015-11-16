#include<iostream>
using namespace std ;


struct node{
	int val ;
	struct node * next  ;
	node(int x) : val(x) , next(NULL){}
};


void print(struct node * head)
{
	if(!head){
		cout<<"empty"<<endl;
		return ;
	}
	struct node * t = head ;
	cout<<t->val<<" ";
	t = t->next;
	while(t != head){
		cout<<t->val<<" ",t =t -> next ;
	}
	cout<<t->val<<" ";
	cout<<endl;
}


void splitIntoTwo(struct node * head,struct node * &first,struct node * &second)
{
	struct node   *last ,*prev_mid ;
	if(head==NULL || head->next==head)
		return ;
	struct node * slow=head,*fast = head ;
	while(fast->next != head)
	{
		prev_mid = slow ;
		slow = slow -> next ;
		last = fast -> next ;
		fast = fast->next -> next ;
		if(fast == head)
			break;
	}
	if(fast != head)
		last = fast ;
	prev_mid -> next = head ;
	first = head ;
	last -> next = slow ;
	second = slow ;
}

struct node * insert(struct node * head,int val)
{

	struct node * newnode = new node(val) ;

	if(head==NULL)
	{
		head = newnode ;
		head -> next = head;
		return  head;
	}
	struct node * tra = head ;
	while(tra->next != head)
		tra = tra->next ;
	newnode -> next = head ;
	tra->next = newnode ;
	return head ;
}

int main()
{
	struct node * head = NULL ;
	for(int i=1; i<=6 ; i++){
		head = insert(head,i) ;
		print(head) ;
		struct node * first = NULL,*second =NULL;
		splitIntoTwo(head,first,second) ;
		print(first) ;
		print(second) ;
	}
	print(head);
	struct node * first = NULL,*second =NULL;
	splitIntoTwo(head,first,second) ;
	print(first) ;
	print(second) ;
}
