#include<iostream>
using namespace std ;

struct node{
	int val ;
	struct node * next ;
	node(int x) : val(x) , next(NULL) {}
};



void print(struct node * head){
	struct node * temp = head;
	while(temp)
	{
		cout<<temp->val<<" ";
		temp = temp -> next;
	}
	cout<<endl;
}


void fun(struct node * head)
{
		if(head == NULL)
			return ;
		cout<<head->val<<" ";
		if(head->next) 	fun(head->next->next);
		cout<<head->next->val<<" ";
		
}

void fun2()
{
	int mat[2][2] = {{1,2} , {3,4}};
	int i,j,temp ,n=2;
	
	for( i=0 ; i<n ; i++ ){
	
	for( j=0 ; j<n ; j++ ){
			temp = mat[i][j]+ 100;
			mat[i][j] = mat[j][i];
			mat[j][i] = temp - 100; 
			}	
}
		for(i=0;i<n ; i++){
			for(j=0;j<n;j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
}


int main()
{
	struct node * head = 	 new node(1);
	head -> next = new node(2);
	head -> next -> next = new node(0);
	head -> next -> next -> next= new node(4);
	head -> next -> next -> next-> next= new node(5);
//	head -> next -> next -> next-> next-> next= new node(3);
	fun2();
}
