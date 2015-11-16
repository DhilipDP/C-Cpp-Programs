#include<iostream>
#define SIZE 500
using namespace std;

char mystack[SIZE];
int top = -1;


//define priorities 
//Note : infix priority of '(' is the greatest
int infixPriority(char x){
	switch(x){
		case '+' : 
		case '-' : return 1;
		case '*' : 
		case '/' : 
		case '^' : return 2;
		case '(' : return 3;
		case '#' :
		case ')' : return 0;
	}

}

int stackPriority(char x){
	switch(x){
		case '+' : 
		case '-' : return 1;
		case '*' : 
		case '/' : 
		case '^' : return 2;
		case '(' :
		case '#' : return 0;
	}

}

void push(char x)
{
	if(top < SIZE){
	top++;
	mystack[top]=x;
	}
}

char pop(){
	if(top>=0){
		char x = mystack[top];
		top--;
		return x;
	}
}

int main()
{
	
		char expr[SIZE];
		string output="";
		cout<<"Enter infix expression: :\n";
		cin>>expr;
		push('#');
	   // cout<<pop();
		//cout<<top;
		for(int i=0 ; expr[i]!='\0'; i++){
			if(isalpha(expr[i]) || isdigit(expr[i])){			
				output+=expr[i];
			}
			else if(expr[i] == ')'){
				char p;
				while(( p = pop())!= '('){
					output += p;
				}
			}
			else{
				char pch = pop();
				char ch = expr[i];
			//	cout<<pch<<" "<<ch;
				if(stackPriority(pch) >= infixPriority(ch) ){
					output += pch;
					push(ch);
				}
				else{
					push(pch);
					push(ch);
				}
			}
			if(expr[i+1]=='\0'){
			
			char p;
			while(( p=pop()) != '#')
				output += p;
			}
		}
		cout<<"\nPostfix Expression: \n";
		cout<<output<<endl;
	
}
