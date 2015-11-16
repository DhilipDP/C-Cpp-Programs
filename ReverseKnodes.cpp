

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

struct node * reverseKnodes(struct node * head,int k)
{
	if(head == NULL || head->next==NULL)
		return head ;
	int n = 0;
	struct node * cur = head ,*pre = NULL ;
	while(cur && n<k)
	{
		struct node * temp = cur -> next ;
		cur -> next = pre ;
		pre = cur  ;
		cur = temp ;
		n++ ;
	}
	head -> next = reverseKnodes(cur,k) ;
	return pre ;
	
}



int main()
{
	struct node * head = 	 new node(5);
	head -> next = new node(3);
	head -> next -> next = new node(6);
	head -> next -> next -> next= new node(2);
	head -> next -> next -> next-> next= new node(1);
	head -> next -> next -> next-> next-> next= new node(4);
	print(head);	
	head = reverseKnodes(head,4) ;
	print(head);
}
