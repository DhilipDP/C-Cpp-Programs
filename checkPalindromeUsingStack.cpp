#include<iostream>
#define MAX_SIZE 1000
using namespace std ;

char stack[MAX_SIZE];
int top = 0;

void push(char c){
	if(top==MAX_SIZE){
		cout<<"Stack full"<<endl;
		return  ;
	}
	stack[top++]=c;
}

void pop(char *c){
	if(top==0){
		cout<<"Stack empty"<<endl;
		return ;
	}
	top--;
	*c = stack[top];
}


bool checkPalindrome(char str[]){
	int len = strlen(str),i; 
	//push all values into stack
	for(i=0 ; i<len ; i++)
		push(str[i]);
	//one by one pop and check
	for(i=0 ; i<len/2 ; i++){
		// the main idea is here . Since we are not allowed to return values from pop()
		// we pass the address of a char variable to pop() function ,, and the popped value is stored in c 
		// it is reflected in this function also!(CALL BY REFERENCE)
		char c;
		pop(&c);
		//comparing values from 1st and last (upto middile) if any characters mismatch immediately stop ! and return false
		if(c!=str[i])  
			return false;
	}
	// now we have checked for all strings and none has mismatched(if it had, function would ve returned in for loop itself)
	return true ;
}
int main(){

	
	char str[MAX_SIZE];
	
	cout<<"Enter a string: "<<endl;
	cin>>str;
	if(checkPalindrome(str)) // if function returns true
		cout<<"\nPalindrome!"<<endl;
	else
		cout<<"\nNot a palindrome!"<<endl;

}
