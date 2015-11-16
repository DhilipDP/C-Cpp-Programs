#include<iostream>
#include<map>

using namespace std ;


struct node
{
	int val ;
	node * next ;
	node * prev ;
	node(int x) : val(x) , next(NULL) , prev(NULL) {}
};

struct Queue{
	int count ;
	struct node * front ;
	struct node * rear ;
	Queue(int v) : count(v) , front(NULL) , rear(NULL) {}
}*queue;


map<int , node *> hash_map ;


void print()
{
	if(queue->front==NULL)
		return  ;
	struct node * temp = queue->front ;
	while(temp != queue->rear->next)
	{
		cout<<temp->val<<" ";
		temp = temp->next ;
	}
	cout<<endl;
}



void insert_at_head(int val)
{
	cout<<"inserting"<<endl;
	queue->count++;
	struct node * newnode =  new node(val) ;
	newnode->next = queue->front ;
	if(queue->front)
		queue->front->prev = newnode ;
	else
		queue->rear = newnode ;
	queue->front = newnode ;
	hash_map[val] = newnode ;
}

void remove_node(struct node * t)
{
	hash_map[t->val] = NULL ;
	queue->count--;
	cout<<"removing"<<endl;
	if(t->next)
		t->next->prev = t->prev ;
	else
		queue->rear = queue->rear->prev ;
	if(t->prev)
		t->prev->next = t->next ;
	else
		queue->front = queue->front->next ;
}


void referencePage(int val,int n)
{
	cout<<val<<endl;
	if(hash_map[val]==NULL){
		//cout<<"hi"<<endl;
		if(queue->count == n)
			remove_node(queue->rear);
		insert_at_head(val);
	}
	else
	{
		struct node * t = hash_map[val] ;
		remove_node(t) ;
		insert_at_head(t->val);
	}
}

int main()
{
	int n = 4 ;
	queue = new Queue(0) ;
	referencePage(1,n);
	print();
		referencePage(2,n);
	print();
		referencePage(3,n);
	print();
		referencePage(1,n);
	print();
		referencePage(4,n);
	print();
		referencePage(5,n);
	print();
}
