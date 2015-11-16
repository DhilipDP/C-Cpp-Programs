#include<iostream>

#include<stack>

#include<queue>

using namespace std;
//IMPLEMENTATION OF STACK USING QUEUE POP COSTLY

queue<int> q1 ;
queue<int> q2;

void push(int i){
	q1.push(i);
	cout<<"Pushing: "<<i<<endl;
}

int pop(){
	
	if(q1.empty())
		return -1;
	int s = q1.size();
	for(int i=0 ; i<s-1 ; i++){
		int n=q1.front();
		q2.push(n);
		q1.pop();
	}
	int p = q1.front();
	q1.pop();

	cout<<"Popping: "<<endl;
	queue<int> temp;
	temp = q1 ;
	q1 = q2 ;
	q2 = temp ;
	return p;
}

int main(){
	
	push(3);
	push(4);
	push(5);
	cout<<pop()<<endl;
	push(6);
	cout<<pop()<<endl;
		cout<<pop()<<endl;
	push(1);
			cout<<pop()<<endl;
			cout<<pop()<<endl;
			cout<<pop();
}
