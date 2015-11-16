#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
using namespace std ;

int eval(vector<string> exp)
{
	string temp ;
	bool set = false;
	stack<int> ans ;
	for(int i=0 ; i<exp.size() ; i++)
	{
		temp += exp[i];
		if(exp[i] == "+" || exp[i] == "-")
		{
			set = true;
			int  b = ans.top();
			ans.pop() ;
			int  a = ans.top() ;
			ans.pop() ;
			if(exp[i]=="+")
				ans.push(a+b) ;
			else
				ans.push(a-b) ;
		}
		else
			ans.push(atoi(exp[i].c_str())) ;
	}
	if(!set)
		return atoi(temp.c_str()) ;
	return ans.top() ;
}

vector<string> transForm(string s)
{
	vector<string> output ;
	stack<char> infix ;
	for(int i=0 ; i<s.length() ; i++)
	{
		//cout<<s[i]<<" : ";
		if(s[i]==' ')
			continue ;
		else if(s[i] == '(' )
			infix.push(s[i]) ;
		else if( s[i]=='+' || s[i]=='-'){
				if(!infix.empty() && infix.top() != '(')
					{
							string t ;
							t += infix.top();
	
						output.push_back(t) ;
				    	infix.pop();
					}
				infix.push(s[i]);
			}
		
		else if(s[i]==')'){
			while((!infix.empty()  && infix.top() != '('))
			{
					string t ;
					t += infix.top();
	
				output.push_back(t);
				infix.pop() ;
			}
			if(!infix.empty())
			infix.pop() ;
		}
		else{
			string temp ="" ;
			while( i<s.length() && isdigit(s[i]))
				temp += s[i++];
			output.push_back(temp);//s[i];
			i--;
		}
	}	
	while(!infix.empty())
	{
		string t ;
		t += infix.top();
		output.push_back(t);
		infix.pop();
	}
	return output ;
}

int calculate(string s)
{
	vector<string> postFix = transForm(s) ;
//	for(int i=0 ; i<postFix.size() ; i++)
//	 cout<<postFix[i]<<" ";
	return eval(postFix) ;	
}

int main()
{
	string s = "(1+(4+5+2)-3)+(6+8)" ;
	cout<<calculate(s) ;  
}
