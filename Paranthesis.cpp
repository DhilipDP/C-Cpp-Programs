#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;


vector<string> res ;




void _printParenthesis(int pos, int n, int open, int close)
{
	cout<<pos<<" "<<open<<" "<<close<<endl;
  static char str[100];     
 
  if(close == n) 
  {
   // printf("%s \n", str);
    cout<<str<<endl ; 
	return;
  }
  else
  {
    if(open > close) {
        str[pos] = '}';
        _printParenthesis(pos+1, n, open, close+1);
    }
    if(open < n) {
       str[pos] = '{';
       _printParenthesis(pos+1, n, open+1, close);
    }
  }
}
void solve(int index,int n,int op, int cl,string &s)
{
	cout<<s<<endl;
	if(cl == n)
	{
		cout<<s<<endl;
	    res.push_back(s) ;
	    return  ;
	}
	if(op > cl)
	    {
	        s[index] = ')' ;
	        solve(index+1,n,op,cl+1,s);
	    }
	   if(op < n){
	       s[index] = '(';
	       solve(index+1,n,op+1,cl,s);
	   }

}
void solve(int n)
{
	if(n <=0)
		return ;
	if(n==1){
		res.push_back("()") ;
		return ;
	}
	solve(n-1) ;
	
	vector<string> temp = res; 
	res.clear() ;
	for(int i=0 ; i<temp.size() ; i++)
	{
		string t = temp[i] ;
		res.push_back("(" + t + ")") ;
		res.push_back(t + "()");
		if(t[0] == t[1]) 
			
			res.push_back("()" + t) ;
	}
}

int main()
{
	string s ;
	s[0] = 1;
	solve(0,1,0,0,s);
//	_printParenthesis(0,1,0,0) ;
	int n = 4;
//	solve(n) ;
	sort(res.begin() , res.end()) ;
	cout<<res.size()<<endl;
	for(int i=0 ; i<res.size() ; i++)
	{
		cout<<res[i]<<endl;
	}
}
