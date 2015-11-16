#include<iostream>
#include<vector>
using namespace std ;


int lcs(string x,string y,int m,int n)
{
	if(m==0 || n==0)
		return 0;
	if(m!=n && x[m-1] == y[n-1])
		return lcs(x,y,m-1,n-1) + 1 ;
	return max(lcs(x,y,m-1,n) , lcs(x,y,m,n-1)) ;
}

// check is any subsequence of length > 1 repeats itself
int anyTwo(string A)
{
	string x=A ;
	string y = A ;
	int n = A.length() ;
	vector<vector<int> > dp(n+1,vector<int>(n+1,0)) ;
	for(int i=0 ; i<=n ; i++)
	{
		for(int j=0 ; j<=n ; j++)
		{
			if(i==0 || j==0)
				dp[i][j]  = 0;
			else if(i!=j && x[i-1] == y[j-1])
				dp[i][j] =  dp[i-1][j-1] + 1 ;
			else
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
		}
	}
	cout<<dp[n][n]<<endl;
	if(dp[n][n] <= 1)
		return 0;
	return 1;
}
int main()
{
	string x = "nadyna" ;
	string y = "nadyna" ;
	cout<<lcs(x,y,x.length() , y.length()) ;
	cout<<endl<<anyTwo("abba") ;
}
