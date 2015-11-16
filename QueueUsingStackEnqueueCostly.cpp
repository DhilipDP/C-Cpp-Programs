#include<iostream>
#include<stack>
using namespace std ;

//IMPLEMENTATION OF QUEUE USING STACK (ENQUEUE COSTLY)

stack<int> s1 ;
stack<int> s2 ;

void enqueue(int x){
	cout<<"Enqueueing "<<x<<endl;
	while(!s1.empty()){
		
		int p = s1.top();
		s2.push(p);
		s1.pop();
	}
	s1.push(x);
	while(!s2.empty()){
		int p = s2.top();
		s1.push(p);
		s2.pop();
	}
}

int dequeue(){
	if(s1.empty())
		return -1 ;
	int d = s1.top();
	cout<<"Dequeuing "<<endl ;	
	s1.pop();
	return d;
}



int main(){
	enqueue(3);	
	enqueue(4);
	enqueue(5);	
	cout<<dequeue()<<endl;
	enqueue(6);	
	cout<<dequeue()<<endl;
	cout<<dequeue()<<endl;
	enqueue(1);	
	cout<<dequeue()<<endl;
	cout<<dequeue()<<endl;	
}
