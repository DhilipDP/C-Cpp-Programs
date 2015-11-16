#include<iostream>
using namespace std ;


 // Definition for singly-linked list.
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
	ListNode * insert(ListNode * l,int val){
		if(l==NULL)
		{
			l = new ListNode(val);
			return l;
		}
		ListNode * t = l;
		while(t->next)
			t=t->next;
		t->next = new ListNode(val);
		return l;
	}
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) { 
        if(l1==NULL && l2==NULL)
        	return NULL;
        if(l1==NULL)
        	return l2;
        if(l2==NULL)
        	return l1;
        ListNode * l3 = NULL;
        while(l1 && l2){
        	
        	if(l1->val < l2->val){
        		l3 = insert(l3,l1->val);   
				l1 = l1->next ;  		
			}
        	else{
        		l3 = insert(l3,l2->val);
        		
        		l2 = l2->next ;
        	}
        		
		}
		while(l1)
			{
				l3 = insert(l3,l1->val);
				l1 = l1->next;
			}
			while(l2){
				l3 = insert(l3,l2->val);
				l2 = l2->next;
		}	
		return l3;
    }

		void print(ListNode * t){
		ListNode * p = t;
		while(p){
			cout<<p->val<<" ";
			p = p->next ;
		}
	
	}
int main(){
	ListNode * l1 = new ListNode(1);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(5);
	ListNode * l2 = new ListNode(2);
	l2->next = new ListNode(6);
	print(l1);
	print(l2);
	
	l1 = mergeTwoLists(l1,l2);
	print(l1);
}
