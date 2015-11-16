#include<iostream>

using namespace std;

//multiplication of two numbers implemented as a linked list


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


int count(struct node * t){
	int i=0;
	while(t){
		i++;
		t=t->next;
	}
	return i;
}


struct node * product(struct node * t,int val){
	int carry = 0 ;
	struct node * p = NULL ;
	while(t){
		int n = (val * t->data) + carry ;
		insert(p,(n)%10);
		carry = n/10;
		t= t -> next ;
	}	
	if(carry!=0)
		insert(p,carry);
	return p;
}

void insert_at_front(struct node *&t,int val){
	struct node * newnode = new node ;
	newnode -> data = val ;
	newnode ->next = t ;
	t = newnode ;
}

struct node * multiply(struct node * head1,struct node * head2){
	int len1 = count(head1);
	int len2 = count(head2);
	struct node * num1, *num2 ;
	if(len1 < len2 )
	{
		num1 = reverse(head2,NULL);
		num2 = reverse(head1,NULL) ;
	}
	else{
		num1 = reverse(head1,NULL);
		num2 = reverse(head2,NULL) ;
	}
	struct node * partPrd = NULL ;
	struct node * prd = NULL ;
	int i = 0;
	while(num2){
		partPrd = product(num1,num2->data);	
		int j=i;
		while(j--){
			insert_at_front(partPrd,0);
		}
		prd = reverse( add(prd,reverse(partPrd,NULL)),NULL);
		i++;
		num2 = num2 -> next ;
	}
	return prd ;
}

int main(){
	//1234
	struct node * head1 = NULL ;
	insert(head1,1);
	insert(head1,2);
	insert(head1,3);
	insert(head1,4); 
	//5678
	print(head1);
	struct node * head2 = NULL ;
	insert(head2,5);
	insert(head2,6);
	insert(head2,7);
	insert(head2,8); 
	print(head2);
	struct node * prd = NULL;
	prd = multiply(head1,head2);
	cout<<"------"<<endl ;
	print(prd);
}
