#include<iostream>
#include<stdlib.h>
using namespace std ;


struct ListNode {
  int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

 // Definition for singly-linked list.
   void del(ListNode * &t){
        ListNode * temp = t->next;
        if(temp){
            t->next = temp->next;
            free(temp);
        }
        else
            t->next = NULL;
            
    }
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode * t = head;
        if(!head)
            return NULL;
        while(t && t->next){
           	if(t->val==t->next->val)
           	{
           		del(t);
           	}
           	else
            	t = t->next;
        }
        return head;
    }
	ListNode *deletDuplicates(ListNode *head) {
        ListNode * last  = NULL;
        if(!head || !(head->next))
            return head;
        ListNode * tra = head ;
        while(tra && tra->next){
            if(tra->val == tra->next->val){
                int data = tra->val;
                while(tra && tra->val==data){
                    tra = tra->next;
                }
                
        }
        return head;
    }

void print(ListNode * head){
	while(head){
		cout<<head->val<<" " ;
		head = head->next;
	}
}
int main(){
	ListNode * head = new ListNode(1);
	head->next = new ListNode(1);
	
	head->next->next = new ListNode(2);
	head = deletDuplicates(head);
	print(head);

}
