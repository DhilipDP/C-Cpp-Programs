#include<iostream>
#include<vector>
#include<math.h>
using namespace std ;


struct node {
	int val ;
	struct node * pre ;
	struct node * next ;
	node(int x) : val(x) , pre(NULL) , next(NULL) {
	}
};

struct node * tra ;

struct node * insert(struct node * head , int v)
{
	struct node * newnode = new node(v) ;
	if(head == NULL)
	{
		head = newnode ;
		tra = head ;
	}
	else{
		tra->next = newnode ;
		newnode->pre = tra ;
		tra = newnode ;
	}
	return head;
}


void print(struct node * head)
{
		struct node * temp = head ;
		while(temp)
			{
				cout<<temp->val<<" ";
				temp = temp -> next ;
			}
		cout<<endl ;
	
}
int main()
{
	int t ;
	cin>>t ;
	while(t--)
	{
		int n,k ;
		cin>>n >> k;
		
		struct node * head = NULL ;
		
		for(int i=0 ; i<n ; i++)
		{
			int val ; cin>>val ;
		//	v.push_back(val) ;
			head = insert(head,val) ;
		}
	//	print(head);
		while(k--)
		{
			struct node * i = head ,*j = tra;
			int  f=0;
			while( i &&j && (i != j ) ){
				int temp = i->val ;
				i->val =  j->val ;
				j->val = temp ;//,v[j]) ;
				f++ ;
				if(f % 2==1)
					i = i->next;
				else
					j = j->pre;
				//cout<<"kk";
	//			print(head);
			}
			struct node * h = head  , *t = tra ;
			while(h && t)
			{
				if( h==t || h->pre == t)
				{
					if(h -> pre)
					h -> pre -> next = h->next ;
					if(h -> next)
					h -> next -> pre = h -> pre ;
					break;
				}
				h = h->next , t = t->pre;
					
			}
		//	print(head);
		}
		print(head);
	}
}
