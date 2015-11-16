

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


bool detectLoop(struct node * head,struct node *&loop_node)
{
	if(!head)
		return NULL ;
	struct node * slow = head ;
	struct node * fast = head ;
	while(fast)
	{
		slow = slow -> next ;
		fast = fast -> next ;
		
		if(fast)
			fast = fast -> next ;
		if(slow==fast){
			loop_node = slow ;
			return true ;
		}
			
	
	}
	return false  ;
	
}


struct node * removeLoop(struct node * head,struct node * loopnode)
{
	int c = 1;
	struct node * tra = loopnode->next ;
	while(tra != loopnode)
	{
		c++ ;
		tra = tra->next ;
	}
	tra = head ;
	int m = 0;
	while( m < c)
		tra = tra -> next ,m++;
	struct node * ptr = head ;
	
	while(ptr != tra)
	{
		ptr = ptr -> next ;
		tra = tra -> next ;
	}
	while(tra ->next != ptr)
		tra = tra -> next ;
	tra -> next = NULL ;
	return head;
}

int main()
{
	struct node * head = 	 new node(5);
	head -> next = new node(3);
//	head -> next -> next= head ;
	head -> next -> next = new node(6);
	head -> next -> next -> next= new node(2);
	head -> next -> next -> next-> next= new node(1);
	
	head -> next -> next -> next-> next-> next= head->next; 
	struct node * loop_node = NULL ;
	if(detectLoop(head,loop_node))
	{
		cout<<"Loop Exists"<<endl; 
		head = removeLoop(head,loop_node);
		cout<<"Removed"<<endl;
	}
	else{
		cout<<"NO LOOP "<<endl;
	}
	print(head) ;
}
