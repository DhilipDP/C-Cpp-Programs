#include<iostream>
#include<stack>
using namespace std ;

//IMPLEMENTATION OF QUEUE USING STACK (DEQUEUE COSTLY)

stack<int> s1 ;
stack<int> s2 ;

void enqueue(int x){
	cout<<"Enqueueing "<<x<<endl;
	s1.push(x);
}

int dequeue(){
	if(s1.empty() && s2.empty())
		return -1 ;
	if(s2.empty())
	{
		while(!s1.empty()){
			int d = s1.top();
			s2.push(d);
			s1.pop();
		}
	}
	int d = s2.top();
	cout<<"Dequeuing "<<endl ;	
	s2.pop();
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
