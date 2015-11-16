#include<iostream>

using namespace std ;



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
 
 void insert(ListNode *&head , int val){
	
//	cout<<"\nInserting: ";
	ListNode * newnode = new ListNode (val);
	if(!head){
//		cout<<val<<" at head"<<endl;
		head = newnode ;
		return ;
	}
	ListNode * p = head ;
	while(p->next)
		p = p->next ;
//	cout<<val<<endl;
	p->next = newnode ;
}



void traverse(ListNode * head){

	ListNode * p = head ;
	while(p){
		cout<<p->val<<" ";
		p= p->next;
	}
		
}


ListNode * reverse(ListNode * head,int n,ListNode * t){
	
	ListNode * current = head;
	ListNode * temp ;
	ListNode * pre = t;
	int i=0;
	while(current && i<n){
		temp = current->next ;
		current -> next = pre ;
		pre= current ;
		current = temp;
		i++;
	}
	return pre ;
}
ListNode *reverseBetween(ListNode *head, int m, int n) {
	
        if(head==NULL)
        	return NULL;
        int i = 1;
        ListNode * current = head;
        while(current && i < m-1){
        	current = current -> next;
        	i++;
        }
        ListNode * temp = current ;
        i = 0;
		while(temp && i <= n)
		{
			temp = temp -> next ;
			i++;
		}
        current -> next = reverse(current->next,n,temp);
        return head;
}
int main(){
		ListNode * head = NULL;
	for(int i=1 ; i<=5 ; i++)
		insert(head,i);
	traverse(head);
	head = reverseBetween(head,1,2);
	cout<<endl;
	traverse(head);
}
