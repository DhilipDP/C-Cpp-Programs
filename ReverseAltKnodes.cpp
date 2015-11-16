

#include<iostream>
using namespace std ;


struct node{
	int val ;
	struct node * next ;
	node(int x) : val(x) , next(NULL) {}
};



void print(struct node * head){
	struct node * temp = head;
	while(temp)
	{
		cout<<temp->val<<" ";
		temp = temp -> next;
	}
	cout<<endl;
}




struct node * reverseAltKnodes(struct node * head,int k)
{
	if(head==NULL || head->next==NULL)
		return head ;
	
	struct node * cur = head,*pre = NULL ,*temp=NULL;
	int c = 0;
	while(cur && c<k)
	{
		temp = cur -> next ;
		cur -> next =  pre ;
		pre = cur ;
		cur = temp ;
		c++ ;
	}
//	print(pre);
	c = 0;
	head -> next = cur ;
	while(cur && c < k)
	{
		temp = cur ;
		cur = cur->next ;
		c++;
	}
	if(temp)
	temp -> next = reverseAltKnodes(cur,k);
	return pre;
}

struct node * insert(struct node * head,int val)
{
	struct node * newnode= new node(val) ;
	if(head == NULL){
		head = newnode ;
		return head;
	}struct node * tra = head ;
	while(tra->next)
		tra = tra -> next ;
	tra -> next = newnode ;
	return head;
}

int main()
{
	struct node * head = NULL ;
	for(int i=1 ; i<=10 ; i++)
		head = insert(head,i);
	print(head);	
	head = reverseAltKnodes(head,4) ;
	print(head);
}
