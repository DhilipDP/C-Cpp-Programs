#include<iostream>
using namespace std ;


struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  
  
  void print(ListNode * t){
 	while(t){
 		cout<<t->val<<" ";
 		t = t->next;
	 }
  }
  
  ListNode *reverseBetween(ListNode *head, int m, int n){
  		int i=0;
  		ListNode * t = head;
  		if(!head)
  			return NULL;
  		ListNode * pre = NULL,*r;
  		while(t){
  				i++;
  				if(i==m){
  					int j=i;
  					ListNode * temp ,*q=pre;
  					ListNode * cur = t,*p=pre;
  					while(cur && j<=n){
  						j++;
  						temp = cur->next ;
  						cur->next = p;
  						if(p==pre )
  							r=cur;	
  						p = cur;
  						cur = temp;
					}
					if(q)
						q->next = p;
					else
						head = p;
					r->next = cur;
					break;
				}
				
				else{
  				pre = t;
  				t = t->next;
  				}
		}
	
		return head;
  }
int main(){
ListNode * head = new ListNode(1);
head->next = new ListNode(2);
head->next ->next= new ListNode(3);
head->next ->next->next= new ListNode(4);
head->next ->next->next->next= new ListNode(5);
head->next ->next->next->next->next= new ListNode(6);
print(head);

head = reverseBetween(head,2,5);
print(head);

}
