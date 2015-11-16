#include<iostream>
#include<stdlib.h>
using namespace std;


struct node{
	int val;
	struct node * next;
	node(int x) : val(x) , next(NULL){} ;
};


void print(struct node * head){
	struct node * t = head;
	while(t)
		cout<<t->val<<" ",t=t->next;
	cout<<endl;
}

struct node * partition(struct node* head,int x){
	struct node *tmp1=NULL,*curr=head;
	

	struct node * p=NULL;
	struct node *d1;
	struct node *d2;
	int i=0,j=0,num;
	while(curr!=NULL)
	{
		struct node * nw = new node(curr->val);
		if(curr->val<x)
		{		
			if(i==0){
				d1 = new node(curr->val);
			tmp1 = d1;
			i++;
			
			}
			else
		 	{ 
		 	tmp1->next=nw;
		 	tmp1=nw;
		 
			}
		}
		else if(curr->val>x){
			if(j==0){
					d2 = new node(curr->val);
			p=d2;
			j++;
			}
			else
		 	{
		 		p->next=nw;
		 		p=nw;
			}
		}
		curr = curr->next;
	}
  struct node* temp1 = new node(x);
  tmp1 -> next = temp1;
  temp1-> next = d2;
    return d1;
 }
     
     
    struct node * Partition(struct node * head,int x){
    	if(head==NULL)
    		return NULL;
    	struct node * l_head=NULL,*l_tra , *r_head=NULL, *r_tra,*cur = head;
    	while(cur){
    		if(cur->val < x){
    			if(l_head==NULL)
    				l_head = cur,l_tra = cur;
    			else
    				l_tra->next = cur,  l_tra = cur;
			}
			if(cur->val >= x){
    			if(r_head==NULL)
    				r_head = cur,r_tra = cur;
    			else
    				r_tra->next = cur,  r_tra = cur;
			}
    		cur = cur -> next ;
		}
		if(r_head)
			r_tra->next = NULL;
		if(!l_head)
			return r_head;
		l_tra->next = r_head;
		return l_head;
	}
int main(){
	struct node * head = new node(4);
	head -> next = new node(1);
	head -> next -> next = new node(2);
	head -> next -> next-> next = new node(5);
	head -> next -> next -> next -> next= new node(3);
	head -> next -> next-> next-> next->next = new node(7); 
	 head -> next -> next-> next-> next->next -> next= new node(8); 
print(head);
head=Partition(head,3);
print(head);
}
