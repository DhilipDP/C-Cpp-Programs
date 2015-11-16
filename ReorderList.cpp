#include<iostream>
#include<deque>
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


/*void reorderList(ListNode * head){
	if(head==NULL)
		return ;
	if(head->next==NULL)
		return ;
	ListNode * start = head,*end ;
	while(start){
		end = start ;
		ListNode * temp = start->next,*pre_end = start ;
		while(end->next)
		{
			pre_end = end ;
			end = end->next ;
		}
		if(start==end)
			break;
		start -> next = end;
		if(start==pre_end){
			break;
		}
		pre_end->next = NULL;
		end->next  = temp;
		start = temp;
	}	
}
*/
void reorderList(ListNode * head ){
	if(head==NULL)
		return ;
	deque<ListNode *> dq ;
	ListNode * tra = head ;
	while(tra){
		dq.push_back(tra);
		tra = tra->next;
	}
	int flag = 0;
	ListNode * t = dq.front();
	dq.pop_front();
	while(!dq.empty()){
		if(flag==0){
			flag = 1;
			t->next = dq.back();
			dq.pop_back();
		}
		else{
			flag = 0;
			t->next = dq.front();
			dq.pop_front();
		}
		t = t->next;
	}
	t->next = NULL;
}

int main(){
	ListNode * head = NULL;
	for(int i=1 ; i<=6 ; i++)
		insert(head,i);
	traverse(head);
	reorderList(head);
	cout<<endl;
	traverse(head);
}
