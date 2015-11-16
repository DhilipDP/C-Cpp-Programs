#include<iostream>

#include<stack>

#include<queue>

using namespace std;
//IMPLEMENTATION OF STACK USING QUEUE PUSH COSTLY

queue<int> q1 ;
queue<int> q2;

void push(int i){
	q2.push(i);
	while(!q1.empty()){
		int n = q1.front();
		q2.push(n);
		q1.pop();
	}		
	queue<int> temp;
	temp = q1 ;
	q1 = q2 ;
	q2 = temp ;
	cout<<"Pushed: "<<i<<endl;
}

int pop(){
	if(q1.empty())
		return -1;
	int f = q1.front();
	cout<<"Popping: "<<endl;
	q1.pop();
	return f;
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
