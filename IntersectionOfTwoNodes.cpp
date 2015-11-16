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


struct node * findIntersection(struct node * head1,struct node * head2)
{
	struct node * t1 = head1;
	struct node * t2 = head2;
	struct node * aLast=NULL,*bLast = NULL;
	struct node * intersect = NULL;
	while(1){
//		cout<<t1->val<< " "<<t2->val<<endl;
		if(t1==t2)
		{
			intersect = t1 ;
			break;
		}
		if(t1->next==NULL){
			aLast= t1 ;

			if(bLast && aLast!=bLast)
				break;
		}
		if(t2->next==NULL){
			bLast= t2 ;
					
			if(aLast && aLast!=bLast)
				break;
		}
		t1 = t1 -> next ;
		t2 = t2 -> next ;
		if(!t2)
			t2 =  head1;
		if(!t1)
			t1 = head2;
	}
	return intersect;
}


int main()
{
	struct node * head = 	 new node(3);
	head -> next = new node(6);
	head -> next -> next = new node(9);
	head -> next -> next -> next= new node(15);
	head -> next -> next -> next-> next= new node(30);
	struct node * head2 = new node(10);
	head2 -> next =head->next->next->next;
	print(head);	
	print(head2);
	struct node * intersect = findIntersection(head,head2);
	intersect ? cout<<"Intersection is :"<<intersect->val<<endl : cout<<"No Intersection"<<endl;
}
