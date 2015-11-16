#include<iostream>

using namespace std ;

struct RandomListNode {
      int label;
      RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
  
  
  void print(RandomListNode * head){
  	RandomListNode * t = head,*t1=head;
  	while(t){
  		cout<<t->label<<" ";
		if(t->random)
			cout<<t->random->label<<" "<<t<<endl;
  		t =t->next;
	}
  
  }
  
  RandomListNode * insert_after(RandomListNode * t){
  	  RandomListNode * p = t->next;
  	  RandomListNode * newnode = new RandomListNode(t->label);
  	  newnode->next = t->next;
  	  newnode->random=t->random;
  	  t->next = newnode;
  	  return t;
  }
   RandomListNode *copyRandomList(RandomListNode *&head) {
        RandomListNode * copy;
        RandomListNode * t = head;
        while(t){
        	t = insert_after(t);
        	if(t->next)
        		t = t->next->next;
        	else
        		t = NULL;
		
		}
//		print(head);
		RandomListNode * t1 = head;
		while(t1 && t1->next){
			//cout<<t1->label<<" "<<t1->next->label<<endl;
			if(t1->random)
				t1->next->random = t1->random->next;
			else
				t1->next->random = NULL;
			//cout<<t1->next->label<<"'s random : "<<t1->random->next->label<<endl; 
			t1=t1->next->next;
			
		}
		RandomListNode * t2 = head;
		RandomListNode *chead = head->next;
		copy=head->next;
		//cout<<"hi";
		while(copy && copy->next ){
		//	cout<<t2->next->label<<" 's next : "<<t2->next->next->label<<endl;
			t2->next = t2->next->next;
			copy->next = copy->next->next;
			t2=t2->next,copy=copy->next;
		
		}
		t2->next = NULL;
		
		return chead;
		
    }
  int main(){
  
  	RandomListNode * head = new RandomListNode(1);
  	head -> next = new RandomListNode(2);
    head -> next -> next = new RandomListNode(3);
	head -> next ->next ->next= new RandomListNode(4);
	head -> next ->next ->next -> next= new RandomListNode(5);
//	head -> next ->next -> next -> next->next= new RandomListNode(5);
	head->random = head->next->next;
	head->next->random = head;
	head->next->next->random = head->next->next->next->next;
	head->next->next->next->random = head->next->next;
	head->next->next->next->next->random = head->next;
	print(head);  	
	cout<<endl<<"Original"<<endl;
  	RandomListNode * copy = copyRandomList(head);
  	//cout<<"come";
	  print(head);
  	
  	cout<<endl<<"Copy"<<endl;
  	print(copy);
  }
