#include<iostream>
#include<map>
using namespace std ;

string dict[] = {"i","icecream","like"};
map<string,int> m;


bool word_break(string s)
{
	int n = s.length() ;
	if(n==0)
		return true ;
	for(int i=0 ; i<n ; i++)
	{
		if(m[s.substr(0,i+1)] && word_break(s.substr(i+1,n-i-1)))
			return true ;
	}	
	return false;
}


bool wordBreak(string s)
{
	int n=s.length();
	if(n==0)
		return false ;
	int dp[n];
	memset(dp,0,sizeof(dp));
	for(int i=0 ; i<n ; i++)	
	{
		if(dp[i]==false && m[s.substr(0,i+1)])
			dp[i]= true ;
		if(dp[i]==true)
		{
			if(i==n-1)
				return true ;
			for(int j=i+1 ; j<n ; j++){
				if(dp[j]==false && m[s.substr(i+1,j-i)])
					dp[j]=true;
				if(dp[j] && j==n)
					return true; 
			}
		}
	}
	return false;
}

int main()
{
	string s = "iicecream" ;
	for(int i=0 ; i<3 ; i++)
	m[dict[i]] = 1;
	cout<<word_break(s)<< " " << wordBreak(s);
}
