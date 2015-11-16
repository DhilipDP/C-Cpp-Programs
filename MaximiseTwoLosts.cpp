

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

struct node * maximise(struct node * h1,struct node * h2)
{
	struct node * result = NULL, *cur1=h1,*cur2=h2 ;
	struct node * pre1 = NULL,*pre2 = NULL ; 
	while(cur1 || cur2)
	{
	
		int sum1 = 0,sum2 = 0;
		while(cur1 && cur2 && cur1->val != cur2->val)
		{
			if(cur1 -> val < cur2->val)
			{
				sum1 += cur1->val;
				cur1 = cur1->next ;
			}
			else{
				sum2 += cur2->val;
				cur2 = cur2 -> next;
			}
		}
	
		if(cur1==NULL)
		{
			while(cur2){
				sum2 += cur2->val;
				cur2 = cur2 -> next;
			}
		}
		if(cur2 ==NULL)
		{
		
			while(cur1)
			{
				sum1 += cur1->val;
				cur1 = cur1->next;
			}
		}
		if(pre1==NULL && pre2==NULL)
			result = sum1 > sum2  ? h1 : h2 ;
		else{
			if(sum1 > sum2 )
	pre2->next = pre1->next ;
			else
			pre1 -> next = pre2 -> next;
		}
		pre1 = cur1;
		pre2 = cur2 ;
		if(cur1)
			cur1 = cur1->next ;
		if(cur2)
			cur2 = cur2-> next;
	
	
	}
	return result;
}


int main()
{
	struct node * head = 	 new node(1);
	head -> next = new node(3);
	head -> next -> next = new node(5);
	head -> next -> next -> next= new node(6);
	head -> next -> next -> next-> next= new node(7);
	head -> next -> next -> next-> next-> next= new node(8);
	print(head);	
	struct node * head1 = 	 new node(2);
	head1 -> next = new node(4);
	head1 -> next -> next = new node(5);
	head1 -> next -> next -> next= new node(8);
	head1 -> next -> next -> next-> next= new node(9);
	head1 -> next -> next -> next-> next-> next= new node(10);
	print(head1);	
	head = maximise(head,head1);
	print(head);
}
