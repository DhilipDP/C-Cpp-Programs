#include<iostream>
#include<stack>
using namespace std ;


int main()
{
	string str ;
	cin>> str ;
	stack<int> st ;
	string temp = "" ;
	int s ;
	for( s=0 ; s<str.length() && str[s]==')' ; s++)	temp += "0" ;
	string res  ;

	for(int  i=s ; i<str.length() ; i++){
		if(str[i]=='(')
			st.push(i) ,temp += "1";
		else if(str[i]==')'){
			if(st.empty())
				temp+="0";
			else
				st.pop() , temp += "1" ; 
		}
		else
			temp +="1" ;
	}
	while(!st.empty())
		{
			temp[st.top()] = '0'  ;
			
			st.pop();
		}
	for(int i=0 ; i<str.length() ; i++)
		if(temp[i]=='1')
			res += str[i] ;
	cout<<res;
}	
