
#include<stdlib.h>
#include<iostream>
using namespace std ;


struct node{
	int val ;
	struct node * next ;
	node(int x) : val(x) , next(NULL) {}
};


struct ListNode{
	int val ;
	ListNode * next ;
	ListNode(int x) : val(x) , next(NULL) {}
};

void print(ListNode * head){
	ListNode * temp = head;
	while(temp)
	{
		cout<<temp->val<<" ";
		temp = temp -> next;
	}
	cout<<endl;
}

struct node * delete_nodes(struct node * head , struct node * p)
{
	if(head==NULL)
		return head ;
	struct node * pre = NULL ,* tra = head ; 
	while(tra && tra != p)
	{
		pre = tra ;
		tra = tra -> next ;
	}
	if(tra==NULL){
		cout<<"not found"<<endl;
		return head ;
	}
	struct node * temp = tra ;	
	if(!pre)
		head = head->next ;
	else
		pre -> next = tra->next;
	free(temp);
	return head;
}


ListNode * delete_node(ListNode * pre,ListNode *p,ListNode * &head )
{
    ListNode * temp = p ;	
    ListNode * next = p->next ;
	if(!pre)
		head = head->next ;
	else
		pre -> next = p->next;
	free(temp);
	return next;
    
}

ListNode* deleteDuplicates(ListNode* A) {

    if(!A)
        return NULL ;
    ListNode * tra = A ,*pre = NULL;
    int c = 0;
    while(tra ){
    	cout<<tra->val<<endl;
        int cur = tra->val;
        if(tra->next && cur==tra->next->val){
            tra = delete_node(pre,tra,A);
            while(tra && tra->val==cur)
                tra = delete_node(pre,tra,A) ;
            
        }
        else{
            pre = tra ;
            tra = tra->next ;
        }
    	c++;
    	print(A) ;
    }
    return A;
}

int main()
{
	ListNode* head = 	 new ListNode(1);
	head -> next = new ListNode(1);
	head -> next -> next = new ListNode(1);
	head -> next -> next -> next= new ListNode(2);
	head -> next -> next -> next-> next= new ListNode(3);
	head -> next -> next -> next-> next-> next= new ListNode(3);
	head -> next -> next -> next-> next-> next -> next= new ListNode(4);
	print(head);
	head = deleteDuplicates(head) ;
	print(head);
}
