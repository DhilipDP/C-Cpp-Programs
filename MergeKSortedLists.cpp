#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std ;


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

bool comp(ListNode * a,ListNode * b)
{
	return a->val > b->val;
}


ListNode * insert(ListNode * head,int val)
{
	static ListNode * last = NULL ;
	ListNode * newnode = new ListNode(val);
	if(!head)
	{
		head = newnode ;
		last = head ;
		return head ;
	}
	last -> next = newnode ;
	last = newnode ;
	return head;
}

ListNode * mergeKlists(vector<ListNode *> &lists)
{
	
	vector<ListNode *> arr ;
	int n = lists.size() ;
	if(n==0)
		return NULL ;
	ListNode * sorted = NULL ;
	for(int i=0 ; i<n ; i++)
		arr.push_back(lists[i]) ;
	make_heap(arr.begin(),ab2rr.end(),comp);
	while(!arr.empty())
	{
		pop_heap(arr.begin(),arr.end(),comp) ;
		sorted = insert(sorted,arr[n-1]->val);
		ListNode * temp = arr[n-1];
		arr.erase(arr.end()-1) ;
		if(temp->next)
			arr.push_back(temp->next);
		else
			n--;
		make_heap(arr.begin(),arr.end(),comp);
	}
	return sorted ;
}


int main()
{      
	LstNode *  list1 = new ListNode(1);
	list1 -> next = new ListNode(3) ;
	list1 -> next -> next = new ListNode(6);
	
	ListNode *  list2 = new ListNode(2);
	list2 -> next = new ListNode(4) ;
	list2 -> next -> next = new ListNode(5);
	
	ListNode *  list3 = new ListNode(4);
	list3 -> next = new ListNode(9) ;
	
	print(list1);
	print(list2);
	print(list3);
	vector<ListNode *> v ;
	v.push_back(list1);
	v.push_back(list2);
	v.push_back(list3);
	
	ListNode * sorted = mergeKlists(v) ;
	print(sorted);
	
}
