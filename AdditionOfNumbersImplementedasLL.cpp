#include<iostream>

using namespace std;

//Addition of two numbers implemented as a linked list


struct node{
	int data ;
	struct node * next ;
};

void insert(struct node * &head , int val){
	//cout<<"\ninserting"<<val<<endl;
	struct node * newnode = new node ;
	newnode->data = val ;
	newnode->next = NULL ;
	if(head==NULL){
		head = newnode ;
		return ;
	}	
	struct node * tra = head ;
	while(tra->next)
		tra = tra->next ;
	tra->next = newnode ;
}


struct node * reverse(struct node * t,struct node * pre){
	if(t==NULL)
		return pre;
	struct node * temp = t->next ;
	t->next = pre ;
	pre = 	t;
	return reverse(temp,pre);
}


void print(struct node * t){
	while(t)
	{
		cout<<t->data<<" ";
		t=t->next ;
	}		
	cout<<endl;
}

struct node * add(struct node * head1,struct node * head2){
	struct node * num1 = reverse(head1,NULL);
	struct node * num2 = reverse(head2,NULL);
	struct node * sum = NULL ;
	int carry = 0;
	while(num1!=NULL || num2!=NULL){
		int a,b,s;
		a = num1 ? num1->data : 0 ;
		b = num2 ? num2->data : 0 ;
		s = (a+b+carry)%10 ;
		carry = (a+b+carry)/10;
		//cout<<a<<" "<<b<<" "<<s<<" "<<carry<<endl;
		insert(sum,s);
		if(num1)
			num1 = num1->next ;
		if(num2)
			num2 = num2->next;
	}
	if(carry!=0)
		insert(sum,carry);
//	print(sum);
	return sum ;
}

int main(){
	//1234
	struct node * head1 = NULL ;
	insert(head1,1);
	insert(head1,2);
	insert(head1,3);
	insert(head1,4); 
	//5678
/*	insert(head1,6);
	insert(head1,1);
	insert(head1,7);
	insert(head1,0);
	insert(head1,0);
	insert(head1,0);
	insert(head1,0);*/
	print(head1);
	struct node * head2 = NULL ;
	insert(head2,4);
	insert(head2,3);
	/*insert(head2,7);
	insert(head2,8); 
	insert(head2,8);
	insert(head2,3);
	insert(head2,6);
	insert(head2,6);
	insert(head2,5);
	insert(head2,2); */
	print(head2);
	struct node * sum = NULL;
	sum = reverse(add(head1,head2),NULL);
	cout<<"------"<<endl ;
	print(sum);
}
