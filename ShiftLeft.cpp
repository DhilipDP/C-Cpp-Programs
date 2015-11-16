#include <iostream>
using namespace std;
 
 
struct node{
	int val;
	struct node * next;
	node(int x): val(x) , next(NULL){}
};
 
struct node * last ;
 
 
void print(struct node * t){
	struct node * l = t;
	int index = 0;
	while(l)
		cout<<l->val<<" ",l = l->next;
	cout<<endl;
}
 
 
 
struct node *insert(struct node * head,int x){
	struct node * nw = new node(x);
	static struct node * tra ;
	if(head==NULL)
		head = tra = last = nw;
	else{
		tra -> next = nw;
		tra = nw;
		last = nw;
	}
	return head;
}
 
struct node * shiftLeft(struct node * head){
	struct node * temp = head ;
	head = head -> next ;
	last -> next = temp ;
	temp -> next = NULL;
	last = temp;
	return head ;
}
 
int findMiddle(struct node * head){
	struct node * slow=head,*fast=head;
	while(fast ){
		cout<<slow->val<<" "<<fast->val<<endl;
		if(fast->next==NULL)
			return slow->val;
		slow = slow->next;
		fast = fast->next->next;
	}
}
 
int main() {
	struct node * head = NULL;
	int arr[] = {34,17,17,74,83,59,39};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0 ; i<n ; i++)
		head = insert(head,arr[i]);
	print(head);
	long long int t = 4432897427834;
	t = t%7;
	while(t--)
	{head = shiftLeft(head);
	print(head);
	}
	cout<<endl;
	print(head);
//	cout<<findMiddle(head);
	// your code goes here
	return 0;
}
