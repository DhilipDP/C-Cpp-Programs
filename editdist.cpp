#include<iostream>
using namespace std ;



int editDistance(string x,string y,int m,int n)
{
	if(m==0 && n==0)
		return 0;
	if(m==0)
		return n ;
		
	if(n==0)
		return m ;
	int add = editDistance(x,y,m-1,n) ;
	int rem = editDistance(x,y,m,n-1) ; 
	int rep = editDistance(x,y,m-1,n-1) + (x[m-1]!=y[n-1]) ;
	return min(min(add,rem),rep);
}
int main()
{
	string x = "Nandu" ;
	string y = "Nijin" ;
	cout<<editDistance(x,y,x.length(),y.length());
}
