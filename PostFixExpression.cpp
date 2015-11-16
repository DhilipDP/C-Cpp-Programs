#include<vector>
#include<stdio.h>
#include<stack>
#include<iostream>
#include<stdlib.h>

using namespace std ;


int evalRPN(vector<string> tokens){
	stack<int> s;
	vector<string> :: iterator it;
	for(it=tokens.begin() ; it!=tokens.end() ; it++)
	{
		string temp = *it;
		int val = atoi((*it).c_str());
		if(temp=="0" || val!=0){
			s.push(val);
		}
		else{
			int b=s.top();
			s.pop();
			int a = s.top();
			s.pop();
			cout<<a<<" "<<b;
			if(*it=="+")
				s.push(a+b);
			else if(*it=="-")
				 s.push(a-b);
			else if(*it=="*")
				s.push(a*b);
			else if(*it=="/")
				s.push(a/b);
		}
			
	}

	return s.top();
}
int main(){
	vector<string> v ;
//	"4", "13", "5", "/", "+"
	v.push_back("0");
	v.push_back("3");
//	v.push_back("5");
	v.push_back("/");
//	v.push_back("+");
	
	cout<<evalRPN(v);
}
