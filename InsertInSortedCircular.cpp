#include<iostream>
using namespace std ;


struct ListNode{
	int val;
	ListNode * next ;
	ListNode(int x ) : val(x) , next(NULL) {}
	
};


void print(ListNode * head)
{
	if(!head)
		return  ;
	cout<<head->val<<" ";
	ListNode * cur = head->next ;
	while(cur!=head)
	{
		cout<<cur->val<<" ";
		cur =  cur -> next ;
	}
	cout<<endl;
}


void insert_after(ListNode * node,int val)
{
		ListNode * newnode = new ListNode(val);
		newnode -> next = node -> next ;
		node -> next = newnode ;
}

void insert(ListNode * node,int val)
{
	if(node==NULL)
		return ;

	ListNode * cur =  node,*pre = node ;

	do
	{
		pre = cur ;
		ListNode * temp = cur->next ;
		//if cur is the biggest element
		if(cur->val > temp->val){
		
			if(val > cur->val || val < temp->val)
				break;
			}
		else if(cur->val <= val && temp->val > val)
				break;
		cur = cur->next ;
	}while(cur != node);
	insert_after(pre,val);
}

int main()
{
	ListNode * head = new ListNode(2) ;
	head -> next = new ListNode ( 4) ;
	head -> next -> next = new ListNode(6) ;
	head -> next -> next -> next  = new ListNode(7) ;
	head -> next -> next -> next -> next = head ;
	print(head) ;
	insert(head->next->next->next,8);
	print(head) ;
	insert(head->next,1);
	print(head) ;
	insert(head->next->next,5);
	print(head) ;
	
}
