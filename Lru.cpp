#include<iostream>
#include<map>
#include<stdlib.h>
using namespace std ;

  struct node
{
    int key ;
	int val ;
	node * next ;
	node * prev ;
	node(int x,int y) : val(x) , key(y), next(NULL) , prev(NULL) {}
};

struct Queue{
	int count ;
	struct node * front ;
	struct node * rear ;
	Queue(int v) : count(v) , front(NULL) , rear(NULL) {}
}*q;


map<int , node *> hash_map ;

void insert_at_head(int key,int val)
{
	cout<<"inserting "<<key<<" "<<val<<endl;
	q->count++;
	struct node * newnode =  new node(val,key) ;
	newnode->next = q->front ;
	if(q->front)
		q->front->prev = newnode ;
	else
		q->rear = newnode ;
	q->front = newnode ;
	hash_map[key] = newnode ;
}

void remove_node(struct node * t)
{
	hash_map[t->key] = NULL ;
	q->count--;
	cout<<"removing "<<t->key<<endl;
	if(t->next)
		t->next->prev = t->prev ;
	else
		q->rear = q->rear->prev ;
	if(t->prev)
		t->prev->next = t->next ;
	else
		q->front = q->front->next ;
	cout<<"done";
}


    int  n ;
    void LRUCache(int capacity) {
        n = capacity ;
        free(q);
        q = new Queue(0);
    }
    
    int get(int key) {
        if(hash_map[key]!=NULL){
        
            int ret =  hash_map[key]->val ;
            remove_node(hash_map[key]) ;
        	insert_at_head(key,ret);
        	return ret;
        }
        return -1;
    }
    
    void set(int key, int value) {
      
        if(hash_map[key] == NULL){
        		
            	if(q->count == n)
			        remove_node(q->rear);
	        	insert_at_head(key,value);
        }
        else
        {
        struct node * t = hash_map[key] ;
		remove_node(t) ;

		insert_at_head(key,value);
	
        }
        
    }
    
    
    int main()
    {
    	LRUCache(1) ;
    //	cout<<"j";
    	set(2,1) ;
    //	set(1,1);
    //	print();
    
    	cout<<get(2) ;
    //	set(4,1) ;
    //	cout<<get(1) ;
	//	set(3,2) ;
    //	print();
    //	cout<<get(2);
    //	cout<<get(3);
    }
