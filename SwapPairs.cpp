
#include<iostream>
using namespace std;


 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 //*/

    ListNode *swapPairs(ListNode *head) {
        if(!head || head->next==NULL)
        	return head;
        ListNode * current = head;
        ListNode * new_head = current->next,*t=current->next->next;
        ListNode * temp = current->next;
        temp->next=current;
        current->next = swapPairs(t);
        return new_head;
    }
    
    int count(ListNode * head){
    	ListNode * t = head;
    	int c=0;
    	while(t){
    //		cout<<"hi";
    		c++;
			t=t->next;
		}
		return c;
	}
	ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL)
        	return head;
       int n = count(head);
       if(k>n)
       	return head;
       ListNode * pre = NULL,*cur = head,*t = head,*temp;
       int i=0;
       while(cur && i<k) {
       	temp = cur->next ;
       	cur->next = pre;
       	pre = cur;
       	cur = temp;
       	i++;
	   }
	   t->next = reverseKGroup(cur,k);
	   return pre;
	   
    }

void print(ListNode * head){
	ListNode * t = head;
	while(t){
		cout<<t->val<<" " ;
		t = t->next;
	}
	cout<<endl;
}
int main(){
	ListNode * head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
//	head->next->next->next->next ->next= new ListNode(6);
	print(head);
	head = reverseKGroup(head,2);
	print(head);
	
}
