
#include<iostream>
using namespace std ;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


void print(ListNode*head){
	while(head)
		cout<<head->val<<" ",head = head->next;
	cout<<endl;
}

ListNode * getEnd (ListNode * head){

	int c = 0;
	while(head->next)
		c++,head = head->next;
	return head;
}

ListNode * partition(ListNode * head,ListNode * end){

	ListNode * tra = head;
	ListNode * pivot = head;
	int piv=  head->val;
	while(tra != end->next){
		if(tra->val < piv){
			pivot = pivot -> next;
			int temp = pivot->val;
			pivot -> val = tra->val;
			tra->val = temp;
		}
		tra = tra->next;
	}
	int temp = pivot->val;
	pivot->val = head->val;
	head->val = temp;
	return pivot;
	
}


ListNode * sort(ListNode * head,ListNode * end){
	if(head == NULL || head->next==NULL)
		return head;
//	cout<<"Sorting"<<head->val<<" "<<end->val<<endl;
//			cout<<"After partitioning :"<<head->val<<endl;
	ListNode * q = partition(head,end);

//	print(head);
	if(head -> val != q->val){
	
		ListNode *pre=head;
		ListNode * t = head;
		while(t!=q){
			t = t->next;
		}
		head = sort(head,t);
	//	print(head);
	}
	ListNode * t = q;
	while(t->next)
		t = t->next ;
	q->next = sort(q->next,t);
	return head;
	
}


ListNode *sortList(ListNode *head) {
	return sort(head,getEnd(head)); 
}
int main(){
	ListNode * head  = new ListNode(4);
	 head  ->  next = new ListNode(4);
	 head  -> next -> next = new ListNode(1);
	 head  -> next -> next -> next = new ListNode(3);
	 head  -> next -> next -> next -> next= new ListNode(2);
	head = sortList(head);
	print(head);
}
  
 

