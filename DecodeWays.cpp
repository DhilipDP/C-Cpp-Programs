#include<iostream>

using namespace std ;



int decodeWays(string s,int n)
{
	if(n==0 || n==1)
		return 1;
	int count = 0;
	//if the last digit is non zero, it will add
	if(s[n-1] > '0')
		count = decodeWays(s,n-1) ;
	if(s[n-2] =='1' || s[n-2]=='2' && s[n-1] <= '6')
		count += decodeWays(s,n-2) ;
	return count;
}

int decode(string s)
{
	int n = s.length() ;
	int dp[n+1] ;
	if(n==0)	
		return 0;
	dp[0] = dp[1] = 1 ;
	for(int i=2 ; i<=n ; i++)
	{
		dp[i] = 0;
		if(s[i-1] > '0')
			dp[i] = dp[i-1] ;
		if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))
			dp[i] += dp[i-2] ;
		
	}
	return dp[n] ;
}
int main()
{
	string s = "1111111111" ;
	cout<<decodeWays(s,s.length())<<" "<<decode(s) ;
}
