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


struct node  * findMiddle(struct  node * head)
{
	if(head==NULL || head->next==NULL)
		return head;
	struct node * slow = head,*fast = head;
	while(fast)
	{
		fast = fast->next;
		if(fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	return slow;
}



struct node * nthNodefromEnd(struct node * head,int n)
{
	if(!head)
		return NULL;
	struct node * slow =head, *fast = head;
	int c = 1;
	while(fast && c < n)
	{
		c++;
		fast = fast-> next ;
	}
	if(!fast)
		return NULL;
	while(fast->next)
	{
		slow = slow->next ;
		fast = fast -> next ;
	}
	return slow;
}


bool isPalindrome(struct node *&left,struct node * right)
{
	if(right==NULL)
		return true;

	bool p1 = isPalindrome(left,right->next);
	if(!p1)
		return false ;
	bool p2 = (left->val==right->val) ;
	left = left->next ;
	return p2;
}

bool isPalindrome(struct node * head)
{
	struct node * left=head,*right=head;
	return isPalindrome(left,right);
}



struct node * reverse(struct node * head)
{
		if(head==NULL || head->next==NULL)
			return head;
	
		struct node * rest = head->next ;
	
		rest = reverse(rest);

		head->next->next=head;
		head->next = NULL ;
		return rest;
}


bool Palindrome(struct node * head)
{
	if(head==NULL || head->next==NULL)
		return true;
	struct node * middle = findMiddle(head);
	struct node * second = reverse(middle);
	print(second);
	struct node * first = head;
	while(second)
	{
		if(first->val==second->val)
		{
			first = first->next ;
			second = second->next;
		}
		else
		return false;
	}
	return true;
}
int main()
{
	struct node * head = 	 new node(5);
	head -> next = new node(3);
	head -> next -> next = new node(6);
	head -> next -> next -> next= new node(6);
	head -> next -> next -> next-> next= new node(3);
	head -> next -> next -> next-> next-> next= new node(5);
	print(head);	 
		
	head = reverse(head);
	print(head);

	struct node * mid = findMiddle(head);
	cout<<"Middle node is "<<mid->val<<endl;
	for(int n = 1 ; n<=7 ; n++) {
	cout<<n<<"th node from the end: ";
	struct node  * last_n  = nthNodefromEnd(head,n);
	if(!last_n)
		cout<<"Invalid n"<<endl;
	else
		cout<<last_n->val<<endl;
	}
	
	if(isPalindrome(head))
		cout<<"palindrome "<<endl;
	else
		cout<<"not palindrome"<<endl;
	
	if(Palindrome(head))
		cout<<"palindrome "<<endl;
	else
		cout<<"not palindrome"<<endl;
		
	
}
