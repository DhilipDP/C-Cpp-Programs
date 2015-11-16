

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


struct node * reverseAppend(struct node * head)
{
	if(head==NULL || head->next == NULL || head->next->next == NULL)
		return head ;
	struct node * odd = head ;
	struct node * even  = NULL;
	while(odd && odd->next)
	{
		cout<<odd->val<<" "<<endl;
		struct node * temp = odd->next->next ;
		if(even){
			odd->next->next = even ;
				even = odd -> next ;
			}
		else{
			even = odd->next ;
			even -> next = NULL ;
		}
	
		odd -> next = temp ;
		if(temp)
		odd = temp ;
	}
	odd->next = even;
	return head;
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
	head = reverseAppend(head);
	print(head);
}
