#include<iostream>
using namespace std ;


struct node{
	int val;
	struct node * next ;
	node(int x) : val(x),next(NULL){}
};



struct node * append(struct node * head,int val){
	cout<<"Adding: "<<val<<endl;
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

struct node * mergeWithoutDuplicates(struct node * n1,struct node * n2){
	if(n1==NULL && n2==NULL)
		return NULL;
	struct node * result = NULL;
	while(n1 != NULL && n2 != NULL){
		
		if(n1->val < n2->val ){
		
			int data = n1->val;
			int count = 0;
			while(n1 && n1->val==data)
				count++,n1 = n1->next;
			if(count==1)
				result = append(result,data);
		}
		
		else if(n2->val < n1->val){
			int data = n2->val;
			int count = 0;
			while(n2 && n2->val==data)
				count++,n2 = n2->next;
			if(count==1)
				result = append(result,data);
		}	
		else{
			int data = n1->val ;
			while(n1 && n1->val==data)
				n1 = n1->next;
			while(n2 && n2->val==data)
				n2 = n2->next;
		}
	}
	while(n1 != NULL){
			int data = n1->val;
			int count = 0;
			while(n1 && n1->val==data)
				count++,n1 = n1->next;
			if(count==1)
				result = append(result,data);
	}
	
	while(n2 != NULL){
			int data = n2->val;
			int count = 0;
			while(n2 && n2->val==data)
				count++,n2 = n2->next;
			if(count==1)
				result = append(result,data);
	}
	return result ;
}



void print(struct node * list){
	
	while(list)
		cout<<list->val<<" ",list=list->next;
	cout<<endl;
}

int main(){
	struct node * list1 = new node(1) ;
	list1 -> next = new node(1);
	list1 -> next -> next = new node(1);
	list1 -> next -> next -> next = new node(3);
	list1 -> next -> next -> next -> next = new node(3);
	list1 -> next -> next -> next -> next -> next= new node(5);
	print(list1);
	struct node * list2 = new node(1);
	list2 -> next = new node(2);
	list2 -> next -> next = new node(2);
	list2 -> next -> next -> next = new node(8);
//	list2 -> next -> next -> next -> next = new node(6);
//	list2 -> next -> next -> next -> next -> next= new node(6);

	print(list2);
	
		struct node * res = mergeWithoutDuplicates(list1,list2);
	print(res);
		
}
