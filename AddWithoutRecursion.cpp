#include<iostream>
using namespace std ;


struct node{
	int val;
	struct node * next ;
	node(int x) : val(x),next(NULL){}
};


int getLength(struct node *t)
{
	int c=0;
	struct node * tra = t ;
	while(tra)
		c++,tra = tra->next;
	return c;
}

struct node * append(struct node * head,int val){
//cout<<"Adding: "<<val<<endl;
	struct node * newnode = new node(val);
	static struct node * rider = NULL;
	if(head==NULL){
		head = newnode ;
		rider = head;
	}
	else{
		rider -> next = newnode ;
		rider = newnode ;
	}
	return head ;
}


void print(struct node * list){
	
	while(list)
		cout<<list->val<<" ",list=list->next;
	cout<<endl;
}


struct  node * add(struct node * l1,struct node * l2,int &c)
{
	struct node * res = NULL;
	if(l1==NULL && l2==NULL)
		return NULL;
	int n1 = getLength(l1);
	int n2 = getLength(l2);
	struct node *t1=l1,*t2=l2;
	bool first=false,second=false;
	struct * tfirst = NULL,*tsecond = NULL;
	if(n1 < n2){
		second = true;
		int move = n2-n1;
		while(move--){
			tsecond = append(tsecond,t1->val);
			t2 = t2->next;
		}
		tsecond->next = NULL;
	}
	else if(n2 < n1){
	     first = true;
			int move = n1-n2;
		while(move--){
			tfirst = append(tfirst,t1->val);
			t1= t1->next;
		}
		tfirst -> next = NULL;
	}
	struct node * temp = add(t1->next,t2->next,c);
	
	int sum = 0;
	sum += (t1->val + t2->val + c);
	res = append(res,sum%10);
	res -> next =temp;
	c = sum/10;
	if(first){
		if(carrry){
		
		}
		else
		
	}
	return res;
	
}


int  main(){
	struct node * list1 = new node(1) ;
	list1 -> next = new node(9);
//	list1 -> next -> next = new node(9);
	struct node * list2 = new node(9);
	list2 -> next = new node(0);
//	list2 -> next -> next = new node(1);	
	int carry = 0;
	struct node * sum = add(list1,list2,carry);
	if(carry){
		struct node * n = new node(carry);
		n->next = sum;
		sum = n;}
	print(sum);
}
